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
const int INF = 1e18, MOD = 1e9;

void add(int &a, int b){
    a = (a+b)%MOD;
}
vvi operator*(vvi& a, vvi& b){
    int n = a.size();
    vvi res(n, vi(n));
    loop(i,0,n) loop(j,0,n) loop(k,0,n) add(res[i][j], a[i][k]*b[k][j]);
    return res;
}
vvi eye(int n){
    vvi res(n, vi(n));
    loop(i,0,n) res[i][i] = 1;
    return res;
}
vvi mpow(vvi& mat, int p){
    if (p==0) return eye(mat.size());
    vvi res = mpow(mat, p/2);
    res = res * res;
    if (p%2) res = res * mat;
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    int N = 1<<n, mask = N-1;
    vvi nums(n+1);
    loop(i,0,N) nums[__builtin_popcount(i)].pb(i);
    vvi mat(N);
    loop(ind,0,N){
        vi next(N);
        vvi dp(n+1, vi(N));
        dp[0][ind] = 1;
        loop(x,0,n+1){
            for(int i:nums[x]){
                loop(j,0,n){
                    if (dp[j][i]==0) continue;
                    add(dp[j+1][i], dp[j][i]);
                    if ((i & (1<<j))==0) {
                        add(dp[j+1][i | (1<<j)], dp[j][i]);
                        if (j+1<n && (i & (1<<(j+1)))==0) {
                            add(dp[j+2][i | (1<<j) | (1<<(j+1))], dp[j][i]);
                        }
                    }
                }
                add(next[mask ^ i], dp[n][i]);
                /*bool b = 1;
                vi inds, di;
                loop(j,0,n){
                    if ((i & (1<<j))==0) {
                        inds.pb(j);
                        if (j+1<n && (i & (1<<(j+1)))==0) {
                            di.pb(j);
                            //add(dp[i | (1<<j) | (1<<(j+1))], dp[i]);
                        }
                    }
                }*/
                //cout<<"HI: "<<i<<endl;
                //add(next[mask ^ i], dp[i]);
                //cout<<next[mask^i]<<endl;
            }
        }
        mat[ind] = next;
    }
    //mat[0][mask] = mat[mask][0] = 3;
    //loop(i,0,N){ loop(j,0,N) cout<<mat[i][j]<<" "; cout<<endl;}
    mat = mpow(mat, m);
    cout<<mat[0][0]<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
2
2



*/