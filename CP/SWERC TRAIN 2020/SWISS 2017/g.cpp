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
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii a(n);
    loop(i,0,n) cin>>a[i].x>>a[i].y;
    if (n<=2) return cout<<1<<endl, 0;
    if (n%2==1) return cout<<"INFINITY"<<endl,0;
    loop(i,0,n) a.pb(a[i]);
    loop(i,0,n/2){
        ii v1 = a[i+1] - a[i], v2 = a[i+n/2+1] - a[i+n/2];
        if (v1*v2) return cout<<"INFINITY"<<endl,0;
    }
    cout<<n/2<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
4
0 0
1 0
1 1
0 1

4
-1 0
0 1
1 0
0 -1

6
1 1
2 2
3 2
4 1
5 0
2 0


*/