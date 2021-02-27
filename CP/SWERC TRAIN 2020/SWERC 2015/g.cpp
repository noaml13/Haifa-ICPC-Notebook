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

int solve(vi& a, int k){
    int n = a.size();
    vi gr(n+1);
    loop(i,1,n+1){
        vi vals;
        loop(j,0,k+1){
            if (j>=i) break;
            int amt = j+a[i-j-1];
            if (amt>i) continue;
            vals.pb(gr[i-amt]);
        }
        sort(all(vals));
        for(int x:vals) if(x==gr[i]) gr[i]++;
    }
    return gr[n];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, k; cin>>n>>k;
    vvi a(n);
    int res = 0;
    loop(i,0,n){
        int m; cin>>m;
        a[i].resize(m);
        loop(j,0,m) cin>>a[i][j];
        int v = solve(a[i], k);
        res ^= v;
    }
    if (res) cout<<"Alice can win."<<endl;
    else cout<<"Bob will win."<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
2 1
1 1
3 1 2 1


4 1
4 1 1 1 1
6 2 1 2 1 2 1
4 1 1 1 1
6 2 1 2 1 2 1

2 2
5 3 2 1 2 1
5 5 4 3 2 1

*/