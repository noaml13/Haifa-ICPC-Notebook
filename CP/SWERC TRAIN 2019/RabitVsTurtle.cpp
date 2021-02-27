#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define iiii pair<ii,ii>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<vector<ii>> g(n),anti_g(n);
    vector<iiii> edge(m);
    for(auto& e : edge){
        cin>>e.x.x>>e.x.y>>e.y.x>>e.y.y;
        --e.x.x, --e.x.y;
        g[e.x.y].pb({e.x.x,e.y.y});
        anti_g[e.x.x].pb({e.x.y,e.y.y});
    }
    int n_t; cin>>n_t;
    vii pt(n_t);
    loop(i,0,n_t){
        cin>>pt[i].x>>pt[i].y, pt[i].x--;
    }
    vi t_suf(n_t+1);
    t_suf[n_t] = 0;
    for(int i=n_t-1;i>=0;i--) t_suf[i] = t_suf[i+1] + edge[pt[i].x ].y.x;
    int n_r; cin>>n_r;
    vi pr(n_r);
    loop(i,0,n_r) {
        cin>>pr[i], pr[i]--;
        ii uv=edge[pr[i] ].x;
        for(auto nei: anti_g[uv.x ]){
            if (nei.x!=uv.y) g[nei.x].pb({i + n, nei.y});
        }
    }
    vi r_suf(n_r+1);
    r_suf[n_r] = 0;
    for(int i=n_r-1;i>=0;i--) r_suf[i] = r_suf[i+1] + edge[pr[i] ].y.y;


    int nn = n+n_r;
    vi dist(nn, INF);
    dist[n-1] = 0;
    set<ii> s;
    loop(i,0,nn) s.insert({dist[i],i});
    while(s.size()){
        ii tmp = *s.begin();
        int cur = tmp.y;
        int curd = tmp.x;
        if (curd==INF) break;
        s.erase(s.begin());
        if (cur>=n) continue;
        for(auto nei: g[cur]){
            if (dist[nei.x] > curd + nei.y){
                s.erase({dist[nei.x],nei.x});
                dist[nei.x] = curd + nei.y;
                s.insert({dist[nei.x],nei.x});
            }
        }
    }
    /*cerr<<endl;
    loop(i,0,nn) cout<<dist[i]<<endl;
    cout<<endl;*/
    int rest_left = 0, walk_left = 0;
    vi ans;
    for(int cur_r = 0, cur_t = 0;cur_r<n_r;cur_r++){
        if (dist[n+cur_r]<r_suf[cur_r]){ //אם רמאות כדאי
            if (dist[n+cur_r]==dist[edge[pr[cur_r] ].x.x ]) {//הרמאות רמאות הכי טובה
                if (dist[n+cur_r]<=t_suf[cur_t] + (walk_left>0? walk_left: rest_left)){ //רמאות מוביל לניצחון
                    ans.pb(edge[pr[cur_r]].x.x);
                }
            }
        }
        bool first = true;
        int rt = edge[pr[cur_r] ].y.y;
        while((first||cur_t<n_t) &&  rt>0){
            int twalk, trest;
            if (first){
                twalk = walk_left;
                trest = rest_left;
                walk_left = rest_left = 0;
                first = false;
            }
            else{
                twalk = edge[pt[cur_t].x ].y.x;
                trest = pt[cur_t].y;
                cur_t ++;
            }
            if (rt >= twalk + trest){
                rt -= twalk + trest;
            }
            else if (rt>= twalk){
                rt -= twalk;
                rest_left = trest - rt;
                rt =0;
            }
            else{
                walk_left = twalk - rt;
                rest_left = trest;
                rt = 0;
            }
        }
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    for(auto a: ans) cout<<(a +1)<<" ";
    cout<<endl;
    return 0;
}



