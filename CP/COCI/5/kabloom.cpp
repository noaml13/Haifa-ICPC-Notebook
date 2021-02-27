#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
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
const int INF = 1e18;

int eq(char a, char b){
    if (a=='R' && b=='R') return 50;
    if (a=='R') a=b;
    if (b=='R') b=a;
    if (a==b){
        if (a>='0' && a<='9') return a-'0';
        if (a=="A") return 20;
        return 15;
    }
    return INF;
}

bool solve(){
    int n; cin>>n;
    if (n==0) return false;
    vector<char> a,b;
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    vvi dp(n+1,vi(n+1,0));
    loop(i,0,n){
        loop(j,0,n){
            int v = eq(a[i],b[j]);
            chkmax(dp[i+1][j+1],dp[i][j]+v);
            chkmax(dp[i][j+1],dp[i][j]);
            chkmax(dp[i+1][j],dp[i][j]);
        }
    }
    cout<<dp[n][n]<<endl;
    return true;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    while(solve()){}
    return 0;
}


