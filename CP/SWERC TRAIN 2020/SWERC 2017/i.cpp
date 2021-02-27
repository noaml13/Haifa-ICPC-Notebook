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
const int INF = 1e18;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    vector<string> ss(n);
    vector<string> d(n);
    loop(i,0,n) cin>>ss[i]>>d[i];
    //vvi vals(n, vi(m));
    vector<map<int, int>> vals(n+1);
    loop(i,0,n) loop(j,0,m){
        if (ss[i][j]!='-') vals[i][j] = ss[i][j] - '0';
    }
    loop(i,0,n) {
        int s = 0;
        vals[i][-INF-1] = 0;
        vals[i][-INF] = 0;
        vals[i][INF] = 0;
        for(auto &p:vals[i]) {
            s += p.y;
            p.y = s;
        }
    }
    vvi path(n+1);
    loop(i,0,n) loop(j,0,m) if(d[i][j]=='|') path[i+1].pb(j);
    //loop(i,0,n) cout<<path[i].size()<<endl;
    const int MAX = 20;
    vvi dp(MAX, vi(MAX)), next(MAX, vi(MAX, -INF));
    int ans = 0;
    loop(i,1,n-1){
        loop(x,0,path[i].size()) loop(y,0,path[i].size()){
            if (x==y) continue;
            int xx = path[i][x], yy = path[i][y];
            loop(a,0,path[i+1].size()) loop(b,0,path[i+1].size()){
                if (a==b) continue;
                int aa = path[i+1][a], bb = path[i+1][b];
                int mini = min(max(xx,yy), max(aa,bb)), maxi = max(min(xx,yy), min(aa,bb));
                if (maxi <= mini){
                    auto it = vals[i].lower_bound(maxi);
                    if (it->x <= mini) continue;
                    mini = min(min(xx,yy), min(aa,bb)), maxi = max(max(xx,yy), max(aa,bb));
                    auto be = prev(vals[i].upper_bound(mini));
                    auto en = vals[i].lower_bound(maxi);
                    chkmax(next[a][b], dp[x][y] + (en->y) - (prev(be)->y));
                }
                else{
                    int v = 0;
                    mini = min(xx, aa), maxi = max(xx, aa);
                    auto be1 = prev(vals[i].upper_bound(mini));
                    auto en1 = vals[i].lower_bound(maxi);
                    v += (en1->y) - (prev(be1)->y);
                    mini = min(yy, bb), maxi = max(yy, bb);
                    auto be2 = prev(vals[i].upper_bound(mini));
                    auto en2 = vals[i].lower_bound(maxi);
                    v += (en2->y) - (prev(be2)->y);
                    if (en1 == be2) v -= en1->y - prev(en1)->y;
                    if (en2 == be1) v -= en2->y - prev(en2)->y;
                    chkmax(next[a][b], dp[x][y] + v);
                }
            }
        }
        loop(x,0,path[i+1].size()) loop(y,0,path[i+1].size()) {
            if (x==y) continue;
            int xx = min(path[i+1][x],path[i+1][y]), yy = max(path[i+1][x],path[i+1][y]);
            auto be = prev(vals[i+1].upper_bound(xx));
            auto en = vals[i+1].lower_bound(yy);
            chkmax(ans, next[x][y] + (en->y) - (prev(be)->y));
        }
        swap(dp, next);
        loop(x,0,MAX) loop(y,0,MAX) next[x][y] = -INF;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ i.cpp -o a & a
5 20
--------------------
.|.....|...|......|.
1-1--1115-3-1-1--1-1
....|.........|.....
---1-11-1-11---1--3-
.......|.........|..
-7----9-4-----------
..|.................
--------9-----------
.|.................|



*/