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

bool check(int stepz, int stepo, int d, int x, int y){
    int cnt = stepo, t = 1;
    vi b;
    while(b.size()<d){
        if (t) loop(i,0,stepo) b.pb(1);
        else loop(i,0,stepz) b.pb(0);
        t = !t;
    }
    if (b.size()!=d) return 0;
    reverse(all(b));
    int c = 0;
    loop(i,0,d) c+=b[i]<<i;
    return x<= c && c<=y;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int x,y; cin>>x>>y;
    int ans = 0;
    loop(i,1,64) loop(j,1,64) loop(d,i+j,64) ans+=check(i,j,d,x,y);
    loop(i,1,64) ans+=check(10,i,i,x,y);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ h.cpp -o a & a
1 10



*/