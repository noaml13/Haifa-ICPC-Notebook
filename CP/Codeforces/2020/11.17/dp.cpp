#include <bits/stdc++.h>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    vector<int> h(n), s(n);
    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=0; i<n; i++) cin>>s[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    loop(i,1,n+1){
        loop(j,0,x+1){
            dp[i][j] = dp[i-1][j];
            if (j>=h[i-1]) dp[i][j] = max(dp[i][j], dp[i-1][j - h[i-1]] + s[i-1]);
        }
    }
    cout<<dp[n][x]<<endl;
    ll x; //
    return 0;
}
/*
color a
cls
g++ dp.cpp -o b & b
4 10
4 8 5 3
5 12 8 1

*/