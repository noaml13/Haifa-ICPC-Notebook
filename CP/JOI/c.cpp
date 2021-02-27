#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 2e18, MOD=1e9+9;

int n;
vvi g;
vii dp;
string s;
int ans = 0;
void dfs(int cur, int p=-1){
    int sumx = 0, sumy = 0, maxi = 0;
    for(auto nei:g[cur]) if(nei!=p){
        dfs(nei, cur);
        sumx+=dp[nei].x;
        sumy+=dp[nei].y;
        chkmax(maxi , dp[nei].y);
    }
    if (s[cur]) {
        sumx--; sumy--;
        chkmax(dp[cur].x, sumy);
        chkmax(dp[cur].y, sumy);
        chkmax(dp[cur].x, maxi+1);
        chkmax(dp[cur].y, maxi-1);
        chkmax(dp[cur].y, int(1));
    }
    else{
        chkmax(dp[cur].x, sumy);
        chkmax(dp[cur].y, sumy);
    }
    chkmax(ans, dp[cur].x);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    g.resize(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    cin>>s; loop(i,0,n) s[i]-='0';
    dp.resize(n);
    dfs(0);
    //cout<<dp[1].y<<endl;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6
2 3
4 3
1 3
3 5
6 2
110011


*/
