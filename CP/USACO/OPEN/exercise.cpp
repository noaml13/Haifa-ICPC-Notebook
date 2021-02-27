/*
ID: licht.n1
PROG: exercise
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
const int INF = 1e9;

int n,mod;
void add(int &a, int b){
    a = (a+b)%mod;
}
int32_t main() {
    ofstream cout("exercise.out");
    ifstream cin("exercise.in");
    cin>>n>>mod;
    int sz=n+1;
    vb check(sz,1);
    vi p;
    loop(i,2,sz){
        if (check[i]){
            p.pb(i);
            for(int j=i*i;j<sz;j+=i) check[j]=0;
        }
    }
    int m = p.size();
    //loop(i,0,m) cout<<p[i]<<" "; cout<<endl;
    vvi dp(m+1, vi(n+1,0)); loop(i,0,n+1) dp[0][i]=1;
    loop(i,0,m){
        loop(j,0,n+1){
            add(dp[i+1][j],dp[i][j]);
            for(int cur=p[i];j+cur<=n;cur*=p[i]) add(dp[i+1][j+cur], (dp[i][j] * cur)%mod);
            //cout<<i<<" "<<j<<endl;
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}
/*
color a
cls
g++ exercise.cpp -o a & a
10 1000000007
*/
