#include "swap.h"
#include <bits/stdc++.h>
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
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD=1e9+9;

struct DSU{
	int n;
	vi p,sz;
	DSU(int n): n(n), p(n,-1), sz(n,1){}
	int find(int c){
		if (p[c]==-1) return c;
		return p[c] = find(p[c]);
	}
	bool uni(int a, int b){
		a = find(a), b = find(b);
		if (a==b) return 0;
		if (sz[a]>sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
		return 1;
	}
};

int n,m;
int LOGN=1;
vvii g;
vi depth;
vvi anc, djump, miniv;
vvii sub;
vi up, cycv;
vvii mini;

void minsert(vii& a, ii v){
	int i = 0;
	while(i<a.size() && a[i]<v) i++;
	while(i<a.size()) swap(a[i++], v);
}
void predfs(int cur, int p=-1){
	for(auto nei:g[cur]) if (nei.x!=p){
		ii v = {nei.y, nei.x};
		minsert(mini[cur], v);
	}
	sub[cur][0] = {mini[cur][1].x, -1}; //do swap here
	for(auto nei:g[cur]) if (nei.x!=p){
		predfs(nei.x, cur);
        chkmin(cycv[cur], max(cycv[nei.x], nei.y));
		ii v = {max(sub[nei.x][0].x, nei.y), nei.y}; 
		minsert(sub[cur], v);
	}
}
void updfs(int cur, int p=-1, int pw=-1){
    up[cur] = INF;
    if (p!=-1){
        chkmin(cycv[cur], max(cycv[p], pw));
        up[cur] = up[p];
		loop(i,0,3){
            if (sub[p][i].y==cur || sub[p][i].y==-1) continue;
            chkmin(up[cur], sub[p][i].x);
            break;
        }
        int cnt = 0;
        loop(i,0,3){
            if(mini[p][i].y!=cur) cnt++;
            if (cnt==2) {
                chkmin(up[cur], mini[p][i].x);
                break;
            }
        }
        chkmax(up[cur], pw);
    }
    for(auto nei:g[cur]) if (nei.x!=p){
        updfs(nei.x, cur, nei.y);
	}
}
void ddfs(int cur, int p=-1,int d=0, int w=INF){
	anc[cur][0] = p; djump[cur][0] = w;
	miniv[cur][0] = INF;
	for(int i=1;anc[cur][i-1]!=-1;i++){
		anc[cur][i] = anc[anc[cur][i-1]][i-1];
		djump[cur][i] = max(djump[cur][i-1], djump[anc[cur][i-1]][i-1]);
        //cycv[cur][i] = min(cycv[cur][i-1], cycv[anc[cur][i-1]][i-1]);
	}
	depth[cur] = d;
	for(auto nei:g[cur]) if (nei.x!=p){
		ddfs(nei.x, cur, d+1, nei.y);
	}
}
void dfs(int cur, int p=-1,int d=0, int w=INF){
	anc[cur][0] = p; djump[cur][0] = w;
	miniv[cur][0] = INF;
	if (p!=-1){
		loop(i,0,3) if(cur!=mini[p][i].y) chkmin(miniv[cur][0], mini[p][i].x);
	}
	for(int i=1;anc[cur][i-1]!=-1;i++){
		anc[cur][i] = anc[anc[cur][i-1]][i-1];
		djump[cur][i] = max(djump[cur][i-1], djump[anc[cur][i-1]][i-1]);
		miniv[cur][i] = min(miniv[cur][i-1], miniv[anc[cur][i-1]][i-1]);
	}
	depth[cur] = d;
	for(auto nei:g[cur]) if (nei.x!=p){
		dfs(nei.x, cur, d+1, nei.y);
	}
}
void lift(int& a, int d, int& maxw, int &minie){
	loop(i,0,LOGN){
		if (d & (1<<i)){
			chkmax(maxw, djump[a][i]);
			chkmin(minie, miniv[a][i]);
			a = anc[a][i];
		}
	}
}
int tmp;
int lca(int a,int b, int &d){
    if(depth[a]<depth[b]) swap(a,b);
    lift(a, depth[a]-depth[b], d, tmp);
    if (a==b) return a;
    for(int i=LOGN-1;i>=0;--i){
		if (anc[a][i]!=anc[b][i]){
			chkmax(d, max(djump[a][i], djump[b][i]));
			a=anc[a][i];
			b=anc[b][i];
		}
	}
    chkmax(d, max(djump[a][0], djump[b][0]));
    return anc[a][0];
}
int query(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	int aa = a, bb = b;
	int maxw=0, minie = cycv[a];
	if (depth[a]!=depth[b]){
		lift(a, depth[a]-depth[b]-1, maxw, minie);
		if (anc[a][0]==b) {
			int cnt = 0;
            vii vec = mini[b];
            minsert(vec, {djump[b][0], -1});
			loop(i,0,3) {
				if(vec[i].y!=a) cnt++;
				if (cnt==2) {
                    chkmin(minie, vec[i].x);
                    break;
                }
			}
			chkmax(maxw, djump[a][0]);
			chkmin(minie, sub[aa][0].x); // change in aa
			loop(i,0,3) if(sub[b][i].y!=a && sub[b][i].y!=-1) {
				chkmin(minie, sub[b][i].x);
			}
            chkmin(minie, up[b]);
			return max(maxw, minie);
		}
		lift(a, 1, maxw, minie);
	}
	for(int i=LOGN-1;i>=0;--i){
		if (anc[a][i]!=anc[b][i]){
			chkmax(maxw, max(djump[a][i], djump[b][i]));
			chkmin(minie, min(miniv[a][i], miniv[b][i]));
			a=anc[a][i];
			b=anc[b][i];
		}
	}
	int p = anc[a][0];
	chkmax(maxw, max(djump[a][0], djump[b][0]));
	//change on p->child (!=a,b):
	loop(i,0,3) if (mini[p][i].y!=a && mini[p][i].y!=b) chkmin(minie, mini[p][i].x); 
	chkmin(minie, djump[p][0]); //change n p->p
	chkmin(minie, sub[aa][0].x); //change aa
	chkmin(minie, sub[bb][0].x); //change bb
	return max(maxw, minie);
}

void init(int N, int M, vector<int> U, vector<int> V, vector<int> W) {
	n = N, m = M;
	vector<pair<int, ii>> edge(m), cyc;
	loop(i,0,m) edge[i] = {W[i], {U[i], V[i]}};
    sort(all(edge));
	DSU dsu(n);
	g.resize(n);
	mini.resize(n, vii(3,{INF,-1}));
    for(auto e:edge){
		if (dsu.uni(e.y.x, e.y.y)){
			g[e.y.x].pb({e.y.y, e.x});
			g[e.y.y].pb({e.y.x, e.x});
		}
		else {
            minsert(mini[e.y.x],{e.x,-1});
			minsert(mini[e.y.y],{e.x,-1});
			cyc.pb(e);
		}
	}
	//BINARY
	for(int i=1;i<=n;i<<=1,++LOGN);
	depth.resize(n,0);
	anc.resize(n,vi(LOGN,-1)); djump.resize(n,vi(LOGN,-1));
	miniv.resize(n,vi(LOGN,-1));
	sub.resize(n, vii(3,{INF,-1}));
    up.resize(n); cycv.resize(n, INF);
    ddfs(0); // for lca
    for(auto e:cyc){
        int d = e.x;
        int u = lca(e.y.x, e.y.y, d);
        chkmin(cycv[u], d);
    }
	predfs(0);
    updfs(0);
	dfs(0);
}

int getMinimumFuelCapacity(int X, int Y) {
	int v =query(X,Y);
	return (v>=INF?-1:v);
}
/*
color a
cls
g++ swap2.cpp grader.cpp -o a & a
5 6
0 1 4
0 2 4
1 2 1
1 3 2
1 4 10
2 3 3
3
1 2
2 4
0 1

3 2 
0 1 5
0 2 5
1
1 2
*/