#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 998244353;

void add(int &a, int b){
    a = (a+b) % MOD;
}
void sub(int &a, int b){
    a = (a-b)%MOD;
    if (a<0) a+=MOD;
}
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b, p/2);
    return (v*v)%MOD * (p%2?b:1) %MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int m = 0;
    vi a(n); loop(i,0,n) cin>>a[i], m+=a[i];
    vi f(m+1,1);
    loop(i,1,m){
        int v = (m * (n-1) - (m-i) * (n-2))%MOD;
        if (v<0) v+=MOD;
        v = (v * f[i])%MOD;
        int v2 = i * (n-1) % MOD;
        v = v * (f[i-1] + 1) %MOD;
        sub(v, v2);
        f[i+1] = v * pp(m-i,MOD-2) % MOD;
    }
    //cout<<"F: "; loop(i,0,m) cout<<f[i]<<" "; cout<<endl;
    int ans = 0;
    loop(i,0,n) add(ans, f[a[i]]);
    sub(ans, f[m]);
    sub(ans, (n-1)*f[0] % MOD);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
2
1 1


*/