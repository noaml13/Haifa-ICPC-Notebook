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
const int MAXN = 360;
const int MOD =  1e9 +7;
bool flag =  1;
int mpow(int b, int e){
    if (e==0) return 1;
    int v = mpow(b,e/2);
    return (((v*v)%MOD)*(e%2?b:1))%MOD;
}
void solve(int n){
    vvi ch(MAXN,vi(MAXN,0));
    loop(i,0,MAXN){
        ch[i][0] = ch[i][i] = 1;
        loop(j,1,i) ch[i][j] = (ch[i-1][j-1] + ch[i-1][j]) %MOD;
    }
    vvvi dp(n+1,vvi(n+1,vi(2,0)));
    dp[0][n][0] = 1;
    int ans = 0;
    loop(x,0,n){
        loop(left,0,n+1) loop(b,0,2){
            int v = dp[x][left][b];
            if (v==0) continue;
            if (flag && b){
                ans+=(v*mpow(n-x,left))%MOD;
                ans%=MOD;
                continue;
            }
            loop(j,0,left+1){
                int nextB = (x+1==j);
                if (b) nextB  = b;
                dp[x+1][left-j][nextB] += ((v * ch[left][j])%MOD);
                dp[x+1][left-j][nextB]%=MOD;    
            }
        }
    }
    //loop(i,0,4)  cout<<dp[3][i][1]<<endl;
    cout<<(dp[n][0][1]+ans)%MOD<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n;cin>>n;
    solve(n);
    return 0;
}


