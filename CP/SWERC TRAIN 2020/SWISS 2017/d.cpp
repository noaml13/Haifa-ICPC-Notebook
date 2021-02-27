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
const int INF = 4e18, MOD = 1e9 + 7;

vi dist(int s, vvi& g){
    queue<int> q;
    q.push(s);
    vi dist(g.size(), -1); dist[s] = 0;
    while(q.size()){
        int cur = q.front(); q.pop();
        for(int nei:g[cur]){
            if (dist[nei]==-1){
                dist[nei] = dist[cur] +1;
                q.push(nei);
            }
        }
    }
    return dist;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,k; cin>>n>>m>>k;
    vvi g(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int maxd = 0;
    loop(i,0,n){
        vi v = dist(i, g);
        for(int x:v) chkmax(maxd, x);
    }
    if (maxd<=n-k) {
        cout<<n<<endl;
        loop(i,0,n) cout<<i+1<<" ";
        cout<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
7 9 3
1 3
1 4
1 5
2 5
3 4
6 3
6 1
4 6
1 7



*/