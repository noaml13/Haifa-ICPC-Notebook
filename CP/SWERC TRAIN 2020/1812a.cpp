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
const int INF = 1e18, MOD = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, qq; cin>>n>>qq;
    vi l(qq), r(qq), q(qq);
    loop(i,0,qq) cin>>l[i]>>r[i]>>q[i], l[i]--, r[i]--;
    int log = 30;
    vi ans(n);
    loop(k,0,log){
        vi tmp(n+1);
        loop(i,0,qq) if(q[i]&(1<<k)){
            tmp[l[i]]++;
            tmp[r[i]+1]--;
        }
        loop(i,1,n+1) tmp[i]+=tmp[i-1];
        loop(i,0,n) tmp[i] = (tmp[i]>0), ans[i] += tmp[i]*(1<<k);
        loopr(i,0,n) tmp[i+1] = tmp[i];
        tmp[0] = 0;
        loop(i,0,n) tmp[i+1] += tmp[i];
        loop(i,0,qq) if((q[i]&(1<<k))==0){
            int v = tmp[r[i]+1] - tmp[l[i]];
            if (v>=r[i]-l[i]+1) return cout<<"NO"<<endl,0;
        }
    }
    cout<<"YES"<<endl;
    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ 1812a.cpp -o a & a
3 1
1 3 3

*/

