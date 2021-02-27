#include <bits/stdc++.h>
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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD=1e9+7;



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,s; cin>>n>>s;
    vvi dp(n+1, vi(s+1,0));
    vvi prev(n+1, vi(s+1,0));
    vi a(n+1); loop(i,1,n+1) cin>>a[i];
    loop(i,0,n+1){
        loop(x,0,s){
            loop(j,0,i){
                if (a[j]<=a[i] && a[i]+x<=s) {
                    if (dp[i][x + a[i]] < dp[j][x]+1){
                        dp[i][x + a[i]] = dp[j][x]+1;
                        prev[i][x+a[i]] = j;
                    }
                }
            }
        }
    }
    int ans = 0; ii pos = {0,0};
    loop(i,1,n+1){
        if (ans < dp[i][s]){
            ans = dp[i][s];
            pos = {i, s};
        }
    }
    cout<<ans<<endl;
    vb res(n);
    while(pos.x!=0){
        res[pos.x-1] = 1;
        int t = pos.y;
        pos.y -= a[pos.x];
        pos.x = prev[pos.x][t];
    }
    loop(i,0,n) cout<<res[i]<<" "; cout<<endl;
    return 0;
}
/*
color a
cls
g++ Drinking.cpp -o a & a
5 11
1 3 2 4 5

5 5
1 3 2 4 5
*/