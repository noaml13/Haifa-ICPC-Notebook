#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define pb push_back
#define loop(i,s,e) for(int i=(s); i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1; i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using namespace std;
const int INF = 1e18, MOD = 1e9+7;

const int N = 1e5+10;
int n;
vi a;
ii dp[N];
ii val(int x, int y, int c){
    return {dp[x].x + (a[y]-a[x])*(y-x-1) + c, dp[x].y+1};
}
ii solve(int c){
    dp[0] = {0,0};
    vii st(1,{0,1}); // (j,i)
    int ind = 0;
    loop(j,1,n+1){
        {
            while(ind+1<st.size() && st[ind+1].y<=j) ind++;
            int j2 = st[ind].x;
            dp[j] = val(j2,j,c);
        }
        while(st.size()){
            int i = st.back().y, j2 = st.back().x;
            if (j>=i) break;
            if (val(j,i,c) >= val(j2,i,c)) break;
            st.pop_back();
        }
        {
            int j2 = st.back().x;
            int l = max(st.back().y, j+1), r = n+1, mid, ans = -1;
            while(l<r){
                mid = (l+r)/2;
                if (val(j,mid,c) < val(j2,mid,c)) ans = r = mid;
                else l = mid + 1;
            }
            if (ans!=-1) st.pb({j, ans});
        }
    }
    return dp[n];
}
ii solve2(int c){
    dp[0] = {0,0};
    loop(i,1,n+1){
        dp[i] = {INF,INF};
        loop(j,0,i){
            chkmin(dp[i], val(j,i,c));
        }
    }
    return dp[n];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    int k; cin>>n>>k;
    a.resize(n+1); loop(i,0,n) cin>>a[i+1];
    loop(i,0,n) a[i+1]+=a[i];
    if (k==n) return cout<<0<<endl,0;
    if (k==1) return cout<<a[n]*(n-1)<<endl,0;
    int l = 0, r = 1e14, mid, ans = r;
    while(l<r){
        mid = (l+r)/2;
        ii res = solve(mid);
        if (res.y>k) l = mid + 1;
        else ans = r = mid;
    }
    ii res = solve(ans);
    ans = res.x - k * ans;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
10 8
1 1 1 1 1 1 1 1 1 1


8 4
8 1 2 3 9 1 9 1
*/ 