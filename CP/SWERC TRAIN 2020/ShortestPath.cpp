#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD = 1e9 + 7;



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,k; cin>>n>>m>>k;
    vvi g(n);
    loop(i,0,m){
        int a,b; 
        cin>>a>>b; 
        a--, b--; 
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<pair<ii, int>> forb(k);
    loop(i,0,k) {
        cin>>forb[i].x.x>>forb[i].x.y>>forb[i].y;
        forb[i].x.x--,forb[i].x.y--,forb[i].y--;
    }
    sort(all(forb));
    queue<ii> q; q.push({0,0});
    vvi from(n, vi(n,-1)); 
    ii last = {-1,-1};
    while(q.size()){
        ii cur = q.front(); q.pop();
        if (cur.y==n-1) {
            last = cur;
            break;
        }
        for(auto nei:g[cur.y]){
            auto tri = make_pair(cur, nei);
            int i = lower_bound(forb.begin(), forb.end(), tri) - forb.begin();
            //cout<<"CUR: "<<cur.x<<" "<<cur.y<<" "<<nei<<" "<<i<<endl;
            if (i<k && forb[i]==tri) continue;
            if (from[cur.y][nei]==-1){
                from[cur.y][nei] = cur.x;
                q.push({cur.y, nei});
            }
        }
    }
    if (last.x==-1) return cout<<-1<<endl,0;
    vi ans; ans.pb(last.y);
    while(last.x){
        ans.pb(last.x);
        last = {from[last.x][last.y], last.x};
    }
    cout<<ans.size()<<endl;
    ans.pb(0); reverse(all(ans));
    for(auto x:ans) cout<<x+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ ShortestPath.cpp -o a & a
4 4 2
1 2
2 3
3 4
1 3
1 2 3
1 3 4



*/

