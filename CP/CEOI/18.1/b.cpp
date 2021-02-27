#include <bits/stdc++.h>
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
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;


int binary(vi& vec, int v){
    int l=0, r=vec.size(), mid, ans=-1;
    while(l<r){
        mid = (l+r) / 2;
        if (vec[mid]>=v) r = mid;
        else l = mid + 1, ans = mid;
    }
    return ans;
}
int solve(int n, int x, vi& a){ //suffix
    vi dp(n+1, INF);
    dp[0] = -INF;
    vi v(n);
    loop(i,0,n){
        int ind = binary(dp, a[i]+x);
        v[i] = ind;
        ind = binary(dp, a[i]);
        chkmin(dp[ind+1], a[i]);
    }
    fill(all(dp), INF); dp[0] = -INF;
    reverse(all(a)); reverse(all(v));
    loop(i,0,n) a[i]=-a[i];
    int res = 0;
    loop(i,0,n){
        int ind = binary(dp, a[i]);
        chkmin(dp[ind+1], a[i]);
        chkmax(res, ind+1 + v[i]);
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,x; cin>>n>>x;
    vi a(n); loop(i,0,n) cin>>a[i];
    int ans = solve(n,x,a);
    chkmax(ans, solve(n,x,a));
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
8 10
7 3 5 12 2 7 3 4

*/



