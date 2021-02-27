/*
ID: licht.n1
PROG: castle
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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

int n,m;
vvi g;
vb check;
int conv(int i, int j){
    return i*m+j;
}
int dfs(int cur){
    if (check[cur]) return 0;
    //cout<<"VISIT: "<<cur<<endl;
    check[cur]=1;
    int sz = 1;
    for(auto nei:g[cur]){
        sz+=dfs(nei);
    } 
    return sz;
}
int main() {
    ofstream cout("castle.out");
    ifstream cin("castle.in");
    cin>>m>>n;
    g.resize(n*m);
    loop(i,0,n) loop(j,0,m){
        int a; cin>>a;
        if ((a&1)==0) g[conv(i,j)].pb(conv(i,j-1));
        if ((a&2)==0) g[conv(i,j)].pb(conv(i-1,j));
        if ((a&4)==0) g[conv(i,j)].pb(conv(i,j+1));
        if ((a&8)==0) g[conv(i,j)].pb(conv(i+1,j));
    }
    check.clear(); check.resize(n*m,0);
    int cnt=0,maxr=0;
    loop(i,0,n*m){
        if (!check[i]){
            cnt++; chkmax(maxr,dfs(i));
            //cout<<"END!!!!"<<endl;
        }
    }
    cout<<cnt<<endl<<maxr<<endl;
    int maxr2=0, d=-1;
    ii p;
    loop(j,0,m) for(int i=n-1;i>=0;--i){
        check.clear(); check.resize(n*m,0);
        int cur = dfs(conv(i,j));
        if (i) cur += dfs(conv(i-1,j));
        if (cur>maxr2) p={i,j},d=0,maxr2=cur;
        check.clear(); check.resize(n*m,0);
        cur = dfs(conv(i,j));
        if (j<m-1) cur += dfs(conv(i,j+1));
        if (cur>maxr2) p={i,j},d=1,maxr2=cur;
    }
    cout<<maxr2<<endl<<p.x+1<<" "<<p.y+1<<" "<<(d?'E':'N')<<endl;
    return 0;
}
/*
color a
cls
g++ castle.cpp -o a & a
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
*/
