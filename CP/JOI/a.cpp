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

ii operator+(ii a, ii b){
    return {a.x+b.x, a.y+b.y};
}
struct TopLane{
    int n,m;
    vvi dp;
    vii lane;
    TopLane(vvi& b):dp(b){
        n = b.size(), m = b[0].size();
        //loop(i,0,n) loop(j,0,m) if(dp[i][j]==0) dp[i][j] = -1;
        lane.resize(n+m-1);
        lane[n+m-2] = {n-1,m-1}; dp[n-1][m-1] = 2; //right bot is win
        dfs(0,0);
    }
    bool dfs(int i, int j){
        if (!in(i,j)) return 0;
        if (dp[i][j]==1) return 0;
        if (dp[i][j]==2) return 1;
        if (dfs(i,j+1)) dp[i][j] = 2;
        else if (dfs(i+1,j)) dp[i][j] = 2;
        if (dp[i][j]==2){
            lane[i+j] = {i,j};
            return 1;
        }
        dp[i][j] = 1;
        return 0;
    }
    void out(int i, int j){
        dp[i][j] = 1;
        if (lane[i+j]!=ii({i,j})) return ;
        int ind = i+j - 1;
        for(;1;ind--){
            dp[lane[ind+1].x][lane[ind+1].y] = 1; //last is block
            if (lane[ind].x!=lane[ind+1].x) continue;
            if (dfs(lane[ind].x+1, lane[ind].y)) break;
        }
    }
    bool in(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
};
int n,m;
int conv(int i, int j){
    return m*i+j;
}
bool in(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}
ii T(ii a){
    return {a.y, a.x};
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    vvi bb(n, vi(m)), bT(m, vi(n));

    loop(i,0,n){
        loop(j,0,m){
            cin>>bb[i][j];
            bT[j][i] = bb[i][j];
        }
    }
    TopLane top(bb), bot(bT);
    int q; cin>>q;
    loop(i,0,q){
        int a,b; cin>>a>>b; a--; b--;
        int ans = 0;
        int ind = a+b;
        if (bb[a][b]==0 && (top.lane[ind] != ii(a,b) || bot.lane[ind]!=ii(b,a))){
            ans = 1;
            bb[a][b] = 1;
            top.out(a,b);
            bot.out(b,a);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
4 4
0 0 1 0
0 0 0 0 
1 1 1 0 
0 0 0 0
100


*/
