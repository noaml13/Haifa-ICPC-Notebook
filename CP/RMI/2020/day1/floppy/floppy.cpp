#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);++i)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);--i)
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int MOD = 1e9+7, INF = 1e9+20;
//#define DEBUG
#ifndef DEBUG
#include "floppy.h"
#endif
struct SEG{
    int sz;
    vii a;
    SEG(const vi& aa){
        for(sz=1;sz<aa.size(); sz*=2);
        a.resize(2*sz);
        loop(i,0,aa.size()) a[i+sz] = {aa[i], i};
        loopr(i,1,sz) a[i] = max(a[2*i], a[2*i+1]);
    }
    ii query(int l, int r){
        ii res = {-INF, -1};
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res, a[l++]);
            if (r%2==0) chkmax(res, a[r--]);
        }
        return res;
    }
};
#ifdef DEBUG
void save_to_floppy(string s){
    cout<<s<<endl;
}
#endif
int LOG;
int n;
string bits;
void Tobits(int v, int sz){
    loop(i,0,LOG) {
        if (sz<=(1<<i)) break;
        bits += ((v & (1<<i))?'1':'0');
    }
}
SEG seg(vi(0));
void solve(int l, int r){
    if (l>r) return ;
    int m = seg.query(l, r).y;
    int szl = m-l, szr = r-m;
    if (szl) bits+='1';
    else bits+='0';
    solve(l, m-1);
    if (szr) bits+='1';
    else bits+='0';
    solve(m+1, r);
}

void read_array(int subtask_id, const vector<int> &v) {
    n = v.size();
    for(LOG = 1; (1<<LOG)<n; LOG++);
    bool asc = 1,  dec = 1;
    loop(i,0,n-1){
        if (v[i]>v[i+1]) asc = 0;
        else dec = 0;
    }
    if (asc || dec) loop(b,0,2) b--;
    seg = SEG(v);
    solve(0,n-1);
    save_to_floppy(bits);
}

vi arr;
int ind=0;
bool readBits(){
    return bits[ind++]=='1';
}
int cnt=0;
vii g;
vi h;
int build(){
    int cur = cnt++;
    if (readBits()) g[cur].x = build();
    if (readBits()) g[cur].y = build();
    return cur;
}
int predfs(int cur){
    if (cur==-1) return -1;
    h[cur] = 0;
    chkmax(h[cur], predfs(g[cur].x)+1);
    chkmax(h[cur], predfs(g[cur].y)+1);
    return h[cur];
}
void dfs(int cur){
    if (cur==-1) return ;
    dfs(g[cur].x);
    arr[cnt++] = h[cur];
    dfs(g[cur].y);
}
std::vector<int> solve_queries(int subtask_id, int N, const string &BITS,
                                const vector<int> &a, const vector<int> &b) {
    //return vi(a.size());
    n = N;
    bits = BITS;
    int q = a.size();
    for(LOG = 1; (1<<LOG)<n; LOG++);
    arr.resize(n);
    g.resize(n, {-1,-1});
    h.resize(n);
    cnt = 0;
    int root = build();
    predfs(root);
    cnt = 0;
    dfs(root);
    seg = SEG(arr);
    vi ans(q);
    loop(i,0,q) ans[i] = seg.query(a[i], b[i]).y;
    return ans;
}
#ifdef DEBUG
int main(){
    int n,q; cin>>n>>q;
    vi v(n); loop(i,0,n) cin>>v[i];
    //loop(i,0,n) cout<<v[i]<<" "; cout<<endl;
    read_array(0, v);
    solve_queries(0, n, bits, vi(0), vi(0));
    loop(i,0,n) cout<<arr[i]<<" ";
    return 0;
}
#endif
/*
color
cls
g++ floppy.cpp -o b & b
8 3
3 2 9 8 7 11 3 4
*/