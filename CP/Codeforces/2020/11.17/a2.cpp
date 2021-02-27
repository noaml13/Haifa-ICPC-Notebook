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
    int t,n,m; cin>>t>>n>>m;
    cout<<t<<endl;
    loop(k,0,t){
        cout<<n<<" "<<m<<endl;
        loop(i,0,n) {
            loop(j,0,m) cout<<char('0'+(rand()%10!=0));
            cout<<endl;
        }
    }
    return 0;
}
/*
color a
cls
g++ a2.cpp -o b & b

*/