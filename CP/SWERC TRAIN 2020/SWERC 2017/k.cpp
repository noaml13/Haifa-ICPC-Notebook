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
ii operator+(ii a, ii b){
    return {a.x+b.x, a.y+b.y};
}
ii operator-(ii a, ii b){
    return {a.x-b.x, a.y-b.y};
}
int operator*(ii a, ii b){
    return a.x*b.y - a.y*b.x;
}
int dot(ii a, ii b){
    return a.x*b.x + a.y*b.y;
}
int norm(ii a){
    return a.x*a.x+a.y*a.y;
}
ii perp(ii a){
    return {a.y, -a.x};
}
ld dist(ii a, ii b, ii c){
    ii v = perp(a-b);
    return abs(dot(v, (c-a))) / sqrt(ld(norm(v)));
}
bool cmpR(ii a, ii b){
    return ld(a.x)/a.y < ld(b.x)/b.y;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, r; cin>>n>>r;
    vii p(n);
    loop(i,0,n) cin>>p[i].x>>p[i].y;
    int mini = 0;
    loop(i,1,n){
        if (p[mini] > p[i])
            mini = i;
    }
    ii base = p[mini];
    swap(p[mini], p.back()); p.pop_back();
    //for(ii& a:p) a = a-base;
    sort(all(p), [&](ii a, ii b){
        int v = (a-base)*(b-base);
        if (v) return v<0;
        return norm(a-base)<norm(b-base);
    });
    vii st = {base};
    for(ii x:p){
        while(st.size()>1){
            ii a = st[st.size()-2], b = st.back();
            if ((b-a)*(x-b)<0) break;
            st.pop_back();
        }
        st.pb(x);
    }
    p = st;
    n = p.size();
    //cout<<"N: "<<n<<endl;
    if (n<=2) return cout<<0<<endl,0;
    ld ans = INF;
    int j = 0;
    //cout<<dist({0,0},{2,0},{0,1})<<endl;
    loop(i,0,n){
        int cnt = 0;
        while(dist(p[i], p[(i+1)%n], p[j%n]) <= dist(p[i], p[(i+1)%n], p[(j+1)%n])){
            j++;
            cnt++;
            if (cnt>n) break;
        }
        if (cnt>n) j = i+2;
        ld v = dist(p[i], p[(i+1)%n], p[j%n]);
        if (v<ans) ans = v;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ k.cpp -o a & a
3 3
0 0
1 1
2 2



7 100
0 0
2 0
0 2
2 2
1 1
3 1
1 3

3 10
0 0
10 0
0 10



*/