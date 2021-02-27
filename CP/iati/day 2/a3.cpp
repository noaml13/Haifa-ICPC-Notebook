#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define pb push_back
#define loop(i,s,e) for(int i=(s); i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1; i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using namespace std;
const int INF = 1e18, MOD = 1e9+7;
void add(int &a, int b){ a = (a+b)%MOD;}


const int N = 1e5+10;
int n;
vi a;
int dpp[2][N];
int op = 0;
#define dp dpp[op]
#define next dpp[op^1]
int val(int x, int y){
    return (a[y]-a[x])*(y-x-1);
}
void solve(int l, int r, int optl, int optr){
    if (l>=r) return ;
    int i =(l+r)/2;
    int opt = optl, mini = dp[optl] + val(optl, i);
    loop(j,optl+1, optr+1){
        if (j>=i) break;
        int v = dp[j] + val(j,i);
        if (v<mini){
            mini = v;
            opt = j;
        }
    }
    next[i] = mini;
    solve(l, i, optl, opt);
    solve(i+1, r, opt, optr);
}
int32_t main(){
    // O(k * n * logn)
    ios_base::sync_with_stdio(0);
    int k; cin>>n>>k;
    a.resize(n+1); loop(i,0,n) cin>>a[i+1];
    loop(i,0,n) a[i+1]+=a[i];
    if (k==n) return cout<<0<<endl,0;
    int ans = 0;
    loop(i,0,n+1) dp[i] = INF;
    dp[0] = 0;
    loop(i,0,k){
        // O(n * logn)
        fill(next, next+n+1, INF);
        next[0] = 0;
        solve(1,n+1,0,n);
        op = !op;
    }
    cout<<dp[n]<<endl;
    return 0;
}
/*
color a
cls
g++ a3.cpp -o a3 & a3
8 4
8 1 2 3 9 1 9 1

g++ a3.cpp -o a3 & a3 < in.txt
*/