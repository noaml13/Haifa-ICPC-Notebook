#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;


struct car{
    ii p,d;
    int s;
};
#define dd pair<double, double>

double solve(car& a, car& b){
    if (a.d == b.d || a.d = {-b.d.x,-b.d.y}){
        
    }
    return INF;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<car> cars(n);
    for(auto &c:cars){
        cin>>c.p.x>>c.p.y>>c.d.x>>c.d.y>>c.s;
    }
    double ans = INF;
    loop(i,0,n) loop(j,i+1,n) chkmin(ans, solve(cars[i],cars[j]) );
    if (ans==INF) cout<<"No show :("<<endl;
    else cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
4
3 -1 -1 1 2
2 3 -3 -2 10
-4 2 1 -2 1
-2 -2 -1 2 4


*/