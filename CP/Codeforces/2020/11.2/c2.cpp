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
const int INF = 4e18, MOD = 998244353;
 
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) %MOD;
}
int n,m;
vvi g,ag;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    g.resize(n), ag.resize(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        ag[b].pb(a);
    }
    int LOG = 30;
    vvi dist(LOG, vi(n, INF));
    vvii totdist(n, vii(2,{-1,-1}));
    dist[0][0] = 0;
    priority_queue<pair<int,ii>> q; q.push({0,{0,0}});
    auto change = [&](int cur, int k, int d){
        bool ok = 0;
        if (k>=LOG){
            int b = k%2;
            if (totdist[cur][b].x>d){
                totdist[cur][b] = {d,k};
                ok = 1;
            }
        }
        else if (dist[k][cur]>d){
            dist[k][cur] = d;
            ok = 1;
        }
        if (ok){
            q.push({-d,{k, cur}});
        }
    };
    while(q.size()){
        auto tmp = q.top(); q.pop();
        int d = -tmp.x, k = tmp.y.x, cur = tmp.y.y;
        if (d!=dist[k][cur] && ii(d,k)!=totdist[cur]) continue;
        if (k%2){
            for(int nei:ag[cur]) change(nei, k, d+1);
        }
        else{
            for(int nei:g[cur]) change(nei, k, d+1);
        }
        change(cur, k+1, d);
    }
    int ans = INF;
    loop(i,0,LOG) if(dist[i][n-1]<INF) {
        chkmin(ans, dist[i][n-1]+(1<<(i))-1);
    }
    if (ans==INF) {
        ans = (totdist[n-1][0].x + pp(2,totdist[n-1][0].y))%MOD;
        chkmin(ans, (totdist[n-1][1].x + pp(2,totdist[n-1][1].y))%MOD);
    }
    ans = ans%MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c2.cpp -o a & a
4 3
2 1
2 3
4 3
 
 
*/