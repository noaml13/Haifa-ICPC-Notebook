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

ii operator-(ii a, ii b){
    return {a.x-b.x, a.y-b.y};
}
ii operator+(ii a, ii b){
    return {a.x+b.x, a.y+b.y};
}
int operator*(ii a, ii b){
    return a.x * b.y - a.y * b.x;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    /*
    int n;
    vii p(n);
    int mini = 0;
    loop(i,1,n){
        if (p[i]<p[mini]) mini = i;
    }
    ii base = p[mini];
    swap(p[mini], p.back()); p.pop_back();
    sort(all(p), [&](ii a, ii b){
        return (a-base)*(b-base)>0; // ?
    });
    vii st = {base};
    for(ii a:p){
        while(st.size()>=2 && ()) st.pop_back();
        st.pb(a);
    }
    */
    int n; cin>>n;
    vi a(n), b(n);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    vi cnt(3);
    loop(i,0,n){
        cnt[i%3]+=a[i];
    }
    vi ans(3);
    loop(i,0,n){
        loop(j,0,3) ans[(i+j)%3]+=cnt[j]*b[i];
    }
    loop(i,0,3) cout<<ans[(i+1)%3]<<" ";
    return 0;
}
/*
color a
cls
g++ j.cpp -o a & a
3
1 1 1
1 1 1



*/