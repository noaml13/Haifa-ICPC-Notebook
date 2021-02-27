#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e18, MOD=1e9+9;


int in(int x, ii a){
    if (a.y<a.x) swap(a.x, a.y);
    return a.x<=x && x<=a.y;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    string s; cin>>s;
    vi b, w;
    loop(i,0,2*n){
        if (s[i] == 'B') b.pb(i);
        else w.pb(i);
    }
    vi per(n); loop(i,0,n) per[i]=i;
    int ans = 0;
    do{
        int cur = 0;
        loop(i,0,n){
            ii segi = {b[i], w[per[i]]};
            loop(j,i+1,n){
                ii segj = {b[j], w[per[j]]};
                if (in(segi.x, segj) + in(segi.y, segj)==1) cur++;
            }
        }
        chkmax(ans, cur);

    }while(next_permutation(all(per)));
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
3
BBWWBW


*/
