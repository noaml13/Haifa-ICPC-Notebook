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

ii operator-(ii a, ii b){
    return {a.x-b.x, a.y-b.y};
}
int operator*(ii a, ii b){
    return a.x * b.y - a.y * b.x;
}
int dot(ii a, ii b){
    return a.x*b.x + a.y*b.y;
}
int norm(ii a){
    return a.x*a.x + a.y*a.y;
}
typedef pair<double, double> dd;
dd operator*(double d, ii a){
    return {d*a.x, d * a.y};
}
dd operator+(ii a, dd b){
    return {a.x+b.x, a.y+b.y};
}
dd operator-(dd a, dd b){
    return {a.x-b.x, a.y-b.y};
}
double operator*(dd a, dd b){
    return a.x * b.y - a.y * b.x;
}
double AR(dd a, dd b, dd c){
    dd v1 = b - a, v2 = c - a;
    return abs(v1 * v2) / 2.0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    vii a(3);
    loop(i,0,3) cin >> a[i].x >> a[i].y;
    vvi d(3);
    loop(i,0,3){
        int n; cin>>n;
        d[i].resize(n);
        loop(j,0,n) cin>>d[i][j];
        int x = d[i].back();
        d[i].resize(1);
        d[i].pb(x);
    }
    vector<dd> ps;
    loop(i,0,3){
        ii x = a[i], y = a[(i+1)%3];
        ii v = y-x;
        double div = sqrt(norm(v));
        for(auto ds:d[i]) ps.pb(x + (ds / div) * v);
    }
    // for(auto p:ps) cout<<p.x<<" "<<p.y<<endl;
    int n = ps.size();
    double ans = 0;
    loop(i,0,n) loop(j,0,i) loop(k,0,j){
        ans = max(ans, AR(ps[i], ps[j], ps[k]));
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
0 0
6 0
6 7
2
1 5
2
2 6
1
5



*/