#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;

const int P = 1e9+7, MOD = 1e9+9;
vi h, pp;
int get(int i, int x){
    return ((h[i+x] - h[i] * pp[x])%MOD + MOD )%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,l; cin>>n>>l;
    vi a(n); loop(i,0,n) cin>>a[i];
    h.resize(n+1,0); pp.resize(n+1,1);
    loop(i,0,n) h[i+1] = (h[i]*P + a[i])%MOD, pp[i+1]=pp[i]*P%MOD;
    map<int, vi> mm;
    loop(i,0,n-l+1){
        mm[get(i,l)].pb(i);
    }
    int q; cin>>q;
    vi ans(n-l+1);
    for(auto x:mm){
        //cout<<x.x<<": ";
        for(auto i:x.y) {
            //cout<<i<<" ";
            ans[i]=x.y.size()-1;
        }
        //cout<<endl;
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ c2.cpp -o a & a
6 2
1 2 1 3 2 1
1
0

*/



