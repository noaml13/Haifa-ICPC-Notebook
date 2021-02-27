#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define loop(i,s,e) for(int i=(s); i<(e); i++)
#define loopr(i,s,e) for(int i=(e)-1; i>=(s); i--)
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define all(a) a.begin(),a.end()
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max(a,b)
using namespace std;
const int MOD = 1e9 + 7;

const int MAXN = 1e5;
int n,q;
int p[MAXN], w[MAXN];
int d[MAXN];
ii h[2][MAXN];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    p[0] = -1;
    loop(i,1,n) cin>>p[i];
    loop(i,1,n) cin>>w[i];
    loop(b,0,2) fill(h[b], h[b]+n, ii({0,-1}));
    loop(i,1,n){
        d[i] = d[p[i]] + 1;
    }
    loopr(i,1,n){
        if (h[1][p[i]].x < h[0][i].x + w[i]){
            h[1][p[i]] = {h[0][i].x + w[i], i};
            if (h[1][p[i]].x>h[0][p[i]].x) swap(h[0][p[i]], h[1][p[i]]);
        }   
    }
    int ans = 0;
    loop(i,0,n) ans = (ans + h[0][i].x + h[1][i].x)%MOD;
    cout<<ans<<endl;
    cin>>q;
    loop(i,0,q){
        int v,add; cin>>v>>add;
        w[v] += add;
        while(v){
            int u = p[v], hh = h[0][v].x + w[v];
            if (h[0][u].y==v){
                ans = (ans + hh - h[0][u].x) % MOD;
                h[0][u].x = hh;
            }
            else if (hh>h[1][u].x){
                ans = (ans + hh - h[1][u].x) % MOD;
                h[1][u] = {hh, v};
                if (h[1][u].x>h[0][u].x) swap(h[0][u], h[1][u]);
            }
            else break;
            v = u;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
color 
cls
g++ Arboras.cpp -o a & a
5
0 0 1 1
0 0 0 0
10
1 2
2 2
3 2
4 2
4 1
3 1
2 1
1 1
4 1000
2 1000
*/
