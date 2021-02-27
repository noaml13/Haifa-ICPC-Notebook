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
const int INF = 1e18, MOD = 998244353;
 
const int N=15, M=1<<N;
int dp[N+1][M][N+1];
ii mini[N+1][M][N+1];
ii op[N+1][M][N+1];
int sum[M];
int n;
inline void const_mini(int i, int s){
    mini[i][s][0] = {dp[i][s][0],0};
    loop(pos,1,n+1)  mini[i][s][pos] = min(mini[i][s][pos-1], ii(dp[i][s][pos], pos));
}
inline void add(vi &a, int s){
    loop(i,s,n) a[i]++;
}
int solve(){
    cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    int m = (1<<n);
    loop(s,0,m){
        sum[s] = 0;
        loop(i,0,n){
            if (s & (1<<i)) sum[s]+=a[i];
        }
    }
    loop(i,0,m) loop(pos,0,n+1) dp[0][i][pos] = INF;
    dp[0][0][0] = 0; op[0][0][0] = {-1,-1};
    loop(s,0,m) const_mini(0,s);
    int fini = 0, fins = 0, finp = 0;
    loop(i,1,n+1){
        //cout<<"I: "<<i<<endl;
        loop(s,0,m){
            loop(pos,0,n+1){
                int &v = dp[i][s][pos] = INF;
                ii &oo = op[i][s][pos] = {-1,-1};
                if (pos==0) continue;
                if ((s & (1<<(pos-1))) == 0) continue;
                for(int part = s; ; part = (part-1)&s){
                    if (part==s) continue;
                    if (part & (1<<(pos-1))) continue;
                    int last = sum[s^part];
                    if (mini[i-1][part][pos-1].x<last) {
                        if (v>last){
                            v = last;
                            oo = {part, mini[i-1][part][pos-1].y};
                        }
                    }
                    if (part==0) break;
                }
                if (v!=INF && s==m-1) {
                    fini = i;
                    fins = s;
                    finp = pos;
                }
            }
            const_mini(i,s);
        }
    }
    vi minus(n,0);
    vii ans;
    while(fini){
        ii oo = op[fini][fins][finp];
        int part = oo.x, pp = oo.y;
        int take = fins ^ part;
        loop(i,0,n){
            if (i==finp-1) continue;
            if (take & (1<<i)){
                ans.pb({finp-1 - minus[finp-1], i - minus[i]});
                add(minus, i);
            }
        }
        finp = pp;
        fins=part;
        fini--;
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.y+1<<" "<<p.x+1<<endl;
    return 0;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
4
8
2 1 3 5 1 2 4 5
15
16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
2
3 3
14
1 2 3 4 5 6 7 8 9 10 11 12 13 14
 
 
 
 
*/