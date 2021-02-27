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


vvb tran(const vvb& a){
    int n = a[0].size(), m = a.size();
    vvb mat(n, vb(m));
    loop(i,0,n) loop(j,0,m) mat[i][j] = a[j][i];
    return mat;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vvb a(n, vb(m));
    loop(i,0,n) loop(j,0,m){
        char c; cin>>c;
        a[i][j] = (c=='B');
    }
    bool is_tran = 0;
    if (n<m) swap(n,m), a = tran(a), is_tran = 1;
    const int MAXM = 350;
    typedef bitset<MAXM> BIT;
    vector<vector<BIT>> rep(n+1,vector<BIT>(m, 0));
    loop(j,0,m) rep[0][j][j] = 1;
    loop(i,0,n) loop(j,0,m){
        rep[i+1][j] = rep[i][j];
        if (i) rep[i+1][j] ^= rep[i-1][j];
        if (j) rep[i+1][j] ^= rep[i][j-1];
        if (j+1<m) rep[i+1][j] ^= rep[i][j+1];
        rep[i+1][j][m] = rep[i+1][j][m] ^ a[i][j];
    }
    vector<BIT> mat(m, 0);
    loop(i,0,m) mat[i] = rep[n][i];
    // mat is (m) X (m+1)
    loop(i,0,m){
        int ind = -1;
        loop(j,i,m) if(mat[j][i]){
            ind = j;
            break;
        }
        if (ind == -1) continue; 
        swap(mat[i], mat[ind]);
        loop(j,0,m){
            if (j!=i && mat[j][i]) mat[j] ^= mat[i];
        }
    }
    loop(i,0,m) if (!mat[i][i] && mat[i][m]) return cout<<"IMPOSSIBLE"<<endl, 0;
    BIT vec = 0; vec[m] = 1;
    loop(i,0,m) vec[i] = mat[i][m];
    vvb ans(n, vb(m));
    loop(i,0,n) loop(j,0,m) ans[i][j] = (vec & rep[i][j]).count() % 2;
    if (is_tran) ans = tran(ans), swap(n,m);
    loop(i,0,n) {loop(j,0,m) cout<<(ans[i][j]?'P':'A')<<" "; cout<<endl;}
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
5 22
B B B W B W W W B W B B B W B B B B W B B B
B W W W B W W W B W B W W W B W W B W B W W
B B B W B W B W B W B B B W B B B B W B W W
W W B W B W B W B W B W W W B W B W W B W W
B B B W W B W B W W B B B W B W W B W B B B

3 3
B W B
W W W
W B B

2 2
B W
W W

1 2
B W


*/