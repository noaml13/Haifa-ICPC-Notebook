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
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;



int n,v; 
vi amt;
vvi g;
vvi dp, up;

int ans = 0;
void dfs(int cur, int p=-1){
    for(auto nei:g[cur]) if(nei!=p) dfs(nei, cur);
    int sum=0;
    for(auto nei:g[cur]) if(nei!=p) sum+=amt[nei];
    loop(i,0,v+1) up[cur][i] = dp[cur][i] = 0;
    int amtp = (p==-1?0:amt[p]);
    chkmax(up[cur][1], sum + amtp); //start up in cur
    for(auto nei:g[cur]) if(nei!=p) {
        loop(i,1,v+1){
            chkmax(dp[cur][i], dp[nei][i]);
            chkmax(dp[cur][i], dp[nei][i-1] + sum);

            chkmax(ans, dp[nei][i-1] + sum + amtp); //start in cur

            chkmax(up[cur][i], up[nei][i]);
            chkmax(up[cur][i], up[nei][i-1] + sum - amt[nei] + amtp);
        }
    }
    loop(i,1,v+1) chkmax(dp[cur][i], dp[cur][i-1]), chkmax(up[cur][i], up[cur][i-1]);
    chkmax(ans, up[cur][v]); //start in cur
    chkmax(ans, up[cur][v]); //end in cur
    vii fir(v+1, {0,-1}), sec(v+1, {0,-1});
    
    for(auto nei:g[cur]) if(nei!=p){
        loop(i,0,v+1){
            if (dp[nei][i] > fir[i].x) sec[i]=fir[i], fir[i]={dp[nei][i],nei};
            else if (dp[nei][i] > sec[i].x) sec[i]={dp[nei][i],nei};
        }
    }
    for(auto a:g[cur]) if(a!=p) { //LCA is cur
        loop(i,1,v){
            int b = fir[v-i].y;
            if (b==a){
                b = sec[v-i].y;
            }
            if (b==-1) continue;
            chkmax(ans, up[a][i] + dp[b][v-i]); //dont put
            chkmax(ans, up[a][i-1] + dp[b][v-i] + sum + amtp - amt[a]); //put
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>v;
    amt.resize(n); g.resize(n);
    loop(i,0,n) cin>>amt[i];
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    //loop(i,0,n) 
    dp.resize(n, vi(v+1,0)); up.resize(n, vi(v+1,0));
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
12 2
2 3 3 8 1 5 6 7 8 3 5 4
2 1
2 7
3 4
4 7
7 6
5 6
6 8
6 9
7 10
10 11
10 12

*/

