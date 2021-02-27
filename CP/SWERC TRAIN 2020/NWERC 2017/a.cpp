#include <bits/stdc++.h>
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
const int INF = 2e9 + 10, MOD = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi b;
    loop(i,0,n){
        b.pb(a[i]);
        while(i+1<n && a[i]==a[i+1]) i++;
    }
    int m = n;
    a = b;
    n = a.size();
    map<int, int> conv;
    for(int x:a) conv[x];
    int cnt = 0;
    for(auto &p:conv) p.y = cnt++;
    for(auto &x:a) x = conv[x];
    // loop(i,0,n) cout<<a[i]<<" "; cout<<endl;
    vvi inds(cnt);
    vi back(n);
    loop(i,0,n) {
        back[i] = inds[a[i]].size();
        inds[a[i]].pb(i);
    }
    vi dp(n);
    // for(int i:ind[cnt-1]) dp[i] = 0;
    loopr(h,0,cnt-1){
        if (inds[h].size()==1){ 
            int i = inds[h][0];
            if (i+1<n && a[i+1]==h+1){
                // cout<<"HI: "<<endl;
                dp[i] = dp[i+1] + 1;
                // cout<<"BI: "<<endl;
            }
            for(int j:inds[h+1]) chkmax(dp[i], dp[j]);
        }
        else{
            vi vals;
            for(int i:inds[h+1]) {
                vals.pb(dp[i]);
                if (i>0 && a[i-1]==h){
                    vals.back()++;
                }
            }
            int r = vals.size();
            vi pref = vals, suf = vals;
            loop(i,1,r) chkmax(pref[i], pref[i-1]);
            loopr(i,0,r-1) chkmax(suf[i], suf[i+1]);
            for(int i:inds[h]){
                if (i+1<n && a[i+1]==h+1){
                    int j = back[i+1];
                    dp[i] = dp[i+1];
                    if (j>0) chkmax(dp[i], pref[j-1]);
                    if (j+1<r) chkmax(dp[i], suf[j+1]);
                }
                else dp[i] = pref[r-1];
            }
        }
    }
    int ans = 0;
    for(int i:inds[0]) chkmax(ans, dp[i]);
    cout << n - ans - 1 << endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
11
3 6 12 7 7 7 7 8 10 5 5


6
2 3 4 2 3 5

10
1 2 3 1 2 3 4 1 2 3

12
1 2 2 3 3 1 2 3 4 1 2 3

5
1 2 3 2 2

4
1 2 3 2




3
5000000 5500000 7000000



*/