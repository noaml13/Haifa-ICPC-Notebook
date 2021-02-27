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
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;


int solve(){
    int n; cin>>n;
    vi a(n+1, -1); loop(i,0,n) cin>>a[i], a[i]--;
    vi pos(n); loop(i,0,n) pos[a[i]]=i;
    int last = 0;
    loop(i,a[0]+1,n) chkmax(last, pos[i]);
    loop(i,last+1,n) if(a[i]<a[0]) return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
4
3
1 2 3
4
3 1 2 4
3
2 3 1
6
2 4 6 1 3 5

*/