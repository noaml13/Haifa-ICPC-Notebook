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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int MOD = 998244353;


void solve(){
    int n; cin>>n;
    int o=-1,e=-1;
    int cnt = n-1;
    loop(i,0,2*n){
        int a; cin>>a;
        if (a%2){
            if (o==-1) o=i;
            else {
                if (--cnt>=0) cout<<i+1<<" "<<o+1<<endl;
                o=-1;
            }
        }
        else{
            if (e==-1) e=i;
            else {
                if (--cnt>=0) cout<<i+1<<" "<<e+1<<endl;
                e=-1;
            }
        }
    }
}
int32_t main(){
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
3
3
1 2 3 4 5 6
2
5 7 9 10
5
1 3 3 4 5 90 100 101 2 3

*/