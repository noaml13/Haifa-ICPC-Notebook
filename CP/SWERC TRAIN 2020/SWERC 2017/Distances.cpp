#include <bits/stdc++.h>
#define int int64_t
#define ii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e14, MOD = 1e9+7;

vvi solve(){
    int n,m; cin>>n>>m;
    vvi g(n);
    loop(i,0,n){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b), g[b].pb(a);
    }
    vvi dist(n, vi(2,MOD));
    queue<ii> q; q.push({0,0});
    while(q.size()){
        int cur = q.front().x, b =q.front().y; q.pop();
        for(int nei:g[cur]) if(dist[nei][b^1]==MOD){
            dist[nei][b^1] = dist[cur][b] + 1;
            q.push({nei, b^1});
        }
    }
    return dist;
}
void add(int &a, int b){ a = (a+b)%MOD;}
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) % MOD;
}
int inv(int x){ return pp(x,MOD-2);}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>k;
    vector<vvi> dist(k);
    vvi cnt(k, vi(2));
    loop(i,0,k) dist[i] = solve(), cnt[i][0] = cnt[i][1] = dist[i].size();
    int ans = 0;
    vi mult(2);
    loop(i,0,k) mult[0] = mult[0] * cnt[i][0] % MOD;
    mult[1] = mult[0];
    vvb fst(k);
    loop(i,0,k) fst[i] = vb(cnt[i][0], 1);
    set<pair<int, pair<int, ii>>> s;
    loop(i,0,k) loop(j,0,cnt[i][0]) loop(b,0,2) {
        s.insert({dist[i][j][b], {i, {j,b}}});
    }
    while(s.size()){
        auto tmp = *s.rbegin(); s.erase(tmp);
        int i = tmp.y.x, j = tmp.y.y.x, b = tmp.y.y.y, d = tmp.x;
        mult[b] = mult[b] * inv(cnt[i][b]) % MOD;
        if (fst[i][j]){
            fst[i][j] = 0;
            add(ans, mult[b] * d % MOD);
        }
        cnt[i][b]--;
        mult[b] = mult[b] * cnt[i][b] % MOD;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ Distances.cpp -o a & a
2

2 1
1 2

4 4
1 2
2 3
3 4
4 1

*/