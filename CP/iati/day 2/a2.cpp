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


const int N = 1e3+10;
int n;
vi a;
int dp[N][N];
int32_t main(){
    ios_base::sync_with_stdio(0);
    int k; cin>>n>>k;
    a.resize(n+1); loop(i,0,n) cin>>a[i+1];
    loop(i,0,n) a[i+1]+=a[i];
    loop(i,0,n+1) loop(x,0,k+1) dp[i][x] = INF;
    dp[0][0] = 0;
    loop(i,1,n+1){
        loop(x,1,k+1){
            loop(j,0,i){
                int v = (a[i] - a[j])*(i-j-1) + dp[j][x-1];
                chkmin(dp[i][x], v);
            }
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
/*
color a
cls
g++ a2.cpp -o a2 & a2
8 4
8 1 2 3 9 1 9 1
*/