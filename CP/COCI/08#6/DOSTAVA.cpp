#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
#define v(x) vector<v(x-1)>
using namespace std;
const int INF = 2e9;
int N;
void dijkstra(vvii& g, int st, vi& dist, vb& check){
    dist[st]=0;
    loop(i,0,N) check[i]=0;
    priority_queue<ii, vii, greater<ii>> s;
    s.push({0,st});
    while(s.size()){
        int cur = s.top().y; s.pop();
        if (check[cur]) continue;
        check[cur]=1;
        for(auto nei:g[cur]){
            if (dist[cur]+nei.y<dist[nei.x]){
                dist[nei.x]=dist[cur]+nei.y;
                s.push({dist[nei.x], nei.x});
            }
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    N=2*n;
    vvii g(N);
    vvi a(n, vi(m));
    loop(i,0,n) loop(j,0,m) cin>>a[i][j];
    vvi pref(n, vi(m+1,0)), suf(n,vi(m+1,0));
    loop(i,0,n){
        loop(j,0,m) pref[i][j+1]=pref[i][j]+a[i][j];
        loopr(j,0,m) suf[i][j]=suf[i][j+1]+a[i][j];
    }
    loop(i,0,n){
        g[2*i].pb({2*i+1, pref[i][m] - a[i][0]});
        g[2*i+1].pb({2*i, suf[i][0] - a[i][m-1]});
    }
    loop(i,0,n-1){
        g[2*i].pb({2*(i+1), a[i+1][0]});
        g[2*(i+1)].pb({2*i, a[i][0]});
    }
    loop(i,0,n-1){
        g[2*i+1].pb({2*(i+1)+1, a[i+1][m-1]});
        g[2*(i+1)+1].pb({2*i+1, a[i][m-1]});
    }
    vb check(N);
    vvi dist(N, vi(N,INF));
    loop(i,0,N) dijkstra(g, i, dist[i], check);
    int q; cin>>q;
    int64_t ans=a[0][0];
    ii c = {0,0};
    loop(i,0,q){
        ii b; cin>>b.x>>b.y;
        b.x--; b.y--;
        int d0 = INF;
        if (c.x==b.x) {
            if (b.y>c.y) d0 = pref[b.x][b.y+1] - pref[c.x][c.y+1];
            else d0 = pref[c.x][c.y] - pref[b.x][b.y];
        }
        int d1 = pref[c.x][c.y] + pref[b.x][b.y+1] + dist[c.x*2][b.x*2] - a[b.x][0];
        int d2 = pref[c.x][c.y] + suf[b.x][b.y] + dist[c.x*2][b.x*2+1] - a[b.x][m-1];
        int d3 = suf[c.x][c.y+1] + pref[b.x][b.y+1] + dist[c.x*2+1][b.x*2] - a[b.x][0];
        int d4 = suf[c.x][c.y+1] + suf[b.x][b.y] + dist[c.x*2+1][b.x*2+1] - a[b.x][m-1];
        int cur=min({d0,d1,d2,d3,d4});
        //cout<<cur<<endl;
        ans+=cur;
        c = b;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ DOSTAVA.cpp -o a & a
3 3
1 8 2
2 3 2
1 0 1
3
1 3
3 3
2 2

*/


 




