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
		ii v = {max(sub[nei.x][0].x, nei.y), nei.y}; 
		minsert(sub[cur], v);
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
int query(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	//int minia = mini[a][]
	int aa = a, bb = b;
	//cout<<aa<<" "<<a<<" : "<<bb<<" "<<b<<" "<<depth[a]<<" "<<depth[b]<<endl;
	int maxw=0, minie = INF;
	if (depth[a]!=depth[b]){
		lift(a, depth[a]-depth[b]-1, maxw, minie);
		if (anc[a][0]==b) {
			int cnt = 0;
			loop(i,0,2) {
				if(mini[b][i].y!=a) cnt++;
				if (cnt==2) chkmin(minie, mini[b][i].x);
				//cout<<"SUB: "<<sub[b][i].x<<" "<<sub[b][i].y<<endl;
			}
			chkmax(maxw, djump[a][0]);
			chkmin(minie, djump[b][0]); //change n p->p
			chkmin(minie, sub[aa][0].x);
			//cout<<"PP: "<<a<<" "<<b<<" "<<maxw<<" "<<minie<<endl;
			loop(i,0,2) if(sub[b][i].y!=a && sub[b][i].y!=-1) {
				//cout<<"SUB: "<<sub[b][i].x<<" "<<sub[b][i].y<<endl;
				chkmin(minie, sub[b][i].x);
			}
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
	//change on p
	loop(i,0,3) if (mini[p][i].y!=a && mini[p][i].y!=b) chkmin(minie, mini[p][i].x); 
	chkmin(minie, djump[p][0]); //change n p->p
	chkmin(minie, sub[aa][0].x); //change aa
	chkmin(minie, sub[bb][0].x); //change bb
	return max(maxw, minie);
}

void init(int N, int M, vector<int> U, vector<int> V, vector<int> W) {
	n = N, m = M;
	vector<pair<int, ii>> edge(m);
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
		}
	}
	//BINARY
	for(int i=1;i<=n;i<<=1,++LOGN);
	depth.resize(n,0);
	anc.resize(n,vi(LOGN,-1)); djump.resize(n,vi(LOGN,-1));
	miniv.resize(n,vi(LOGN,-1));
	sub.resize(n, vii(2,{INF,-1}));
	predfs(0);
	dfs(0);
}

int getMinimumFuelCapacity(int X, int Y) {
	int v =query(X,Y);
	return (v>=INF?-1:v);
}
/*
color a
cls
g++ swap.cpp grader.cpp -o a & a
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