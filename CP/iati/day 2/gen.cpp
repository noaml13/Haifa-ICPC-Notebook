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
const int INF = 1e9+ 10, MOD = 1e9 + 7;


struct BINARY{
    int n, LOGN=1;
    vvi g;
    vi depth;
    vvi anc;
    BINARY(vvi& _g, int s=0):g(_g), n(_g.size()){
        for(int i=1;i<=n;i<<=1,++LOGN);
        depth.resize(n,0);
        anc.resize(n,vi(LOGN,-1));
        dfs(s);
    }
    void dfs(int cur, int p=-1,int d=0){
        anc[cur][0] = p;
        for(int i=1;anc[cur][i-1]!=-1;i++){
            anc[cur][i] = anc[anc[cur][i-1] ][i-1];
        }
        depth[cur] = d;
        for(auto nei:g[cur]){
            if (nei==p) continue;
            dfs(nei, cur, d+1);
        }
    }
    int lift(int a, int d){
        loop(i,0,LOG){
            if (d & (1<<i)){
                a = anc[a][i];
            }
        }
        return a;
    }
    int lca(int a,int b){
        if(depth[a]<depth[b]) swap(a,b);
        a = lift(a, depth[a]-depth[b]);
        if (a==b) return a;
        for(int i=LOGN-1;i>=0;--i){
            if (anc[a][i]!=anc[b][i]){
                a=anc[a][i];
                b=anc[b][i];
            }
        }
        return anc[a][0];
    }
};


vvi g;
int n; 


void solve(){
    cin >> n;
    g.resize(n);
    for(int i=0; i<n-1; i++){
        int u,v; cin >> u >> v; u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    BINARY bin(g);
    vi& d = bin.depth;
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int a,b,c; cin >> a >> b>> c;
        a--; b--;
        int l = bin.lca(a, b);
        if(d[b] + d[a] - d[l] <= c){
            cout << b+1 << endl;
        }
        else if(d[a] - d[l] > c){
            bin.lift(a, c);
            cout << a+1 << endl;
        }
        else{
            c = c - (d[a] - d[l]);
            bin.lift(b, d[b] - d[l] - c);
            cout << b+1 << endl;
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}
/*
g++ gen.cpp -o a

*/