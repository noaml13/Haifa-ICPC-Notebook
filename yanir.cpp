#include <bits/stdc++.h>
using namespace std;
//@formatter:off
#ifdef lol
const bool dbg = true;
#else
const bool dbg = false;
#endif
#define dout if(dbg) cout
#define fin(i, s, n) for (auto i = s; i < n; ++i)
#define fine(i, s, n) for (auto i = s; i <= n; ++i)
#define int int64_t
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define def(x) int x; cin >> x
#define cases def(t); while (t--)
#define all(x) (x).begin(), (x).end()
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vii = vector<ii>;
using vvii = vector<vector<ii>>;
using ld = long double;
template<class A, class B> ostream &operator<<(ostream &os, pair<A, B> p) { return os << '{' << p.x << ',' << p.y << '}'; }
template<class A, class B> istream& operator>>(istream& is, pair<A,B>& p) { return is >> p.x >> p.y; }
template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; fin(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& x : v) is >> x; return is; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }
int rnd() { return rand()^(rand()<<15); }
#define loop(i, s, e) for(int i=(s);i<(e);i++)
#define loopr(i, s, e) for(int i=(e)-1;i>=(s);i--)
const int inf = 1e18;
//@formatter:on

int32_t main() {
    if (dbg) freopen("ina.txt", "r", stdin);
    else cin.tie(0)->sync_with_stdio(0);
    return 0;
}
