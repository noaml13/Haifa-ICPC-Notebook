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
int n;
vi a, ans;
vvi pos;
void mm(int s){
    ans.pb(s);
    loop(i,0,n+1) if (pos[i].size()==0) {
        a[s]=i;
        pos[i].pb(s);
        return ;
    }
}
int solve(){
    cin>>n;
    ans.clear(); 
    a.clear(); a.resize(n); 
    pos.clear(); pos.resize(n+1);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) if(a[i]<=n) pos[a[i]].pb(i);
    int cur = -1;
    loop(i,0,n){
        cur++;
        for(auto ind:pos[cur]) mm(ind);
        if (a[i]!=cur) mm(i);
        pos[cur].clear();
        pos[cur].pb(i);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i+1<<" ";
    cout<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
1
7
0 7 3 1 3 7 7


5
3
2 2 3
3
2 1 0
7
0 7 3 1 3 7 7
9
2 0 1 1 2 4 4 2 0
9
8 4 7 6 1 2 3 0 5

*/