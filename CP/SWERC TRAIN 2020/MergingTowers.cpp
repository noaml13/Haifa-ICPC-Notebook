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
const int INF = 2e9, MOD = 1e9 + 7;




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
    int lift(int& a, int d){
        int res=0;
        for(int i=LOGN-1;i>=0;--i){
            if (a==-1) return res;
            if (d>= 1<<i){
                d-=1<<i;
                res += 1<<i;
                a = anc[a][i];
            }
        }
        return res;
    }
    int query(int a,int b){
        if(depth[a]<depth[b]) swap(a,b);
        int res = lift(a, depth[a]-depth[b]);
        if (a==b) return res;
        for(int i=LOGN-1;i>=0;--i){
            if (anc[a][i]!=anc[b][i]){
                res += 2 * (1<<i);
                a=anc[a][i];
                b=anc[b][i];
            }
        }
        return res+2;
    }
};
struct DSU{
    int n;
    vi p;
    vector<set<int>> s;
    int dup = 0;
    DSU(int n): n(n), p(n), s(n), dup(n-1){}
    void add(int i, int x){
        s[i].insert(x);
        if (...) dup--;
    }
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    void uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b) return ;
        if (s[a].size()>s[b].size()) swap(a,b);
        p[a] = b;
        for(int x:s[a]){
            add(b, x);
        }
        s[a].clear();
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    return 0;
}
/*
color a
cls
g++ MergingTowers.cpp -o a & a




*/

}