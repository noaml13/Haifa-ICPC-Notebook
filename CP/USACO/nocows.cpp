/*
ID: licht.n1
PROG: nocows
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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
const int INF = 1e9, MOD = 9901;


int main() {
    ofstream cout("nocows.out");
    ifstream cin("nocows.in");
    int n,k; cin>>n>>k;
    vvi dp(k+1,vi(n+1,0));
    vvi tot(k+1,vi(n+1,0));
    dp[1][0] = dp[1][1] = 1;
    tot[1][0] = tot[1][1] = 1;
    loop(i,2,k+1){
        loop(j,0,n+1){
            dp[i][j] = 0;
            loop(l,1,j-1){
                dp[i][j]=(dp[i][j] +  dp[i-1][l] * dp[i-1][j-l-1])%MOD;
                dp[i][j]=(dp[i][j] +  2 * dp[i-1][l] * tot[i-2][j-l-1])%MOD;
            }
            //if (i==2 && j==3) cout<<dp[i][j]<<endl;
            //dp[i][j] = (dp[i][j])%MOD;
        }
        loop(j,0,n+1) tot[i][j]=(tot[i-1][j]+dp[i][j])%MOD;
    }
    //cout<<dp[2][3]<<endl;
    cout<<dp[k][n]<<endl;
    return 0;
}
/*
color a
cls
g++ nocows.cpp -o a & a
5 3
*/

