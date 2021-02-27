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
const int BY = INF;

vvii g;
vi dp, cnt, depth;
vi ans;
void dfs(int cur, int p=-1, int d=0){
    depth[cur] = d;
    dp[cur] = d;
    for(auto nei:g[cur]) if(nei.y!=p){
        if (depth[nei.x]==-1){
            dfs(nei.x, nei.y, d+1);
            chkmin(dp[cur], dp[nei.x]);
            cnt[cur] += cnt[nei.x];
        }
        else{
            ans[nei.y] = BY;
            chkmin(dp[cur], depth[nei.x]);
        }
    }
    if (p!=-1){
        if (dp[cur]==d){ //bridge
            if (cnt[cur]==0) ans[p]=BY; //DONT HAVE ENYTHING ON BOTH SIDES
            else if (cnt[cur]>0) ans[p]=(cur+1);
            else ans[p] = -(cur+1);
        }
        else ans[p] = BY; //part of cycle
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    g.resize(n); dp.resize(n); cnt.resize(n); depth.resize(n,-1);
    ans.resize(m,-BY);
    vi edgea(m);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb({b,i}); 
        if (a!=b) g[b].pb({a,i});
        edgea[i] = a;
    }
    int p; cin>>p;
    loop(i,0,p){
        int a,b; cin>>a>>b; a--; b--;
        cnt[a]++; cnt[b]--;
    }
    loop(i,0,n) if (depth[i]==-1) dfs(i);
    loop(i,0,m){
        if (ans[i]==-BY) loop(i,0,INF) i--;
        else if (ans[i]==BY) cout<<'B';
        else{
            int x = abs(ans[i])-1, sign = ans[i]>0;
            cout<<(((x==edgea[i]) ^ (sign))?'L':'R');
        }
    }
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
5 6
1 2
1 2
4 3
2 3
1 3
5 1
2
4 5
1 3
*/



