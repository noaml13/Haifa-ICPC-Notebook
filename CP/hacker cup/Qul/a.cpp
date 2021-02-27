#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;


int solve(int t){
    int n; cin>>n;
    string a,b; cin>>a>>b;
    vvb ans(n, vb(n));
    loop(i,0,n){
        loop(j,i-1,i+2){
            if (j<0 || j>=n) continue;
            if (i==j) ans[i][j] = 1;
            else{
                ans[i][j] = (a[j]=='Y' && b[i]=='Y');
            }
        }
    }
    loop(k,2,n){
        loop(i,0,n){
            int j = i+k;
            if (j<n){
                ans[i][j] = ans[i][j-1] && ans[j-1][j];
            }
            j = i-k;
            if (j>=0){
                ans[i][j] = ans[i][j+1] && ans[j+1][j];
            }
        }
    }
    cout<<"Case #"<<t<<":"<<endl;
    loop(i,0,n) { loop(j,0,n) cout<<(ans[i][j]?"Y":"N"); cout<<endl;}
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve(i+1);
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a < in.txt > out.txt
5
2
YY
YY
2
NY
YY
2
NN
YY
5
YNNYY
YYYNY
10
NYYYNNYYYY
YYNYYNYYNY

*/