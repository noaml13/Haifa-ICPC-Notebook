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
const int INF = 1e18, MOD = 1e9 + 7;


int n,m,L,s,t;
vvii g;
vi w;
vii edge;
priority_queue<ii, vector<ii>, less<ii>> q;
vi dist;
int dijkstra(){
    fill(all(dist), INF);
    dist[s] = 0; q.push({0,s});
    while(q.size()){
        int cur = q.top().y, d = q.top().x; q.pop();
        if (dist[cur]!=d) continue;
        for(auto nei:g[cur]){
            if (dist[nei.x]>d + w[nei.y]){
                dist[nei.x] = d + w[nei.y];
                q.push({dist[nei.x], nei.x});
            }
        }
    }
    int d = dist[t];
    if (d==L){
        cout<<"YES"<<endl;
        loop(i,0,m){
            cout<<edge[i].x<<" "<<edge[i].y<<" "<<w[i]<<endl;
        }
        exit(0);
    }
    return d;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>L>>s>>t;
    g.resize(n); dist.resize(n);
    w.resize(m); edge.resize(m);
    vi ind;
    loop(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        g[a].pb({b,i});
        g[b].pb({a,i});
        w[i] = c;
        edge[i] = {a,b};
        if (!c) ind.pb(i);
    }
    int l = 1, r = INF, mid, ans = 0;
    while(l<r){
        mid = (l+r)/2;
        for(int i:ind) w[i] = mid;
        int d = dijkstra();
        if (d>L) r = mid;
        else l = mid + 1, ans = mid;
    }
    if (!ans) return cout<<"NO"<<endl,0;
    for(int i:ind) w[i] = ans;
    int k = ind.size();
    l = 0, r = k+1;
    while(l<r){
        mid = (l+r)/2;
        loop(i,0,k) w[ind[i]] = ans+(i<mid?1:0);
        int d = dijkstra();
        if (d>L) r = mid;
        else l = mid + 1;
    }
    cout<<"NO"<<endl;
    return 0;
}
/*
color a
cls
g++ CompleteTheGraph.cpp -o a & a
4 4 2 1 3
1 3 13
2 3 0
2 0 0
1 0 0


[l,r)
val(mid)>x: [l, mid)
val(mid)<x: [mid+1,r)

*/

