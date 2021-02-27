/*
ID: licht.n1
PROG: money
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
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
const int INF = 1e9;


int32_t main() {
    ofstream cout("money.out");
    ifstream cin("money.in");
    int n,l; cin>>n>>l;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    vvi dp(n+1,vi(l+1,0));
    dp[0][0] = 1;
    loop(i,0,n){
        loop(j,0,l+1) {
            dp[i+1][j]+=dp[i][j];
            if (a[i]+j<=l) dp[i][a[i]+j]+=dp[i][j];
        }
    }
    cout<<dp[n][l]<<endl;
    return 0;
}
/*
color a
cls
g++ money.cpp -o a & a
3 10
1 2 5
*/
