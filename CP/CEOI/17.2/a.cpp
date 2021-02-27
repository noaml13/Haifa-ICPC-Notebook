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
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

struct line{
    int a=0,b=INF;
    int at(int x){
        return a*x+b;
    }
};
struct LiCho{
    int sz;
    vector<line> a;
    LiCho(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void insert(int cur, line x, int l=-1, int r=-1){
        if (l==-1) l=0,r=sz;
        int mid = (l+r)/2;
        if (a[cur].at(mid)>x.at(mid)){
            swap(x, a[cur]);
        }
        if (x.at(l) < a[cur].at(l)) insert(cur*2, x, l, mid);
        if (x.at(r-1) < a[cur].at(r-1)) insert(cur*2+1, x, mid, r);
    }
    int query(int x){
        int best=INF;
        for(int i=x+sz;i;i/=2) chkmin(best, a[i].at(x));
        return best;
    }
};
const int MAX = 1e6+123;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi h(n), w(n), pref(n+1);
    loop(i,0,n) cin>>h[i];
    loop(i,0,n) cin>>w[i], pref[i+1]=pref[i]+w[i];
    vi dp(n); dp[0]=0;
    LiCho tree(MAX);
    auto insert = [&](int j){
        line l;
        l.a = -2*h[j];
        l.b = dp[j] + h[j]*h[j] - pref[j+1];
        tree.insert(1,l);
    };
    insert(0);
    loop(i,1,n){
        dp[i] = h[i]*h[i] + pref[i] + tree.query(h[i]);
        insert(i);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
6
3 8 7 1 6 6
0 -1 9 1 2 0
*/

