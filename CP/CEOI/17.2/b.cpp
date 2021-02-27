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
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, P = 1e9+7, MOD = 1e9+9;

int v(vi& h, vi& p, int a, int n){
    return (h[a+n]+MOD- (h[a]*p[n])%MOD)%MOD;
}
bool eq(vi& h, vi& p, int a, int b, int n){
    return v(h,p,a,n) == v(h,p,b,n);
}
int solve(){
    string s; cin>>s; 
    int n = s.size();
    vi h(n+1,0), p(n+1,1);
    loop(i,0,n) h[i+1]=(h[i]*P + (s[i]-'a')) % MOD, p[i+1]=p[i]*P%MOD;
    int i = 0, j=n-1, cnt=1,res=0;
    //cout<<eq(h,p,0,4,2)<<endl;
    while(i+cnt-1<j){
        if (eq(h, p, i, j, cnt)){
            //cout<<"I: "<<i<<" "<<cnt<<endl;
            i+=cnt;
            cnt = 0;
            res+=2;
        }
        cnt++;
        j--;
    }
    if (2*i!=n) res++;
    cout<<res<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
5
bonobo
deleted
racecar
racecars
abcabc

*/

