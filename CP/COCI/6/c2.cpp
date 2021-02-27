#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;


vvi solve(int k){
    if (k==1){
        vvi g(4);
        g[1].pb(0); g[2].pb(0);
        g[3].pb(1); g[3].pb(2);
        return g;
    }
    if (k==-1){
        /*vvi g(4);
        g[1].pb(0); g[2].pb(0);
        g[3].pb(1); g[3].pb(2);*/
        vvi g(2);
        g[1].pb(0);
        return g;
    }
    if (k==0){
        vvi g(3);
        g[1].pb(0); g[2].pb(1);
        return g;
    }
    int r = abs(k), sign=(k>0?1:-1);
    vvi g = solve(-(k/2) + (r%2 && k<0));
    int n = g.size();
    g.resize(n+3);
    for(auto pre:g[n-1]) {
        g[n].pb(pre);
        g[n+1].pb(pre);
    }
    if (r%2){
        g.resize(n+4);
        g[n+2].pb(0);
        g[n+3].pb(n-1); g[n+3].pb(n); g[n+3].pb(n+1); g[n+3].pb(n+2);
    }
    else{
        g[n+2].pb(n-1); g[n+2].pb(n); g[n+2].pb(n+1);
    }
    return g;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>k;
    vvi g = solve(k);
    int n = g.size(), m=0;
    loop(i,0,n) m+=g[i].size();
    cout<<n<<" "<<m<<endl;
    loop(i,0,n) for(auto pre:g[i]) cout<<pre+1<<" "<<i+1<<endl;
    return 0;
}
/*
color a
cls
g++ c2.cpp -std=c++11 -O2 -static -s -lm -o a & a
1


*/


 