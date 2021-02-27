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
const int INF = 1e9, MOD = 1e9 + 7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, c; cin>>n>>c;
    vi d(n), s(n);
    loop(i,0,n) cin>>d[i]>>s[i], d[i] = max(d[i], s[i]) - s[i];
    vector<pair<ii, int>> vec(n);
    loop(i,0,n) vec[i] = {{d[i], s[i]}, i};
    /*sort(all(vec), [&](pair<ii, int> a, pair<ii, int> b){
        return ii(a.x.x, -a.x.y) > ii(b.x.x, -b.x.y);
    }); */
    sort(all(vec)); reverse(all(vec));
    vvi dp(n+1, vi(c+1, 0)), opt(n+1, vi(c+1, 0));
    loop(i,0,n){
        int d = vec[i].x.x, s = vec[i].x.y;
        dp[i+1] = dp[i];
        loop(x,0,c+1){
            if (x+s+d<=c && dp[i+1][x+s] < dp[i][x]+1){
                dp[i+1][x+s] = dp[i][x]+1;
                opt[i+1][x+s] = 1;
            }
        }
    }
    vi ans;
    int cur = c, i = n;
    loop(x,0,c) if (dp[n][cur] < dp[n][x]) cur = x;
    while(i) if (opt[i--][cur]) ans.pb(vec[i].y), cur -= vec[i].x.y;
    reverse(all(ans));
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ i.cpp -o a & a
3 10
2 1
5 3
6 5



2 100
1 99
99 1


3 10
10 1

*/