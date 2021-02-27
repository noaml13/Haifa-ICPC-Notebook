#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;


const int MAXN = 1e3+10;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vvi a(n);
    int dp[[MAXN],dp2[MAXN];
    fill(dp, dp+MAXN,0);
    fill(dp2, dp2+MAXN,0);
    loop(i,0,n){
        int t; cin>>t;
        a[i].resize(t+1);
        loop(j,0,t) cin>>a[i][j+1], a[i][j+1]+=a[i][j];
        
    }
    loop(i,0,n){
        int t = a[i].size()-1;
        int v = a[i][t];
        loopr(j,0,k-t+1) chkmax(dp[j+t], dp[j] + v);
    }
    loopr(i,0,n){
        int t = a[i].size()-1;
        int v = a[i][t];
        loopr(j,0,k-t+1) chkmax(dp2[j+t], dp2[j] + v);
    }
    int ans = max(dp2[k], dp[k]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o b & b
3 3
1 1
2 3 4
2 5 6


2 5 10
3 1 2 3
2 1 20


*/