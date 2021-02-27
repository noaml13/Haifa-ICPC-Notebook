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
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

vector<double> a,b, prefa, prefb;
double ans = 0;
void solve(int l, int r, int optl, int optr){
    if (l==r) return;
    int mid = (l+r) / 2;
    int opt = -1;
    double v = -INF;
    loop(j,optl, optr){
        double curv = min(prefa[mid],prefb[j]) - (mid+j+2);
        //cout<<j<<": " <<curv<<endl;
        if (curv>v) v = curv, opt = j;
    }
    //cout<<"HI "<<v<<endl;
    chkmax(ans, v);
    solve(l,mid, optl, opt+1);
    solve(mid+1,r, opt, optr);
}
int32_t main(){
    //ios_base::sync_with_stdio(false);
    int n; cin>>n;
    a.resize(n); b.resize(n);
    loop(i,0,n) cin>>a[i]>>b[i];
    sort(all(a)); reverse(all(a));
    sort(all(b)); reverse(all(b));
    prefa.resize(n); prefb.resize(n);
    prefa[0] = a[0]; prefb[0] = b[0];
    loop(i,1,n) prefa[i] = prefa[i-1]+a[i], prefb[i] = prefb[i-1]+b[i];
    /*loop(i,0,n) cout<<prefa[i]<<" ";
    cout<<endl;*/
    solve(0,n,0,n);
    printf("%.4lf\n",(double)ans);
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
4
1.4 3.7
1.2 2
1.6 1.4
1.9 1.5
*/



