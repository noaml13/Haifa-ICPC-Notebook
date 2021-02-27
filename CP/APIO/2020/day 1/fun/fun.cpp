#include "fun.h"
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

struct SEG{
	int sz;
	vii a;
	SEG(int n){
		for(sz=1;sz<n;sz*=2);
		a.resize(2*sz);
	}
	void update(int i, int x){
		a[i+sz]={x, i};
		i+=sz;
		for(i/=2;i;i/=2) a[i] = min(a[2*i], a[2*i+1]);
	}
	int query(int l, int r){
		ii res = {INF, -1};
		for(l+=sz, r+=sz;l<=r;l/=2,r/=2){
			if (l%2) chkmin(res, a[l++]);
			if (r%2==0) chkmin(res, a[r--]);
		}
		return res.y;
	}
};

int n;
vi d;
vb check;
vii best;
vi p;
vii g;
void fix(int i){
	for(;i;i = p[i]) {
		best[i] = max(best[g[i].x], best[g[i].y]);
		if (!check[i]) chkmax(best[i],  ii(d[i],i));
	}
}
int find(int i){
	ii ans = {best[i].x-d[i], best[i].y};
	for(int h=0;i;i = p[i], h++) {
		if (!check[i]) chkmax(ans, ii(h,i));
		int nei = g[p[i]].x;
		if (nei==i) nei = g[p[i]].y;
		if (nei==0) continue;
		chkmax(ans, ii(best[nei].x - d[nei] + h + 2, best[nei].y));
	}
	return ans.y;
}
void add_edge(int a, int b){
	if (g[a].x==0) g[a].x = b;
	else g[a].y = b;
	p[b] = a;
}
vi dist;
void solve2(int cur, int l, int r, SEG& seg, int d){
	if (l==r) return ;
	int i1 = seg.query(l, cur-1);
	int i2 = seg.query(cur+1, r);
	//cout<<"CUR: "<<cur<<" "<<l<<" "<<r<<" "<<i1<<" "<<i2<<endl;
	if (i1!=-1 && dist[i1]==d+1){
		seg.update(i1, INF);
		add_edge(cur, i1);
		solve2(i1, l, cur-1, seg, d+1);
	}
	if (i2!=-1 && dist[i2]==d+1){
		seg.update(i2, INF);
		add_edge(cur, i2);
		solve2(i2, cur+1, r, seg, d+1);
	}
}
int solve(int cur, SEG& seg, int d=0){
	if (cur==n) return cur;
	int i1 = seg.query(cur+1,n);
	seg.update(i1, INF);
	if (dist[i1]!=d+1) cout<<"FUCK! "<<cur<<endl;
	int i2 = seg.query(cur+1, n);
	if (i2==i1 || dist[i2]!=d+1) {
		if (cur+1==i1){
			add_edge(i1, cur);
			return solve(i1, seg, d+1);
		}
		add_edge(cur, i1);
		solve2(i1, cur+1, n, seg, d+1);
		return cur;
	}
	seg.update(i2, INF);
	if (i1<i2) swap(i1, i2);
	add_edge(cur, i2); add_edge(i1, cur);
	solve2(i2, cur+1, i1-1, seg, d+1);
	return solve(i1, seg, d+1);
}
vi createFunTour(int N, int Q) {
	n = N;
	g.resize(n+1, {0,0}); p.resize(n+1,0);
	dist.resize(n+1);
	SEG seg(n+1);
	loop(i,2,n+1) {
		dist[i] = hoursRequired(0,i-1);
		seg.update(i, dist[i]);
	}
	int s = 1;
	s = solve(s, seg);
	//cout<<"S: "<<s<<endl;
	/*loop(i,2,n+1) {
		int a = i/2, b = i;
		add_edge(a,b);
	}*/
	check.resize(n+1); 
	best.resize(n+1, {-INF,-1});
	d.resize(n+1);
	queue<ii> q; q.push({s,0});
	int cur;
	while(q.size()){
		ii c = q.front(); q.pop();
		if (c.x==0) continue;
		d[c.x] = c.y;
		cur = c.x; //deepest
		fix(c.x);
		q.push({g[c.x].x, c.y+1});
		q.push({g[c.x].y, c.y+1});
	}
	vi per;
	per.pb(cur); check[cur] = 1; fix(cur);
	loop(i,1,n){
		cur = find(cur);
		per.pb(cur); check[cur] = 1; fix(cur);
	}
	for(int& x:per) x--;
	//for(auto x:per) cout<<x<<" "; cout<<endl;
	return per;
}
/*
color a
cls
g++ fun.cpp grader.cpp -o a & a
9 40000
0 1
1 2
2 3
2 4
4 8
8 5
5 7
7 6


25 400000
0 1
0 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
5 11
5 12
6 13
6 14
7 15
7 16
8 17
8 18
9 19
9 20
10 21
10 22
11 23
11 24
*/
