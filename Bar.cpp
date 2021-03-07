#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define pqii priority_queue<ii>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(VA_ARGS, rep3, rep2, rep1)(VA_ARGS)
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, s, n) for (int i = (s); i < (n); i++)
#define repr(...) GET_MACRO(VA_ARGS, repr3, repr2, repr1)(VA_ARGS)
#define repr1(n) for (int i = (n)-1; i >= 0; i--)
#define repr2(i, n) for (int i = (n)-1; i >= 0; i--)
#define repr3(i, n, s) for (int i = (n)-1; i >= (s); i--)
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)

const int INF = 1e18;

void solve(){
    int n; cin >> n;
    vii v(n);
    rep(n) cin >> v[i].x >> v[i].y;
    cout<<fixed<<setprecision(1);

    int cv = 0;
    double d = 0;
    rep(n){
        d += cv*v[i].y + 0.5 * v[i].xv[i].yv[i].y;
        cv += v[i].xv[i].y;
    }
    double normal = d;
   //  cout << d << endl;
    sort(all(v));
    reverse(all(v));
    cv = 0;
    d = 0;
    rep(n){
        d += cvv[i].y + 0.5 * v[i].xv[i].yv[i].y;
        cv += v[i].xv[i].y;
    }
    cout << d - normal<< endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}

/*
cls
g++ a.cpp -o a -D_GLIBCXX_DEBUG & a
4

*/
