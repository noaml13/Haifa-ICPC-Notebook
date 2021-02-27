#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;

struct UnionFind{
    vi p,sz;
    int n;
    UnionFind(int _n): n(_n){
        p.resize(n,-1);
        sz.resize(n,1);
    }
    int find(int cur){
        if (p[cur]==-1) return cur;
        return p[cur] = find(p[cur]);
    }
    bool uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b) return 0;
        if (sz[a]>sz[b]) swap(a,b);
        sz[b] += sz[a];
        p[a] = b;
        return 1;
    }
};

struct BINARY{
    int n, LOGN=1;
    vector<vii> g;
    vi depth;
    vvi dis, anc;
    BINARY(vector<vii>& _g):g(_g), n(_g.size()){
        for(int i=1;i<=n;i<<=1,++LOGN);
        depth.resize(n,0);
        dis.resize(n,vi(LOGN,0));
        anc.resize(n,vi(LOGN,-1));
        dfs(0);
    }
    void dfs(int cur, int p=-1,int d=0, int last_dis=0){
        anc[cur][0] = p;
        dis[cur][0] = last_dis;
        for(int i=1;anc[cur][i-1]!=-1;i++){
            anc[cur][i] = anc[anc[cur][i-1]][i-1];
            dis[cur][i] = max(dis[cur][i-1],dis[anc[cur][i-1]][i-1]);
        }
        depth[cur] = d;
        for(auto nei:g[cur]){
            if (nei.x==p) continue;
            dfs(nei.x, cur, d+1, nei.y);
        }
    }
    int lift(int& a, int d){
        int res=0;
        for(int i=LOGN-1;i>=0;--i){
            if (d>= 1<<i){
                d-=1<<i;
                chkmax(res, dis[a][i]);
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
                chkmax(res, dis[a][i]);
                chkmax(res, dis[b][i]);
                a=anc[a][i];
                b=anc[b][i];
            }
        }
        chkmax(res, dis[a][0]);
        chkmax(res, dis[b][0]);
        return res;
    }
};

int n, m, q, N;

int conv(int i, int j){
    return i*m+j;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>q;
    N=n*m;
    vvi h(n, vi(m));
    loop(i,0,n){
        loop(j,0,m) cin>>h[i][j];
    }
    vector<pair<int,ii>> edge;
    loop(i,0,n){
        loop(j,0,m){
            if (i){
                int w = max(h[i][j], h[i-1][j]);
                edge.pb({w,{conv(i,j),conv(i-1,j)}});
            }
            if (j){
                int w = max(h[i][j], h[i][j-1]);
                edge.pb({w,{conv(i,j),conv(i,j-1)}});
            }
        }
    }
    sort(all(edge));
    vector<vii> g(N);
    UnionFind d(N);
    for(auto& e: edge){
        if (d.uni(e.y.x,e.y.y)){
            g[e.y.x].pb({e.y.y, e.x});
            g[e.y.y].pb({e.y.x, e.x});
        }
    }
    BINARY bin(g);
    loop(i,0,q){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        --x1;--y1;--x2;--y2;
        if (x1==x2 && y1==y2) cout<<h[x1][y1]<<endl;
        else cout<<bin.query(conv(x1,y1), conv(x2,y2))<<endl;
    }
    return 0;
}
/*
color a
cls
g++ Mountaineers.cpp -o a & a
3 5 4
3 3 2 1 3
2 4 5 4 4
2 1 3 2 2
2 3 2 4
2 4 2 5
1 4 3 4
2 1 3 2
*/

