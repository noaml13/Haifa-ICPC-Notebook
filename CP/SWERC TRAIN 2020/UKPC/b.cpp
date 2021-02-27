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
const int INF = 1e18;
typedef long double ld;

int operator*(ii a, ii b){
    return a.x*b.y - a.y*b.x;
}
ii operator+(ii a, ii b){
    return {a.x+b.x, a.y+b.y};
}
ii operator-(ii a, ii b){
    return {a.x-b.x, a.y-b.y};
}
ld ans = INF;
vii a;
void check(ii vec){
    int mini = INF, maxi = -INF;
    for(auto p:a){
        int val = p * vec;
        chkmin(mini, val);
        chkmax(maxi, val);
    }
    int v = maxi - mini;
    ld vv = v * 1.0 / sqrt(vec.x*vec.x + vec.y*vec.y);
    if (ans > vv) ans = vv;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    a.resize(n); 
    loop(i,0,n) cin>>a[i].x>>a[i].y;
    loop(i,0,n) loop(j,0,i){
        ii vec = a[i] - a[j];
        check(vec);
        // vec -> 
        vec = {vec.y, -vec.x};
        check(vec);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
4
0 0
5 0
5 2
0 2

*/