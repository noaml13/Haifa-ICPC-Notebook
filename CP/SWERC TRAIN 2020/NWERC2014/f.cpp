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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

struct DSU{
    int n;
    vi sz, p;
    DSU(int n): n(n), p(n,-1), sz(n,1){}
    int find(int c){
        return p[c]==-1?c:p[c] = find(p[c]);
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
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    map<int, int> mm;
    vector<pair<ii, int>> edges, ans;
    loop(i,0,n){
        int m; cin>>m;
        vi a(m); 
        loop(j,0,m) {
            cin>>a[j];
            if (mm.find(a[j])!=mm.end()) edges.pb({{mm[a[j]], i}, a[j]});
        }
        loop(j,0,m) mm[a[j]] = i;
    }
    DSU dsu(n);
    for(auto e:edges) {
        //cout<<"E: "<<e.x.x<<" "<<e.x.y<<endl;
        if(dsu.uni(e.x.x, e.x.y)) ans.pb(e);
    }
    //cout<<"ANS: "<<ans.size()<<" "<<edges.size()<<endl;
    if (ans.size()<n-1) return cout<<"impossible"<<endl,0;
    for(auto e:ans) cout<<e.x.x+1<<" "<<e.x.y+1<<" "<<e.y<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
6
2 17 10
2 5 10
2 10 22
3 17 22 9
2 17 8
3 9 22 16

6
2 17 10
1 5
2 10 22
3 17 22 9
2 17 8
3 9 22 16




*/