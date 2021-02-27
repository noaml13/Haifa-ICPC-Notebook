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
const int INF = 1e9, MOD = 1e9 + 7;
const double eps = 1e-7;
#define dd pair<double, double> 
const double pi = 3.14159265358979323846;


dd operator-(dd a, dd b){
    return {a.x-b.x, a.y-b.y};
}
dd perp(dd a){ // right
    return {a.y, -a.x};
}
double operator*(dd a, dd b){
    return a.x*b.y - a.y*b.x;
}
int n;
vector<dd> p;
bool can(vector<dd>& c, double r, int k){
    for(auto a:p){
        bool ok = 0;
        loop(i,0,k){
            dd vec = c[(i+1)%k] - c[i];
            if (a * vec > r) ok = 1;
        }
        if (!ok) return 0;
    }
    return 1;
}
double solve(int k){
    vector<dd> c(k);
    double alpha = 2 * pi / k;
    loop(i,0,k){
        c[i] = {cos(alpha*i), sin(alpha*i)};
    }
    double maxr = 0, minr = 0;
    loop(i,0,k){
        dd vec = c[(i+1)%k] - c[i];
        for(auto a:p) chkmax(maxr, a * vec);
    }
    double l = 0, r = maxr, mid;
    while((r-l)>=eps){
        mid = (l+r) / 2;
        if (can(c, mid, k)) l = minr = mid;
        else r = mid;
    }
    auto area = [&](double r){
        return r*r*sin(alpha)/2 * k;
    };
    return area(minr) / area(maxr);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    p.resize(n);
    loop(i,0,n)  cin>>p[i].x>>p[i].y;
    double best = 0; int ans = -1;
    loop(i,3,9){
        double r = solve(i);
        if (r > best) best = r, ans = i;
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<" "<<best<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
9
-4 -1
-4 6
-3 -6
-3 4
0 -4
2 -3
2 3
5 1
7 0


*/