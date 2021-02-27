#pragma GCC taget ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int INF = 1e14;
typedef long double ld;
const int maxn = 1e5+5;

int _p[maxn],_sz[maxn],_rep[maxn];
inline void init(int n) {
    loop(i,0,n) _sz[i] = 1, _p[i] = _rep[i] = i;
}
int find(int x) {
    if (_p[x] != x) _p[x] = find(_p[x]);
    return _p[x];
}
inline int ffind(int x) {
    return _rep[find(x)];
}
inline int uni(int a, int b) {
    a = find(a), b = find(b);
    int r = _rep[b];
    if (a == b) return a;
    if (_sz[a] > _sz[b]) swap(a, b);
    _sz[b] += _sz[a];
    _p[a] = b;
    _rep[b] = r;
    return b;
}
inline int rem(int x) {
    return _rep[uni(x, x + 1)];
}

int n;
int h[maxn], hh[maxn], backh[maxn];
ii sorted[maxn];
ld who[maxn];
ld solve(){
    loop(i,0,n) sorted[i] = {h[i], i};
    sort(sorted, sorted+n);
    int cnt = 0;
    loop(i,0,n) {
        hh[sorted[i].y] = cnt;
        while(i+1<n && sorted[i].x==sorted[i+1].x) 
            hh[sorted[++i].y] = cnt;
        backh[cnt++] = sorted[i].x; 
    }
    // loop(i,0,n) cout<<h[i]<<" "; cout<<endl;
    //loop(i,0,n) cout<<hh[i]<<" "; cout<<endl;
    init(cnt + 2);
    fill(who, who+cnt+2, -1);
    ld res = -INF;
    loopr(i, 0, n - 1) {
        int a = hh[i], b = hh[i + 1];
        for (int cur = ffind(0); cur <= b; cur = rem(cur)) who[cur] = i + 1;
        ld v = who[hh[i]] - i;
        chkmax(res, v);
        if (a > b) {
            //cout<<"HI: "<<endl;
            for (int cur = ffind(b); cur <= a; cur = rem(cur)) {
                who[cur] = i + (h[i] - backh[cur]) * 1.0 / (h[i] - h[i + 1]);
                //cout<<"BII: "<<cur<<endl;
            }
        }
    }
    return res;
}
ld solve(int dd){
    loop(i,0,n) h[i] = h[i] - i*dd;
    ld ans = solve();
    reverse(h,h+n);
    loop(i,0,n) h[i] = -h[i];
    chkmax(ans,solve());
    reverse(h, h+n);
    loop(i,0,n) h[i] = -h[i];
    loop(i,0,n) h[i] = h[i] + i*dd;
    return ans;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int k; cin>>n>>k;
    n++;
    loop(i,0,n) cin>>h[i];
    cout<<fixed<<setprecision(10);
    loop(i,0,k){
        ld d; cin>>d;
        d = solve(round(10*d));
        if (d < -INF/2) cout << -1 << '\n';
        else cout << d << '\n';
    }
    return 0;
}
/*
color a
cls
g++ h.cpp -o a & a
8 2
0 0 10 30 60 45 75 65 30
2.0
3.1




*/