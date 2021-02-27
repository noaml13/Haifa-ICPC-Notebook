#include <bits/stdc++.h>
#define ll int64_t
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
const int MOD = 1e9+7;

const int M = 55;
void add(ll &a, ll b){ a = (a+b)%MOD;}
ll pp(ll b, ll p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) % MOD;
}
ll solve1(int n){
    if (n<=3) return 0;
    return (pp(2,n)+MOD-2-2*n)%MOD;
}
ll solve2(int n){
    ll dp[M][3][3][3][3];
    loop(i,0,n+1) loop(a1,0,3) loop(a2,0,3) loop(b1,0,3) loop(b2,0,3) {
        dp[i][a1][a2][b1][b2] = 0;
    }
    dp[0][0][0][0][0] = 1;
    loop(i,0,n){
        loop(a1,0,3) loop(a2,0,3) loop(b1,0,3) loop(b2,0,3) {
            if (!dp[i][a1][a2][b1][b2]) continue;
            loop(x,0,4){
                bool bit1 = x&1, bit2 = x&2;
                int aa1, aa2, bb1, bb2;
                if (bit1){
                    if (b1==0) {
                        if (bit2) bb1 = 2;
                        else bb1 = 1;
                    }
                    else bb1 = 2;
                    aa1 = a1;
                }
                else{
                    if (a1==0) {
                        if (!bit2) aa1 = 2;
                        else aa1 = 1;
                    }
                    else aa1 = 2;
                    bb1 = b1;
                }
                if (bit2){
                    if (b2==0) {
                        if (bit1) bb2 = 2;
                        else bb2 = 1;
                    }
                    else bb2 = 2;
                    aa2 = a2;
                }
                else{
                    if (a2==0) {
                        if (!bit1) aa2 = 2;
                        else aa2 = 1;
                    }
                    else aa2 = 2;
                    bb2 = b2;
                }
                add(dp[i+1][aa1][aa2][bb1][bb2], dp[i][a1][a2][b1][b2]);
            }
        }
    }
    ll ans = 0;
    loop(a1,0,3) loop(a2,0,3) loop(b1,0,3) loop(b2,0,3){
        if (a1==1 || a2==1 || b1==1 || b2==1) continue;
        add(ans, dp[n][a1][a2][b1][b2]);
    }
    return ans;
}
int n,m;
bool mat[M][M];
int row[M], col[M];
bool check(){
    loop(i,0,n) row[i] = 0;
    loop(j,0,m) col[j] = 0;
    loop(i,0,n) loop(j,0,m) row[i]+=mat[i][j], col[j]+=mat[i][j];
    loop(i,0,n) loop(j,0,m){
        int x = row[i], y = col[j];
        if (!mat[i][j]) x = m-x, y = n-y;
        if (x<=1 && y<=1) return 0;
    }
    return 1;
}
int solvebrute(){
    int sz = 1<<(n*m);
    int ans = 0;
    loop(x,0,sz){
        loop(i,0,n){
            loop(j,0,m){
                int ind = i*m+j;
                mat[i][j] = x&(1<<ind);
            }
        }
        ans+=check();
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    if (n<m) swap(n,m);
    if (n*m<20) return cout<<solvebrute()<<endl,0;
    if (m==1) return cout<<solve1(n)<<endl,0;
    if (m==2) return cout<<solve2(n)<<endl,0;
    ll dp[M][M], next[M][M];
    ll choose[2*M][2*M];
    ll p2[2*M];
    loop(i,0,2*M){
        choose[i][0] = choose[i][i] = 1;
        p2[i] = pp(2, i);
        loop(j,1,i) choose[i][j] = (choose[i-1][j-1] + choose[i-1][j])%MOD;
    }
    /*cout<<"CHOOSE: "<<endl;
    loop(i,0,8) { loop(j,0,i+1) cout<<choose[i][j]<<" "; cout<<endl;}*/
    loop(a,0,m+1) loop(b,0,m+1) dp[a][b] = next[a][b] = 0;
    dp[0][0] = 1;
    int sz = 1<<m;
    loop(_,0,n){
        loop(a,0,m+1) loop(b,0,m+1) {
            if (a+b>m || dp[a][b]==0) continue;
            int c = m-a-b;
            loop(a2,0,a+1) loop(b2,0,min(2,b+1)) loop(c2,0,c+1){
                int cnt = a2+b2+c2;

                int aa,bb;
                if (cnt==1){
                    bb=b+a2;
                    aa = a-a2 + c2;
                }
                else{
                    bb=b+a2+c2;
                    aa = a-a2;
                }
                int mult = choose[a][a2] * choose[c][c2] %MOD;
                if (b2){
                    mult = mult * (p2[b]-1) % MOD;
                }
                add(next[aa][bb], dp[a][b] * mult%MOD);
            }
        }
        loop(a,0,m+1) {
            loop(b,0,m+1){
                dp[a][b] = next[a][b], next[a][b] = 0;
            }
        }
    }
    ll ans = 0;
    loop(a,1,m+1) loop(b,0,m+1) add(ans, dp[a][b]);
    ans = ans*2%MOD;
    ans = (pp(2,n*m) +MOD - ans)%MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c2.cpp -o a & a
3 3


2 2


3 3 
*/