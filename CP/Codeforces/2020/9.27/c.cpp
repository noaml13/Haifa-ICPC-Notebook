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
const int INF = 2e9;
 


int v1[40]={0}, v2[40]={0};
void dfs(vi& a, int k){
    if (a.size()==0 || k==-1) return ;
    vi one, zero;
    int o=0, z=0;
    for(auto x:a){
        int v = x & (1<<k);
        if (v) o++, v2[k]+=z, one.pb(x);
        else z++, v1[k]+=o, zero.pb(x);
    }
    dfs(zero, k-1);
    dfs(one, k-1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    loop(i,0,40) v1[i] = v2[i] = 0;
    dfs(a, 30);
    int x = 0, ans = 0;
    loop(i,0,31){
        if (v2[i]<v1[i]) x^=(1<<i), ans+=v2[i];
        else ans+=v1[i];
    }
    cout<<ans<<" "<<x<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
 
*/