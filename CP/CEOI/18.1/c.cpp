#include <bits/stdc++.h>
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
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,l; cin>>n>>l;
    vi a(n); loop(i,0,n) cin>>a[i];
    int q; cin>>q;
    map<int, int> conv;
    vi qur(q);
    loop(i,0,q){
        cin>>qur[i];
        conv[qur[i]];
    }
    conv[INF];
    int m = 0;
    for(auto &p:conv) p.y=m++;
    int nn = n-l+1;
    vvi ans(m, vi(nn));
    loop(k,1,nn){
        int cur = 0;
        loop(i,0,l) cur+=(a[i]!=a[i+k]);
        loop(i,0,nn-k){
            int j = i+k;
            int ind = conv.lower_bound(cur)->y;
            ans[ind][i]++; ans[ind][j]++;
            if (j+l==n) break;
            cur-=(a[i]!=a[j]);
            cur+=(a[i+l]!=a[j+l]);
        }
    }
    loop(i,1,m) loop(j,0,nn) ans[i][j]+=ans[i-1][j];
    for(auto ind:qur){
        for(auto x:ans[conv[ind]]) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6 2
1 2 1 3 2 1
3
1
2
0

*/



