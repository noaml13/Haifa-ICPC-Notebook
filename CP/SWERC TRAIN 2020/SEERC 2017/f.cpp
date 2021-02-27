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

int n;
vii c;
string a,b;
int ans = INF;
void solve(int sz){
    int sum = 0, res = 0;
    loop(i,0,n) {
        int ind = c[i].y;
        if(a[ind]) sum+=c[i].x;
    }
    string cur = a;
    // cout<<"SUM: "<<sum<<endl;
    loop(i,0,n){
        int ind = c[i].y;
        if ((i<sz && a[ind] && b[ind]) || (a[ind] && !b[ind])){
            cur[ind] = 0;
            sum -= c[i].x;
            res += sum;
            // cout<<"IND: "<<ind<<endl;
        }
    }
    // cout<<"RES: "<<res<<endl;
    loopr(i,0,n){
        int ind = c[i].y;
        if (!cur[ind] && b[ind]){
            sum += c[i].x;
            res += sum;
            cur[ind] = 1;
        }
    }
    // cout<<"SZ: "<<sz<<" "<<(cur == b)<<endl;
    chkmin(ans, res);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    c.resize(n); loop(i,0,n) cin>>c[i].x, c[i].y = i;
    cin>>a>>b;
    loop(i,0,n) a[i]-='0', b[i]-='0';
    sort(all(c));
    reverse(all(c));
    solve(0);
    loop(i,0,n) {
        int ind = c[i].y;
        if (a[ind] && b[ind]) solve(i+1);
    }
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
5
5 2 6 1 5
01110
10011 

5
100 1 1 1 1
10000
11111

*/