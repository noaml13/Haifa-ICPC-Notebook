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
const int INF = 1e14;

int hungarian(vvi& a){
    int n = a.size() - 1, m = a[0].size() - 1;
    vi u(n+1), v(m+1), p(m+1), way(m+1);
    loop(i,1,n+1){
        p[0] = i;
        int j0 = 0;
        vi minv(m+1, INF);
        vector<char> used(m+1, 0);
        do{
            used[j0] = 1;
            int i0 = p[j0], delta = INF, j1;
            loop(j,1,m+1){
                if (!used[j]){
                    int cur = a[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            }
            loop(j,0,m+1){
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else   
                    minv[j] -= delta;
            }
            j0 = j1;
        } while(p[j0]!=0);
        do{
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    return -v[0];
}
ii operator-(ii a, ii b){
    return {a.x-b.x, a.y-b.y};
}
int dist(ii a){
    return abs(a.x)+abs(a.y);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    // n,a is bottle
    vii a(n), b(m); 
    loop(i,0,n) cin>>a[i].x>>a[i].y;
    loop(i,0,m) cin>>b[i].x>>b[i].y;
    ii p; cin>>p.x>>p.y;
    for(auto &x:a) x = x-p;
    for(auto &x:b) x = x-p;
    int ans = 0;
    for(auto x:a) ans += dist(x);
    vvi d(n+1, vi(n+(m-1)+1));
    loop(i,0,n) loop(j,0,m) d[i+1][j+1] = dist(a[i]-b[j]);
    loop(i,0,n) loop(j,m,n+m-1) d[i+1][j+1] = dist(a[i]);
    ans += hungarian(d);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
2 1
1 1
0 -1
100 0
0 0

*/