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
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;
const double eps = 1e-9;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n=2e5-10; cin>>n;
    cout<<n<<endl;
    loop(i,0,n) cout<<((1<<20) - 1)<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ hack.cpp -o a & a

*/