#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define int int64_t
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<pair<int, ii>>>
#define viiii vector<pair<ii, ii>>
#define vvi vector<vi>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define FOR(i,l,r) for(int i=l; i<r; ++i)
#define ROF(i,r,l) for(int i=r; i>=l; --i)
#define all(x) x.begin(), x.end()
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max((int)a,(int)b)
#define test int t; cin >> t; while(t--) solve();
 
using namespace std;
typedef long long ll;
 
const int MAXN =75;
const int MAXINT = 1e9;
const int MAXLL = 1e18;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
/*
look at the constraints
 
? n==1..2
 
test/solve
 
*/


int dp[MAXN][MAXN][MAXN];


vvii g;
int n,m,k;
vi dijkstra(int s){
    vi dist(n, MAXLL); dist[s] = 0;
    priority_queue<ii> q; q.push({0,s});
    while(q.size()){
        int cur = q.top().y, d = -q.top().x; q.pop();
        if (d!=dist[cur]) continue;
        //cout<<"CUR: "<<cur<<" "<<d<<endl;
        for(auto nei:g[cur]){
            if (dist[nei.x]>d + nei.y){
                dist[nei.x] = d + nei.y;
                q.push({-dist[nei.x], nei.x});
            }
        }
    }
    return dist;
}
 
void solve(){
    cin>>n>>m>>k;
    g.resize(n);
    vii edge(m);
    FOR(i,0,m){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        g[a].pb({b,c});
        g[b].pb({a,c});
        edge[i] = {a,b};
    }
    vii pp(k);
    FOR(i,0,k) cin>>pp[i].x>>pp[i].y, pp[i].x--, pp[i].y--;
    vvi dist(n);
    FOR(i,0,n) dist[i] = dijkstra(i);
    //FOR(i,0,n) {FOR(j,0,n) cout<<dist[i][j]<<" "; cout<<endl;}
    int ans = MAXLL;
    FOR(i,0,m){
        int tot = 0;
        int u = edge[i].x, v = edge[i].y;
        FOR(j,0,k){
            int a = pp[j].x, b = pp[j].y;
            int d = dist[a][b];
            chkmin(d, dist[a][u]+dist[v][b]);
            chkmin(d, dist[a][v]+dist[u][b]);
            tot+=d;
        }
        chkmin(ans, tot);
    }
    cout<<ans<<endl;
} 
/*
color a
cls
g++ a.cpp -o a & a
6 5 2
1 2 5
2 3 7
2 4 4
4 5 2
4 6 8
1 6
5 3






*/
int32_t main(){
    fast;
    //test;
    //int t; cin>>t;
    //while(t--) solve();
    solve();
    return 0;
}