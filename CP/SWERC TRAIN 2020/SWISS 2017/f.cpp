#include <bits/stdc++.h>
#define int int64_t
#define ii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vii vector<ii>
#define vvii vector<vii>
#define vvvii vector<vvii>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9 + 7;

struct Deal{
    int id;
    int s,e,c,h;
};
int n,h, m;
vector<Deal> deals;
vector<vector<Deal>> sd;
typedef pair<ii, ii> iiii;
typedef vector<iiii> viiii;
typedef vector<viiii> vviiii;
typedef vector<vviiii> vvviiii;
pair<int, vi> solveA(int x){
    vvviiii dp(n+1, vviiii(x+1, viiii(h+1, {{INF,-1}, {-1,-1}})));
    dp[0][0][0] = {{0,-1},{-1,-1}};
    loop(i,0,n){
        loop(j,0,x+1){
            loop(k,0,h+1){
                for(auto d:sd[i]){
                    if (d.h == k) continue;
                    iiii v = {{dp[i][j][k].x.x+d.c, j}, {d.id, k}};
                    chkmin(dp[d.e][min(j + d.e-d.s, x)][d.h], v);
                }
                iiii v = {{dp[i][j][k].x.x, j}, {-1, k}};
                chkmin(dp[i+1][j][0], v);
            }
        }
    }
    int i = n, j = x, k = 0;
    loop(kk,1,h+1) if(dp[i][j][kk]<dp[i][j][k]) k = kk;
    int res = dp[i][j][k].x.x;
    if (res > INF/2) return {INF, vi(0)};
    vi vec;
    while(i){
        auto p = dp[i][j][k];
        k = p.y.y;
        if (p.y.x == -1) {
            i--;
            continue;
        }
        int id = p.y.x;
        vec.pb(id);
        int s = deals[id].s, e = deals[id].e;
        i = s, j = p.x.y;
    }
    reverse(all(vec));
    return {res, vec};
}
pair<int, vi> solveB(int x){
    vvviiii dp(n+1, vviiii(x+1, viiii(h+1, {{INF,-1}, {-1,-1}})));
    dp[0][0][0] = {{0,-1},{-1,-1}};
    loop(i,0,n){
        loop(j,0,x+1){
            loop(k,0,h+1){
                for(auto d:sd[i]){
                    if (d.h == k) continue;
                    iiii v = {{dp[i][j][k].x.x+d.c, j}, {d.id, k}};
                    chkmin(dp[d.e][min(j + 1, x)][d.h], v);
                }
                iiii v = {{dp[i][j][k].x.x, j}, {-1, k}};
                chkmin(dp[i+1][j][0], v);
            }
        }
    }
    int i = n, j = x, k = 0;
    loop(kk,1,h+1) if(dp[i][j][kk]<dp[i][j][k]) k = kk;
    int res = dp[i][j][k].x.x;
    if (res > INF/2) return {INF, vi(0)};
    vi vec;
    while(i){
        auto p = dp[i][j][k];
        k = p.y.y;
        if (p.y.x == -1) {
            i--;
            continue;
        }
        int id = p.y.x;
        vec.pb(id);
        int s = deals[id].s, e = deals[id].e;
        i = s, j = p.x.y;
    }
    reverse(all(vec));
    return {res, vec};
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int x,y; cin>>n>>x>>y;
    cin>>h>>m;
    sd.resize(n);
    deals.resize(m);
    loop(i,0,m){
        int hh,s,e,c; cin>>hh>>s>>e>>c;
        s--, e--;
        sd[s].pb({i,s,e,c,hh});
        deals[i] = {i,s,e,c,hh};
    }
    auto r1 = solveA(x);
    auto r2 = solveB(y);
    if (min(r1.x, r2.x)>INF/2) return cout<<"IMPOSSIBLE"<<endl,0;
    vi v;
    if (r1.x > r2.x){
        cout<<"STAYS"<<endl;
        v = r2.y;
    }
    else{
        cout<<"NIGHTS"<<endl;
        v = r1.y;
    }
    cout<<v.size()<<endl;
    for(int x:v) cout<<x+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
5 3 2
2 5
1 1 2 5
1 2 3 4
1 1 3 20
1 3 5 15
2 3 4 10




*/