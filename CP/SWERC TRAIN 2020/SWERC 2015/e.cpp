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
const int INF = 1e18;
const int MOD = (int(1)<<31) - 1;

void add(int &a, int b){
    a = (a+b)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int st; cin>>st; st--;
    vi sp(n);
    loop(i,0,n) cin>>sp[i], sp[i]--;
    vvi dp(n, vi(n+1,0)); // dp[i][x]
    dp[0][st] = 1;
    loop(i,0,n-1){
        loop(x,0,n+1){
            int y = sp[i];
            //if (x==y) continue;
            // i -> [x,y] : i+1
            if (sp[i+1]>min(x,y)) add(dp[i+1][min(x,y)], dp[i][x]);
            if (sp[i+1]<max(x,y)) add(dp[i+1][max(x,y)], dp[i][x]);
        }
    }
    int ans = 0;
    loop(x,0,n+1) add(ans, dp[n-1][x]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
2
2 3 1


5
2 6 5 1 4 3



     <---
    ---->
*/