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

pair<int, ii> solve(vii& a){
    int n = a.size();
    ii last = a[0];
    int sz = 0;
    loop(i,1,n) if(last.y<a[i].y) {
        sz+=last.y * abs(a[i].x - last.x);
        last = a[i];
    }
    return {sz, last};
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii a(n);
    int maxi = 0;
    loop(i,0,n) cin>>a[i].x>>a[i].y, a[i].y++, chkmax(maxi, a[i].y);
    sort(all(a));
    vii aa = {a[0]};
    loop(i,1,n){
        if (aa.back().x == a[i].x) aa.back().y = a[i].y;
        else aa.pb(a[i]);
    }
    a = aa;
    n = a.size();
    int minx = a.begin()->x, maxx = a.back().x;
    auto sz1 = solve(a);
    reverse(all(a));
    auto sz2 = solve(a);
    int sz = sz1.x + sz2.x;
    ii p1 = sz1.y, p2 = sz2.y;
    sz += p1.y * (p2.x - p1.x + 1);
    // cout<<sz1.x<<" "<<sz2.x<<endl;
    int cir = (maxx - minx + 3) + 2 * (maxi+1);
    cout<<cir<<" "<<cir-2<<" "<<sz<<endl;
    return 0;
}
/*
color a
cls
g++ j.cpp -o a & a
4
-1 2
2 4
4 1
4 4


*/