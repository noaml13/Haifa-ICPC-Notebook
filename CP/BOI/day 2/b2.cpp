#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e9;

int n;
vvii g;
vii edge;
vi depth;
vb is;
vi ans;
int res = 0;

void dfs(int cur, int d=0, int p=-1){
    depth[cur] = d;
    for(auto nei:g[cur]) if(nei.x!=p){
        dfs(nei.x, d+1, cur);
    }
}
int calc(int cur, int p=-1){
    int sz = 1;
    for(auto nei:g[cur]) if(nei.x!=p){
        int v = calc(nei.x, cur);
        res+=2*min(n-v, v);
        sz += v;
    }
    return sz;
}
bool cmp(int a, int b){
    return depth[a]>depth[b];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    g.resize(n); depth.resize(n); is.resize(n-1,1);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb({b,i}); g[b].pb({a,i});
        edge.pb({a,b});
    }
    ans.resize(n);
    calc(0);
    cout<<res<<endl;
    /*loop(i,0,n) cout<<ans[i]+1<<" ";
    cout<<endl;*/
    return 0;
}
/*
color a
cls
g++ b2.cpp -o a & a
7
4 2
5 7
3 4
6 3
1 3
4 5


*/