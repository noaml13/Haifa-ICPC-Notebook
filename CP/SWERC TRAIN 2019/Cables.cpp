#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

int n, g;
int calc(int x, vb& dp){
    int mind = g -10;
    int maxd = mind + (x+1)*5;
    for(int i = maxd; i>=mind;i--){
        if (dp[i]) return i - mind;
    }
    return -1;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    cin>>n>>g;
    vi d(n);
    loop(i,0,n) cin>>d[i];
    int maxg = g + 5 * (n + 1) + 5;
    vector<vvb> dp(2, vvb(n +1 , vb(maxg, 0)));
    dp[0][0][0] = 1;
    loop(i,0,n){
        loop(x,0,n) loop(l,0,maxg) dp[1][x][l] = 0;
        loop(x,0,n){
            loop(l,0,maxg){
                if (dp[0][x][l]){
                    dp[1][x][l] = 1;
                    if (l+d[i]<maxg) dp[1][x+1][l + d[i]] = 1;
                }
            }
        }
        swap(dp[0],dp[1]);
    }
    long double ans = -1;
    loop(x,1,n+1){
        int v = calc(x, dp[0][x]);
        if (v>=0) chkmax(ans, v/((long double)(x+1)) );
    }
    if (ans<0) cout<<"impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}
