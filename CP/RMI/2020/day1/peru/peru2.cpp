#include "peru.h"
#include <bits/stdc++.h>
#define ll int64_t
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);++i)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);--i)
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max(a,b)
using namespace std;
const ll MOD = 1e9+7, INF = 1e18;

struct SEG{
    int sz;
    vector<ll> a;
    SEG(int n){
        for(sz=1;sz<n; sz*=2);
        a.resize(2*sz, INF);
    }
    void update(int i, ll x){
        i+=sz;
        chkmin(a[i], x);
        for(i/=2; i;i/=2) a[i] = min(a[2*i], a[2*i+1]);
    }
    ll query(int l, int r){
        ll res = INF;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmin(res, a[l++]);
            if (r%2==0) chkmin(res, a[r--]);
        }
        return res;
    }
};

int solve(int n, int k, int* v){
    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    deque<pair<int, pair<ll, ll>>> maxi; 
    multiset<ll> vals;
    SEG seg(n+1);
    loop(i,0,n){
        seg.update(i, dp[i]);
        ll x = dp[i], y = v[i];
        while(maxi.size() && maxi.back().y.y <= y){
            if (maxi.size()>1){
                chkmin(x, maxi.back().y.x);
                vals.erase(vals.find(maxi.back().y.x+maxi.back().y.y));
            }
            else{
                chkmin(x, seg.query(max(i-k+1,0), maxi.back().x));
            }
            maxi.pop_back();
        }
        maxi.pb({i, {x,y}});
        if (maxi.size()>1) vals.insert(x+y);
        if (maxi[0].x+k==i){ // pop back
            maxi.pop_front();
            //remove from vals
            auto v = maxi[0];
            vals.erase(vals.find(v.y.x+v.y.y));
        }
        
        /*cout<<"MAXI: "<<endl;
        for(auto p:maxi) cout<<p.x<<" "<<p.y.x<<" "<<p.y.y<<endl;
        for(auto v:vals) cout<<v<<endl;
        cout<<endl;*/
        if (vals.size()) chkmin(dp[i+1], *vals.begin());
        chkmin(dp[i+1], seg.query(max(i-k+1,0), maxi[0].x) + maxi[0].y.y);
    }
    //loop(i,0,n+1) cout<<dp[i]<<" "; cout<<endl;
    ll ans = 0, mult = 1;
    for(int i=n; i; i--){
        ans = (ans + (dp[i]%MOD)*mult%MOD)%MOD;
        mult = (mult*23)%MOD;
    }
    return int(ans);
}
/*
color
cls
g++ peru.cpp peru.h grader.cpp -o a & a
8 3
3 2 9 8 7 11 3 4
*/
