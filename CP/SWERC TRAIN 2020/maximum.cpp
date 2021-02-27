#include <bits/stdc++.h>
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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vi a(n); loop(i,0,n) cin>>a[i];
    set<int> s;
    int nn = n/2;
    loop(x,0,(1<<nn)){
        int cur = 0;
        loop(j,0,nn) if(x&(1<<j)) cur=(cur+a[j])%m;
        s.insert(cur);
    }
    int ans = 0;
    loop(x,0,(1<<(n-nn))){
        int cur = 0;
        loop(j,0,n-nn) if(x&(1<<j)) cur=(cur+a[nn+j])%m;
        auto it = s.lower_bound(m - cur);
        if (it!=s.begin()) it--;
        chkmax(ans, (cur + *it)%m);
    }
    cout<<ans<<endl;


    bitset<1000> bit;
    bit[0] = 1;
    bit[321] = 1;
    bit = bit | (bit << 10);
    
    return 0;
}
/*
color a
cls
g++ maximum.cpp -o a & a
5 1000
38361 75847 14913 11499 8297



0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0
0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0
*/

