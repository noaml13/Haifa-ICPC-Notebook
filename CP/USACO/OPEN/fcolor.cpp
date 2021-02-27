/*
ID: licht.n1
PROG: fcolor
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9;

struct DSU{
    int n;
    vi p;
    vvi g;
    DSU(int n):n(n),p(n,-1), g(n){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c]=find(p[c]);
    }
    void uni(int a, int b){
        a = find(a); b = find(b);
        if (a==b) return;
        if (g[a].size()<g[b].size()) swap(a,b);
        for(auto nei:g[b]) g[a].pb(nei);
        p[b]=a;
    }
    int skwiz(int cur){
        loop(i,1,g[cur].size()) uni(g[cur][0], g[cur][i]);
        int head = find(g[cur][0]);
        g[cur].clear(); g[cur].pb(head);
        return head;
    }
};

int32_t main() {
    ofstream cout("fcolor.out");
    ifstream cin("fcolor.in");
    int n,m; cin>>n>>m;
    DSU d(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        d.g[a].pb(b);
    }
    priority_queue<ii> q;
    loop(i,0,n) if (d.g[i].size()>1) q.push({d.g[i].size(),i});
    while(q.size()){
        int cur = q.top().y; q.pop();
        if (d.p[cur]!=-1 || d.g[cur].size()<=1) continue;
        int head = d.skwiz(cur);
        //cout<<"VIS: "<<cur+1<<" "<<head+1<<endl;
        if (d.g[head].size()>1) q.push({d.g[head].size(),head});
    }
    map<int, int> conv;
    int cnt=1;
    loop(i,0,n){
        int cur = d.find(i);
        if (!conv[cur]) conv[cur]=cnt++;
        cout<<conv[cur]<<endl;
    }
    return 0;
}
/*
color a
cls
g++ fcolor.cpp -o a & a
9 12
1 2
4 2
5 8
4 6
6 9
2 9
8 7
8 3
7 1
9 4
3 5
3 4
*/
