#pragma GCC taget ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 4e18;

struct Seg{
    int sz;
    vi a;
    Seg(int n){
        for(sz=2;sz<n;sz*=2);
        a.resize(2*sz, 0);
    }
    void add(int i){
        a[i+=sz]++;
        for(i/=2;i;i/=2) a[i] = a[2*i] + a[2*i+1];
    }
    int get(int l, int r){
        int ans = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2==1) ans += a[l++];
            if (r%2==0) ans += a[r--];
        }
        return ans;
    }
};
int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,c,r; cin>>n>>c>>r;
    vi a(n); 
    vii sorted(n);
    loop(i,0,n) cin>>a[i], sorted[i] = {abs(a[i])+1, i};
    sort(all(sorted));
    reverse(all(sorted)); 
    sorted.pb({0, -1});
    int ans = c * sorted[0].x;
    // cout<<"ANS: "<<ans<<endl;
    int rem = 0;
    set<int> inds;
    Seg seg(n);
    loop(i,0,n){
        if (sorted[i].x==1) break;
        int j = sorted[i].y;
        auto it = inds.lower_bound(j);
        if (it!=inds.end()){
            int k = *it;
            //cout<<"HI1 "<<j<<" "<<k<<endl;
            int dist = k-j-1;// - seg.get(j+1, k-1);
            if ((dist%2)^(a[k]*a[j]>0)){
                //inds.erase(it);
                //seg.add(k);
                rem++;
            }
        }
        it = inds.lower_bound(j);
        if (it!=inds.begin()){
            it = prev(it);
            int k = *it;
            //cout<<"HI2 "<<j<<" "<<k<<endl;
            int dist = j-k-1;// - seg.get(k+1, j-1);
            if ((dist%2)^(a[k]*a[j]>0)){
                //inds.erase(it);
                //seg.add(k);
                rem++;
            }
        }
        inds.insert(j);
        int v = c * sorted[i+1].x + r * rem;
        //cout<<"S: "<<sorted[i+1].x<<" "<<v<<" "<<rem<<endl;
        chkmin(ans, v);
    }
    int nn = n;
    vi aa;
    loop(i,0,n) if (a[i]) aa.pb(a[i]);
    a = aa;
    n = a.size();
    vii dp(n+1, {0,0});
    loop(i,0,n){
        dp[i+1].x = dp[i].x;
        dp[i+1].y = dp[i].y;
        if (a[i]>0) chkmax(dp[i+1].x,dp[i].y + 1);
        else chkmax(dp[i+1].y, dp[i].x + 1);
    }
    chkmin(ans, (nn - max(dp[n].x, dp[n].y))*r);
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ j.cpp -o a & a
6 100 33
5 -13 0 0 -12 0


4 10 50
8 8 2 -2




*/