#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7, MAXN=2e5+2;

struct SEG{
    int sz;
    vi a;
    void init(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz,0);
    }
    void update(int l, int r, int dx){
        for(l+=sz, r+=sz; l<=r;l/=2,r/=2){
            if (l%2) a[l++]+=dx;
            if (r%2==0) a[r--]+=dx;
            if (l>=r) break;
        }
    }
    int query(int i){
        int ans=0;
        for(i+=sz;i;i/=2) ans+=a[i];
        return ans;
    }
};
template<int V>
class HLD{
    int n,s;
    int parent[V], heavy[V], depth[V];
    int treePos[V], root[V];
    SEG seg;
    int dfs(const vvi& g, int cur, int p=-1, int d=0){
        depth[cur] = d; parent[cur] = p;
        int maxsz=0, sz=1; heavy[cur] = -1;
        for(auto nei:g[cur]) if (nei!=p){
            int sub = dfs(g, nei, cur, d+1);
            sz+=sub;
            if (sub>maxsz){
                heavy[cur] = nei;
                maxsz = sub;
            }
        }
        return sz;
    }
    template<class BinaryOperation>
    void doPath(int u, int v,BinaryOperation op){
        for(;root[u]!=root[v]; u = parent[root[u]]){
            if (depth[root[u]]<depth[root[v]]) swap(u,v);
            op(treePos[root[u]], treePos[u]);
        }
        if (depth[u]<depth[v]) swap(u,v);
        op(treePos[v], treePos[u]);
    }
    void modifyPath(int u, int v, int dx){
        doPath(u,v, [this, dx](int l, int r){
            seg.update(l,r,dx);
        });
    }
public:
    void init(const vvi& g, int _s=0){
        s = _s;
        n = g.size();
        dfs(g,s);
        int curp = 0;
        loop(i,0,n){
            if (parent[i]==-1 || heavy[parent[i]]!=i){
                for(int j=i;j!=-1;j=heavy[j]) treePos[j]=curp++, root[j]=i;
            }
        }
        seg.init(n);
    }
    int get(int ind){
        return seg.query(treePos[ind]);
    }
    void update(int u, int dx){
        modifyPath(0,u,dx);
    }
};  
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n,q; cin>>n>>q;
    vi val(n); loop(i,0,n) cin>>val[i];
    vvi g(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    HLD<MAXN> hld;
    hld.init(g);
    loop(i,0,n) hld.update(i,val[i]);
    loop(i,0,q){
        int op, v; cin>>op>>v; v--;
        if (op==1){
            int x; cin>>x;
            hld.update(v, x-val[v]);
            val[v] = x;
        }
        else cout<<hld.get(v)<<endl;
    }
    return 0;
}
/*
color a
cls
g++ HLD.cpp -o a & a
5 3
4 2 5 2 1
1 2
1 3
3 4
3 5
2 3
1 5 3
2 3


*/





