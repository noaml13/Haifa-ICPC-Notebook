#include <bits/stdc++.h>
#define ii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    string s; cin>>s;
    vvi divs(n+1);
    loop(i,1,n+1) loop(j,1,i) if(i%j==0) divs[i].pb(j);
    vvi dp(n+1, vi(n+1,INF));
    vector<vector<map<int, bool>>> isP(n, vector<map<int, bool>>(n));
    loop(i,0,n) dp[i][i] = 1, isP[i][i][1] = 1;
    loop(k,1,n){
        int sz = k+1;
        loop(i,0,n-k){
            int j = i+k;
            isP[i][j][sz] = 1;
            chkmin(dp[i][j], dp[i+1][j] + 1);
            chkmin(dp[i][j], dp[i][j-1] + 1);
            for(int d:divs[sz]){
                if (2*d==sz){
                    isP[i][j][d] = 1;
                    loop(off,0,d) if(s[i+off]!=s[i+d+off]){
                        isP[i][j][d] = 0;
                        break;
                    }
                }
                else{
                    isP[i][j][d] = isP[i][j-d][d] && isP[i+d][j][d];
                }
                // if (k==1 && i==0) cout<<"D: "<<d<<" "<<isP[i][j][d]<<endl;
                if (isP[i][j][d]){
                    chkmin(dp[i][j], dp[i][i+d-1]);
                }
            }
            loop(k,i,j){
                chkmin(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
/*
color a
cls
g++ k.cpp -o a & a
22
aaabaaabccdaaabaaabccd

11
aaabaaabccd

4
aaba

*/