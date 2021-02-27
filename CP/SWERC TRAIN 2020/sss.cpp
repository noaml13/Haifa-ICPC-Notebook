#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define all(x) x.begin(),x.end()
using namespace std;

int cross(const ii& a, const ii& b){
    return a.x*b.y - a.y*b.x;
}
bool cmp(const ii& a, const ii& b){
    return cross(a,b)<0;
}
bool same(const ii& a, const ii& b){
    return cross(a,b)==0 && a.x*b.x>=0 && a.y*b.y>=0;
}

int solve(){
    int n; cin>>n;
    vector<ii> pos, neg;
    double x,y; int c;
    loop(i,0,n) {
        cin>>x>>y>>c;
        if (x==0 && y==0) continue;
        x*=100*c, y*=100*c;
        if (y>0 || (y==0 && x>0)) pos.pb({round(x),round(y)});
        else neg.pb({round(x),round(y)});
    }
    sort(all(pos), cmp), sort(all(neg), cmp);
    for(auto x:pos) neg.pb(x);
    pos.clear();
    for(auto x:neg) if(!pos.size() || !same(pos.back(), x)) pos.pb(x);
    n = pos.size();
    if (n<2) return cout<<"YES"<<endl,0;
    bool ok = 0;
    loop(i,0,n) {
        ii b = pos[i], a = pos[(i+1)%n];
        if(cross(a,b)<=0) ok = 1;
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ sss.cpp -o a & a
3
9
-2.0 1.0 1
2.0 2.0 -1
4.0 2.5 -1
4.0 0.5 -1
-1.0 -1.0 1
4.0 1.5 -1
-3.0 -1.0 1
2.0 3.0 -1
-4.0 1.0 1
4
2.0 2.0 1
2.0 -2.0 -1
-2.0 2.0 -1
-2.0 -2.0 1
1
1 1 1

*/