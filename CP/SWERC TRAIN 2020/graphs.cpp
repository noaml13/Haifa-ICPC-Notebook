#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb emplace_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD = 1e9 + 7;

// p[i] -> parent of i
// sz[i] -> sz of compenent
struct DSU{
    int n;
    vi p, sz;
    DSU(int n): n(n), p(n,-1), sz(n,1){}
    int find(int c){
        if (p[c]==-1) return c;
        p[c] = find(p[c]);
        return p[c];
    }
    void uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b) return ;
        if (sz[a]>sz[b]) swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
    }
};

vector<vector<int>> g;
vector<bool> check;
void dfs(int cur){
    if (check[cur]) return ;
    check[cur] = 1;
    // ----- //
    for(int nei:g[cur]){
        dfs(nei);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    g.resize(n);
    loop(i,0,m){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].pb(a);
    }
    check.resize(n,0);
    dfs(0);
    map<int, int> conv;
    conv[10005] = 564;
    priority_queue<int> q; q.push(0);
    q.pop();
    int c = q.top();
    return 0;
}
/*
color a
cls
g++ graphs.cpp -o a & a

*/
