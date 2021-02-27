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

ii operator+(ii a, ii b){
    return {a.x+b.x, a.y+b.y};
}
ii operator-(ii a, ii b){
    return {a.x-b.x, a.y-b.y};
}
int operator*(ii a, ii b){
    return a.x*b.y - a.y*b.x;
}
int norm(ii a){
    return a.x*a.x+a.y*a.y;
}
ii base;
bool check(ii a, ii b, ii p){
    int v = abs(a*b) - abs(p*a) - abs(p*b) - abs((a-p)*(b-p));
    ii v1 = (a+base), v2 = (b+base);
    //cout<<"V: "<<v<<" "<<v1.x<<" "<<v1.y<<" "<<v2.x<<" "<<v2.y<<endl;
    return v == 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii p(n);
    loop(i,0,n) cin>>p[i].x>>p[i].y;
    int mini = 0;
    loop(i,1,n){
        if (p[mini].y > p[i].y || (p[mini].y==p[i].y && p[mini].x>p[i].x))
            mini = i;
    }
    base = p[mini];
    swap(p[mini], p.back()); p.pop_back();
    for(ii& a:p) a = a-base;
    sort(all(p), [&](ii a, ii b){
        int v = a*b;
        if (v) return v<0;
        return norm(a)<norm(b);
    });
    vii st = {base-base};
    for(ii x:p){
        ii xx = x+base;
        //cout<<"X: "<<xx.x<<" "<<xx.y<<endl;
        while(st.size()>1){
            ii a = st[st.size()-2], b = st.back();
            if ((b-a)*(x-b)<0) break;
            st.pop_back();
        }
        st.pb(x);
    }
    p = st;
    n = p.size();
    //cout<<"ST: "<<endl;
    //for(ii a:p) a = a+base, cout<<a.x<<" "<<a.y<<endl;
    int m; cin>>m;
    int ans = 0;
    loop(i,0,m) {
        ii a; 
        cin>>a.x>>a.y;
        a = a - base;
        int l = 0, r = n, mid, ind=0;
        while(l<r){
            mid = (l+r)/2;
            if(p[mid] * a <= 0) l = mid +1, ind = mid;
            else r = mid;
        }
        if (ind+1==n) ind--;
        //cout<<"IND: "<<ind<<endl;
        if (check(p[ind], p[ind+1], a)) ans++;//, cout<<"YA"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ j.cpp -o a & a
8
3 4
2 8
5 4
1 8
4 7
3 10
11 2
7 3
6
5 12
3 7
3 3
4 5
0 4
2 6



*/