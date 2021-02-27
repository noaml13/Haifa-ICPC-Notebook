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



int32_t main(){
    ios_base::sync_with_stdio(false);
    freopen("out.txt", "w", stdout);
    int n; cin>>n;
    int nn = n;
    int s = n-2, t = n-1; n-=2;
    int x = n/2; n -=x;
    vector<pair<ii, int>> edge;
    loop(i,0,x) edge.pb({{i, s},1});
    loop(i,0,n) edge.pb({{s, x+i},i+1});
    loop(i,0,n) edge.pb({{x+i, t},2*(n-i)-1});
    int m = edge.size(); n = nn;
    cout<<n<<" "<<m<<" "<<n-1<<endl;
    for(auto p:edge) cout<<p.x.x+1<<" "<<p.x.y+1<<" "<<p.y<<endl;
    loop(i,1,n) cout<<1<<" "<<i+1<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a


*/