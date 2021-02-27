#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
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
const int INF = 1e18;
int tryc(vvi& a, int n, int x, int y){
    int ans=0;
    loop(i,0,n-x+1) loop(j,0,n-y+1){
        chkmax(ans, a[i+x][j+y]-a[i][j+y]-a[i+x][j]+a[i][j]);
    }
    //cout<<"XY"<<x<<" "<<y<<": "<<ans<<endl;
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;  cin>>n>>m;
    vvi a(n+1,vi(n+1,0));
    loop(i,0,m){
        int x,y; cin>>x>>y;
        a[x][y]=1;
    }
    loop(i,0,n+1) loop(j,0,n+1){
        if (i) a[i][j]+=a[i-1][j];
        if (j) a[i][j]+=a[i][j-1];
        if (i && j) a[i][j]-=a[i-1][j-1];
    }
    int ans=INF;
    for(int i=1;i*i<=m;i++){
        if (m%i) continue;
        chkmin(ans,m-tryc(a,n,i, m/i));
        chkmin(ans,m-tryc(a,n,m/i, i));
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ NERED.cpp -o a & a
3 2
1 1
1 1

*/


 
