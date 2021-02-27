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
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;

vvi g;
vi f;
vi dp;
vb spec;
vi order;
void predfs(int cur, int p=-1){
    f[cur] = p;
    for(auto nei:g[cur]) if (nei!=p) predfs(nei, cur);
}
void dfs(int cur, int p=-1){
    int fir = 0, sec = 0, sons = 0;
    for(auto nei:g[cur]) if (nei!=p && !spec[nei]) {
        sons++;
        //if (cur==1) cout<<"NEI: "<<nei<<endl;
        dfs(nei, cur);
        int v = dp[nei];
        if (v>fir) sec=fir, fir=v;
        else if (v>sec) sec=v;
    }
    dp[cur] = sec + sons; //down + up (without p edge)
}
bool can(vvi& lst, int x){
    int n = lst.size(), b = 0;
    loop(i,0,n){
        int add = 0;
        for(auto v:lst[i]) if(v + b > x) add++;
        b+=add;
        if (b > i + 1) return 0;
    }
    return b<=x;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,t,m; cin>>n>>t>>m; t--; m--;
    g.resize(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    f.resize(n); spec.resize(n); dp.resize(n,0);
    predfs(t);
    for(int cur = m;cur!=-1;cur=f[cur]) spec[cur] = 1, order.pb(cur);
    order.pop_back(); //-t
    reverse(all(order));
    int k = order.size(), carry = 0;
    vvi lst(k);
    loop(i,0,k){
        dfs(order[i]);
        int cur = order[i], sons = 0;
        vi vals;
        for(auto nei:g[cur]) if (!spec[nei]){
            sons++;
            vals.pb(dp[nei]);
        }
        carry+=sons;
        for(auto &x:vals) x+=carry;
        lst[i] = vals;
    }
    reverse(all(lst));
    int l=0, r = n+10, mid, ans=-1;
    while(l<r){
        mid = (l+r)/2;
        if (can(lst,mid)) ans = r = mid;
        else l = mid + 1 ;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
15 1 15
1 13
13 14
13 2
2 3
2 4
3 9
3 5
4 7
4 6
6 8
7 10
7 11
6 12
4 15
*/



