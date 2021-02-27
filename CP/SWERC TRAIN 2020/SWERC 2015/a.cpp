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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;
typedef long double ld;
int n;
ld ans = 0;
ld pos(ii a){
    return a.x * 1.0 / a.y;
}
void solve(vi& a){
    vector<ii> st; st.pb({a[0], 1});
    loop(i,1,n){
        st.pb({a[i], 1});
        while(st.size()>1){
            ii &a = st.back(), &b = st[st.size()-2];
            if (a.x*b.y > b.x*a.y) break;
            b.x+=a.x, b.y+=a.y;
            st.pop_back();
        }
    }
    int i = 0;
    for(auto p:st){
        ld x = pos(p);
        loop(k,0,p.y){
            ans+=(x-a[i])*(x-a[i]);
            i++;
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vi x(n), y(n);
    loop(i,0,n) cin>>x[i]>>y[i];
    solve(x), solve(y);
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
6
4 1
2 4
3 2
8 3
5 6
2 5





*/