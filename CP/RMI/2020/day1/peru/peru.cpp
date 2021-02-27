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
        a.resize(2*sz);
    }
    void update(int i, ll x){
        i+=sz;
        a[i] = x;
        for(i/=2; i;i/=2) a[i] = max(a[2*i], a[2*i+1]);
    }
    ll query(int l, int r){
        ll res = INF;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res, a[l++]);
            if (r%2==0) chkmax(res, a[r--]);
        }
        return res;
    }
};

int solve(int n, int k, int* v){
    vector<ll> dp(n+1, INF);
    deque<ii> dec;
    dp[0] = 0; 
    int l = 0;
    loop(i,0,n){
        while(dec.size() && dec.back().y <= v[i]) dec.pop_back();
        dec.push_back({i, v[i]});
        chkmax(l, i-k+1);
        if (dec.front().x<l) {
            chkmax(l, dec[0].x + 1);
            dec.pop_front();
        }
        while(dec.size()>1){
            int j2 = dec[0].x+1;
            if (dp[l] + dec[0].y <= dp[j2] + dec[1].y) break;
            l = j2;
            dec.pop_front();
        }
        dp[i+1] = dp[l] + dec[0].y;
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
5 3
1 10 1 9 2

8 3
3 2 9 8 7 11 3 4
*/
