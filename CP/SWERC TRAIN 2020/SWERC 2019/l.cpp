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

ii operator+(ii a, ii b){ return {a.x+b.x, a.y+b.y};}
ii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
int n;
bool in(ii p){
    return p.x>=0 && p.y>=0 && p.x<n && p.y<n;
}
vector<string> a;
vvi riv;
void dfsR(ii p, int col){
    if (!in(p) || a[p.x][p.y]!='*' || riv[p.x][p.y]!=-1) return ;
    riv[p.x][p.y] = col;
    loop(k,0,4) dfsR(p + dir[k], col);
}
vvi near;
vvb check;
vii pos;
void dfsL(ii p, int col){
    if (!in(p) || check[p.x][p.y] || near[p.x][p.y]!=col) return ;
    check[p.x][p.y] = 1;
    pos.pb(p);
    loop(k,0,4) dfsL(p + dir[k], col);
}
const int MAX = 2e6 + 10;
int r;
int mem[MAX];
vi g[MAX];
int getG(int v){
    if (mem[v]!=-1) return mem[v];
    vi vals;
    loop(i,0,r){
        if (v & (1<<i)) continue;
        int u = v | (1<<i);
        bool ok = 1;
        for(int j:g[i]) {
            if (v & (1<<j)) ok = 0;
        }
        if (ok) vals.pb(getG(u));
    }
    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());
    int res = 0;
    while(res<vals.size() && vals[res]==res) res++;
    return res;
}
int solve(){
    r = pos.size();
    fill(mem, mem + (1<<r), -1);
    loop(i,0,r) g[i].clear();
    loop(i,0,r) loop(j,0,i){
        bool ok = 0;
        loop(k,0,4) if (pos[i]+dir[k]==pos[j]) ok = 1;
        if (ok) g[i].pb(j), g[j].pb(i);
    }
    return getG(0);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    loop(i,0,n) cin>>a[i];
    riv.resize(n, vi(n, -1));
    int cnt = 0;
    loop(i,0,n) loop(j,0,n) if(a[i][j]=='*' && riv[i][j]==-1) 
        dfsR({i,j},cnt++);
    near.resize(n, vi(n, -1));
    loop(i,0,n) loop(j,0,n) {
        if (a[i][j]!='.') continue;
        loop(k,0,4){
            ii p = ii(i,j) + dir[k];
            if (in(p) && a[p.x][p.y]=='*') near[i][j] = riv[p.x][p.y];
        }
    }
    check.resize(n, vb(n));
    int ans = 0;
    loop(i,0,n) loop(j,0,n) if(!check[i][j] && near[i][j]!=-1){
        dfsL({i,j}, near[i][j]);
        ans ^= solve();
        pos.clear();
    }
    cout << (ans?"First":"Second") << " player will win"<< endl;
    return 0;
}
/*
color a
cls
g++ l.cpp -o a & a
3
...
...
***



*/