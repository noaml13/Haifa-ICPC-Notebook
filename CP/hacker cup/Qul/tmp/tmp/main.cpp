#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
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

struct SEG {
    int sz;
    vi a;
    SEG(int n) {
        for (sz = 1; sz < n; sz *= 2);
        a.resize(2 * sz, INF);
    }
    void update(int i, int x) {
        i += sz;
        chkmin(a[i], x);
        for (i /= 2; i; i /= 2) a[i] = min(a[2 * i], a[2 * i + 1]);
    }
    int query(int l, int r) {
        chkmax(l, 0LL); chkmin(r, sz - 1);
        int ans = INF;
        for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
            if (l % 2) chkmin(ans, a[l++]);
            if (r % 2 == 0) chkmin(ans, a[r--]);
        }
        return ans;
    }
};

int n, m, a, b;
vvi g;
vi trk, c;
bool dfs(int cur, int p = -1) {
    if (cur == b) {
        trk.pb(cur);
        return 1;
    }
    for (auto nei : g[cur]) if (nei != p) {
        if (dfs(nei, cur)) {
            trk.pb(cur);
            return 1;
        }
    }
    return 0;
}
vb col;
void dfs2(int cur, int pos, SEG& seg, int p = -1, int d = 0) {
    if (c[cur]) {
        int curp = pos + d;
        seg.update(pos - d, seg.query(curp - m, curp) + c[cur]);
    }
    for (auto nei : g[cur]) if (nei != p && !col[nei]) {
        dfs2(nei, pos, seg, cur, d + 1);
    }
}
ifstream in("in.txt");
ofstream out("out.txt");
#define cout out
#define cin in
int solve(int t) {
    cin >> n >> m >> a >> b; a--; b--;
    //cout << "NMAB: " << n << " " << m << " " << a << " " << b << endl;
    g.clear(); g.resize(n);
    c.clear(); c.resize(n);
    loop(i, 0, n) {
        int p; cin >> p >> c[i];
        if (p == 0) continue;
        p--;
        g[p].pb(i);
        g[i].pb(p);
    }
    trk.clear(); col.clear(); col.resize(n);
    dfs(a); reverse(all(trk));
    //cout << t << endl;
    for (auto x : trk) col[x] = 1;
    SEG seg(2 * n); seg.update(n, 0);
    int ind = n;
    for (auto x : trk) {
        dfs2(x, ind, seg);
        ind++;
    }
    int res = seg.query(ind - m - 1, ind);
    if (res >= INF) res = -1;
    cout << "Case #" << t << ": " << res << endl;
    return 0;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    loop(i, 0, t) {
        solve(i + 1);
    }
    return 0;
}
/*
color a
cls
g++ d.cpp -o a  & a < in.txt > out.txt
g++ d.cpp -o a & a


*/
