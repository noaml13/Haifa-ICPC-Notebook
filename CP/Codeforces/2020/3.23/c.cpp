#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,k; cin>>n>>m>>k;
    int a;
    loop(i,0,2*k) cin>>a>>a;
    vi ans;
    loop(i,0,n-1) ans.pb(0);
    loop(i,0,m-1) ans.pb(1);
    loop(i,0,n){
        loop(j,0,m-1) ans.pb((i%2==0)*2+1);
        if (i<n-1) ans.pb(2);
    }
    char conv[] = {'U','L','D','R'};
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<conv[x];
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
3 3 2
1 2
2 1
3 3
3 2


*/




