#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e; i++)
#define loopr(i,s,e) for(int i=e-1;i>=s; i--)
#define all(a) a.begin(),a.end()
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using namespace std;
const int MOD = 1e9+7;

const int M = 51;

int n,m;
bool mat[M][M];
int row[M], col[M];
bool check(){
    loop(i,0,n) row[i] = 0;
    loop(j,0,m) col[j] = 0;
    loop(i,0,n) loop(j,0,m) row[i]+=mat[i][j], col[j]+=mat[i][j];
    loop(i,0,n) loop(j,0,m){
        int x = row[i], y = col[j];
        if (!mat[i][j]) x = m-x, y = n-y;
        if (x<=1 && y<=1) return 0;
    }
    return 1;
}
int32_t main(){
    cin>>n>>m;
    int sz = 1<<(n*m);
    int ans = 0;
    loop(x,0,sz){
        loop(i,0,n){
            loop(j,0,m){
                int ind = i*m+j;
                mat[i][j] = x&(1<<ind);
            }
        }
        ans+=check();
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ cbrute.cpp -o a & a
3 3

*/