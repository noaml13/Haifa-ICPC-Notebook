#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

struct eve{
    int type;
    int c,v,f;
};
bool operator<(eve a, eve b){
    if (a.f == b.f) return a.type < b.type;
    return a.f > b.f;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n;
    vector<eve> a;
    int sz = 0;
    loop(i,0,n){
        int c,f,v; cin>>c>>f>>v;
        a.pb({0,c,v,f});
        sz+=c;
    }
    cin>>m;
    loop(i,0,m){
        int c,f,v; cin>>c>>f>>v;
        a.pb({1,c,v,f});
    }
    sort(all(a));
    vi dp(sz+1, -INF);
    dp[0] = 0;
    for(auto &e:a){
        if (e.type==0){
            loopr(i,0,sz-e.c+1) chkmax(dp[i+e.c], dp[i]-e.v);
        }
        else{
            loop(i,e.c,sz+1) chkmax(dp[i-e.c], dp[i]+e.v);
        }
    }
    int ans = 0;
    loop(i,0,sz+1) chkmax(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a

*/



