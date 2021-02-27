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
const int INF = 4e18, MOD = 1e9 + 7;

void add(int &a, int b){ a = (a+b)%MOD; }
int n, m;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vi a(n+1);
    loop(i,0,m){
        int x; cin>>x;
        a[x]++;
    }
    vi pref(n+1);
    loop(i,0,n) pref[i+1] = a[i+1] + pref[i];
    loop(i,0,n+1) pref[i]+=n-i;
    vi vals(m+1+n, 0);
    vi dp(n+1, 0);
    // loop(i,0,n+1) cout<<pref[i]<<" "; cout<<endl;
    dp[0] = 1;
    vals[pref[0]] = dp[0];
    loop(i,1,n+1){
        if (!a[i]) add(dp[i], dp[i-1]);
        /*int sum = 0;
        loopr(j,1,i+1){
            sum += a[j];
            if (sum == i-j+1) {
                add(dp[i], dp[j-1]);
                break;
            }
        }*/
        add(dp[i], vals[pref[i]]);
        vals[pref[i]] = dp[i];
    }
    // cout << dp[1] << endl;
    cout << dp[n] << endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o b & b
10 8
2 2 3 5 6 6 9 9 


5 4
2 2 4 4 



*/