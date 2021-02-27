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
const int INF = 4e18, MOD = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi lis(n); loop(i,0,n) cin>>lis[i];
    vi inds(n+1, -1);
    vvi g(n);
    vi deg(n);
    loopr(i,0,n){
        int a = inds[lis[i]];
        int b = inds[lis[i]-1];
        if (a!=-1) g[a].pb(i), deg[i]++;
        if (b!=-1) g[i].pb(b), deg[b]++;
        inds[lis[i]] = i;
    }
    priority_queue<int, vi, greater<int>> q;
    loop(i,0,n) if(deg[i]==0) q.push(i);
    vi a(n); int cnt = 1;
    while(q.size()){
        int cur = q.top(); q.pop();
        a[cur] = cnt++;
        for(int nei:g[cur]){
            if (--deg[nei]==0) q.push(nei);
        }
    }
    loop(i,0,n) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ k.cpp -o a & a
4
1 2 2 1



*/