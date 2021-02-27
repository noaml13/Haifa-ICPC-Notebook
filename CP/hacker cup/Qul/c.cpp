#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

void dom(vii& a, map<int, int>& m, int sign){
    for(auto p:a){
        int bef = 0;
        if (m.find(p.x)!=m.end()) bef = m[p.x];
        chkmax(m[p.x+sign*p.y],bef + p.y);
    }
}
int solve(int t){
    int n; cin>>n;
    vii a(n);
    loop(i,0,n) cin>>a[i].x>>a[i].y;
    sort(all(a));
    map<int, int> right, left;
    dom(a, right,1);
    reverse(all(a));
    dom(a, left,-1);
    int ans=0;
    for(auto p:right) {
        if (left.find(p.x)!=left.end()) chkmax(ans, p.y + left[p.x]);
        else chkmax(ans, p.y);
    }
    for(auto p:left) chkmax(ans, p.y);
    cout<<"Case #"<<t<<": "<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve(i+1);
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a < in.txt > out.txt


*/