#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vi>
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
int dpp[2][N], optt[2][N];
int op = 0;
#define dp dpp[op]
#define next dpp[op^1]
#define opt optt[op]
#define nextopt optt[op^1]
int val(int x, int y){
    return (a[y]-a[x])*(y-x-1);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    int k; cin>>n>>k;
    a.resize(n+1); loop(i,0,n) cin>>a[i+1];
    loop(i,0,n) a[i+1]+=a[i];
    if (k==n) return cout<<0<<endl,0;
    int ans = 0;
    //loop(i,0,n+1) dp[i] = 0;
    //vvi dp(n+1, vi(n+1));
    //vvi opt(n+1, vi(n+1));
    //loop(i,0,n+1) dp[i][0] = INF;
    loop(i,0,n+1) dp[i] = 0, opt[i] = max(int(0),i-1);
    loop(dx,1,n+1){
        int sz = n-dx+1;
        fill(next, next+sz, INF);
        fill(nextopt, nextopt+sz, 0);
        loop(x,1,n-dx+1){
            int i = x+dx;
            if (i>n) break;
            dp[i][x] = INF;
            int oo = 0;
            loop(j,opt[i-1][x],opt[i][x+1]+1){
                int v = dp[j][x-1] + val(j,i);
                if (v<dp[i][x]){
                    dp[i][x] = v;
                    opt[i][x] = j;
                }
            }
            if (i==n && x==k) return cout<<dp[n][k]<<endl,0;
        }
    }
    cout<<dp[n][k]<<endl;
    /*loop(kk,0,n-k){
        int sz = n+1-kk;
        fill(next, next+sz, INF);
        loop(i,kk,n){
            
        }
        op = !op;
    }*/
    return 0;
}
/*
color a
cls
g++ a4.cpp -o a4 & a4
8 1
8 1 2 3 9 1 9 1
*/