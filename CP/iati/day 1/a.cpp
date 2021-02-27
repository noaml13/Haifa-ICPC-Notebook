#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e; i++)
#define loopr(i,s,e) for(int i=e-1;i>=s; i--)
#define all(a) a.begin(),a.end()
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using namespace std;
const int INF = 1e9;

const int MAXN = 1e4+10;
int32_t main(){
    ios_base::sync_with_stdio(0);
    int n,k; cin>>n>>k;
    vi l(n), t(n);
    loop(i,0,n) cin>>t[i]>>l[i];
    int dp[2][2][2*MAXN], dp2[2][2*MAXN]; int op = 0;
    loop(i,0,2*n+1) loop(b,0,2) dp[op][b][i] = dp[op^1][b][i] = -INF;
    dp[op][0][n] = 0;
    vb check(n);
    loop(ind,0,n){
        if (check[ind]) continue;
        int cur = ind;
        vi a;
        while(!check[cur]){
            check[cur] = 1;
            a.pb(l[cur]);
            cur = t[cur];
        }
        reverse(all(a));
        int nn = a.size();
        loop(i,0,2*n+1) {
            dp[op][1][i] = -INF;
            loop(b,0,2) dp2[b][i] = dp[op][b][i];
        }
        loop(i,0,nn){ // take last
            loop(j,0,2*n+1){
                chkmax(dp[op^1][0][j], dp[op][1][j] + a[i]);
                if (j+k<=2*n) chkmax(dp[op^1][0][j], dp[op][0][j+k] + a[i]);
                if (j) chkmax(dp[op^1][0][j], dp[op][0][j-1]);
                chkmax(dp[op^1][1][j],dp[op][0][j]);
            }
            //loop(i,0,2*n+1) loop(b,0,2) dp[op][b][i] = dp[op^1][b][i], dp[op^1][b][i] = -INF;
            loop(b,0,2) fill(dp[op][b], dp[op][b]+2*n+1,-INF);
            op = op^1;
        }
        loop(i,0,2*n+1) loop(b,0,2) swap(dp2[b][i], dp[op][b][i]);
        loopr(i,1,nn) swap(a[i], a[i-1]); // cyclic shift 
        loop(i,0,nn){ // don't take last
            loop(j,0,2*n+1){
                chkmax(dp[op^1][0][j], dp[op][1][j] + a[i]);
                if (j+k<=2*n) chkmax(dp[op^1][0][j], dp[op][0][j+k] + a[i]);
                if (j) chkmax(dp[op^1][0][j], dp[op][0][j-1]);
                chkmax(dp[op^1][1][j],dp[op][0][j]);
            }
            loop(b,0,2) fill(dp[op][b], dp[op][b]+2*n+1,-INF);
            op = op^1;
        }
        loop(i,0,2*n+1) chkmax(dp[op][0][i], dp2[0][i]);
    }
    int ans = -INF;
    loop(i,n,2*n+1) chkmax(ans, dp[op][0][i]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
8 2
5 12
6 111
4 101
0 13
1 105
7 14
2 108
3 9


8 3
5 12
6 111
4 101
0 13
1 105
7 14
2 108
3 9


8 2
5 0
6 111
0 101
4 13
1 105
7 14
2 108
3 9





5 2
4 1
3 10
0 0
2 10
1 1


4 2
1 1
3 10
0 0
2 10

*/