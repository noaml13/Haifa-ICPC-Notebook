/*
ID: licht.n1
PROG: sprinklers2
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD=1e9+7;

int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b,p/2);
    return ((v*v)%MOD)*(p%2?b:1)%MOD;
}
inline void add(int &a, int b){
    a = (a+b)%MOD;
}
int n;
int at(vi& a, int i){
    if (i<0) return a[0];
    if (i>=a.size()) return a.back();
    return a[i];
}
int32_t main() {
    ofstream cout("sprinklers2.out");
    ifstream cin("sprinklers2.in");
    cin>>n;
    int sz = 2*n+10;
    vi two(sz,1), inv(sz,1);
    int invtwo =  pp(2,MOD-2);
    loop(i,1,sz)  two[i]=two[i-1]*2%MOD, inv[i]=inv[i-1]*invtwo%MOD;
    vvb b(n,vb(n));
    loop(i,0,n){
        string s; cin>>s;
        loop(j,0,n) b[i][j] = (s[j]=='W');
    }
    vi sum(n,0); 
    loop(i,0,n) loop(j,0,n) sum[i] += !b[i][j];
    vvi dp(n+1, vi(n+1,0)), pre(n+1, vi(n+1,0));
    dp[0][0]=1;
    loop(j,0,n+1) pre[0][j]=1;
    loop(i,1,n+1){
        //dp[i][0] = dp[i-1][0] * two[n] % MOD;
        loop(j,0,n+1){
            if (j>0) add(pre[i][j], pre[i][j-1]);
            int mult = two[sum[i-1]];
            dp[i][j] = dp[i-1][j] * mult % MOD;
            //pre[i][j] = (j>0?pre[i][j-1]:0) + (j<n || !b[i-1][j]?dp[i][j]:0);
            if ((j==0 || b[i-1][j-1])) {
                if (j<n && !b[i-1][j]) add(pre[i][j], dp[i][j]);
                continue;
            }
            mult = mult*inv[1]%MOD;
            if (i>1) mult = mult*inv[1]%MOD;
            int ad = 0;
            if (j>0) ad = pre[i-1][j-1];
            /*loop(k,0,j){
                int cur = 1;
                if (i>1){
                    if(b[i-2][k]) cur=0;
                    //else cur = cur*inv[1]%MOD;
                }
                add(ad, (dp[i-1][k] * cur)%MOD );
            }
            //cout<<i<<" "<<j<<" "<<ad<<" "<<mult<<endl;*/
            add(dp[i][j], (ad*mult)%MOD);
            if (j<n && !b[i-1][j]) add(pre[i][j], dp[i][j]);
        }
    }
    //loop(i,0,n+1) {loop(j,0,n+1) cout<<dp[i][j]<<" "; cout<<endl;}
    int ans=dp[n][n];
    loop(j,0,n) if (!b[n-1][j]) add(ans, (dp[n][j]*inv[1])%MOD);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ sprinklers2.cpp -o a & a
2
..
..
4
..W.
..WW
WW..
...W
*/
