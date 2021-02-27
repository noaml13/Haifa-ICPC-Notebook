#include <bits/stdc++.h>
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
    int n,m; cin>>n>>m;
    vvii g(n);
    loop(i,0,m){
        int a,b,c; cin>>a>>b>>c; a--, b--; 
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    vvi ts(n), vals(n);
    loop(i,0,n){
        int k; cin>>k;
        if (!k) continue;
        ts[i].resize(k), vals[i].resize(k);
        loop(j,0,k) cin>>ts[i][j];
        vals[i][k-1] = ts[i][k-1] + 1;
        loopr(j,0,k-1){
            if (ts[i][j]+1==ts[i][j+1]) vals[i][j] = vals[i][j+1];
            else vals[i][j] = ts[i][j] + 1;
        }
    }
    priority_queue<ii> q; q.push({0,0});
    vi dist(n, INF); dist[0] = 0;
    while(q.size()){ 
        int cur = q.top().y, d = -q.top().x; q.pop();
        if (dist[cur]!=d) continue;
        int i = lower_bound(all(ts[cur]), d) - ts[cur].begin();
        if (i<ts[cur].size() && ts[cur][i]==d) d = vals[cur][i];
        for(auto nei:g[cur]){
            if (dist[nei.x]>nei.y+d){
                dist[nei.x] = nei.y+d;
                q.push({-dist[nei.x], nei.x});
            }
        }
    }
    int ans = dist[n-1];
    if (ans == INF) ans = -1;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ planets.cpp -o a & a
4 6
1 2 2
1 3 3
1 4 8
2 3 4
2 4 5
3 4 3
0
1 3
2 3 4
0


*/
