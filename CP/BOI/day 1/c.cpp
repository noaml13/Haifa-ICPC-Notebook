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

struct DSU{
    int n;
    vi p,sz;
    int cnt = 0;
    DSU(int _n): cnt(_n), n(_n), sz(2*_n,1), p(2*_n,-1){}
    int find(int c, int &d){
        int a = -1, b = -1;
        while(p[c]!=-1){
            if (a!=-1) p[a] = p[c]; //keep pairity
            a = b;
            b = c;
            c = p[c];
            d++;
        }
        return c;
    }
    int uni(int a, int b){
        int d = 0;
        a = find(a, d);
        b = find(b, d);
        if (a==b){
            //cout<<"IN UNI: "<<d<<" "<<da<<endl;
            return d%2==0; 
        }
        if (d%2){
            int cur = cnt++;
            sz[cur] = sz[a]+1;
            p[a] = cur;
            a = cur;
        }
        if (sz[a]>sz[b]) swap(a,b);
        sz[b]+=sz[a];
        p[a]=b;
        return 0;
    }
};
int l,r;
vi d;
vvii g;
bool can;
void dfs(int cur, int p=-1, int dd=0){
    //cout<<cur<<": "<<dd<<endl;
    if (d[cur]!=-1){
        if (d[cur]%2!=dd%2) {
            can=1;
            //cout<<"WOW: "<<cur<<endl;
        }
        return;
    }
    d[cur] = dd;
    for(auto nei:g[cur]) if(nei.x!=p && !(nei.y>=l && nei.y<=r)) dfs(nei.x, cur, dd+1);
}
bool cmp(pair<ii, int>& a, pair<ii, int>& b){
    return a.x.y>b.x.y;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    int n,m,q; cin>>n>>m>>q;
    vii edge(m);
    for(auto &e:edge) cin>>e.x>>e.y, e.x--, e.y--;
    g.resize(n);
    loop(i,0,m){
        int a = edge[i].x, b = edge[i].y;
        g[a].pb({b,i}); g[b].pb({a,i});
    }
    if (n<=2000 && m<=2000 &q<=2000){
        loop(_,0,q){
            cin>>l>>r; l--; r--;
            /*d.clear(); d.resize(n,-1);
            can = 0;
            loop(i,0,n){
                if (d[i]==-1) dfs(i);
            }
            cout<<(can?"YES":"NO")<<endl;*/
            DSU dsu(n);
            int ans = 0;
            loop(i,0,l) 
                if (dsu.uni(edge[i].x, edge[i].y)) ans = 1;
            loop(i,r+1,m) 
                if (dsu.uni(edge[i].x, edge[i].y)) ans = 1;
            cout<<(ans?"YES":"NO")<<endl;
        }
        return 0;
    }
    vector<pair<ii, int>> qur(q);
    loop(i,0,q) cin>>qur[i].x.x>>qur[i].x.y, qur[i].x.x--, qur[i].x.y--, qur[i].y=i;
    sort(all(qur), cmp);
    vi ans(q);
    int last = m-1, res = 0;
    DSU dsu(n);
    for(auto p:qur){
        int a = p.x.x, b = p.x.y, i = p.y;
        for(;last>b;last--) chkmax(res,dsu.uni(edge[last].x, edge[last].y));
        ans[i] = res;
    }
    loop(i,0,q) cout<<(ans[i]?"YES":"NO")<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6 8 3
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
1 7
1 4
1 3

*/