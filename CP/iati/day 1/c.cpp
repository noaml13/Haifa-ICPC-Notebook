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

void add(int &a, int b){ a = (a+b)%MOD;}
int32_t main(){
    int n,m; cin>>n>>m;
    if (n<m) swap(n,m);
    int dp[8][8][8][8], next[8][8][8][8];
    loop(a,0,m+1) loop(b,0,m+1) loop(c,0,m+1) loop(d,0,m+1) {
        dp[a][b][c][d] = next[a][b][c][d] = 0;
    }
    dp[0][0][0][0] = 1;
    int sz = 1<<m;
    int ind;
    loop(_,0,n){
        loop(a,0,m+1) loop(b,0,m+1) {
            if (a+b>m) continue;
            vi x(m);
            ind = 0;
            loop(k,0,b) x[ind++] = 2;
            loop(k,0,a) x[ind++] = 1;
            loop(c,0,m+1) loop(d,0,m+1){
                if (c+d>m || dp[a][b][c][d]==0) continue;
                cout<<"HI: "<<_<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<dp[a][b][c][d]<<endl;
                vi y(m);
                ind = 0;
                loop(k,0,d) y[ind++] = 2;
                loop(k,0,c) y[ind++] = 1;
                loop(nn,0,sz){
                    vb num(m);
                    int cnt = 0;
                    loop(k,0,m) num[k] = nn&(1<<k), cnt+=num[k];
                    int aa = 0, bb=0,cc=0, dd=0;
                    if (cnt==1){
                        loop(k,0,m) {
                            if(x[k]==2 || (x[k]==1 && num[k]==0)) bb++;
                            else if(x[k]==1 || num[k]==0) aa++;
                        }
                    }
                    else{
                        loop(k,0,m) {
                            if(num[k]==0 || x[k]==2) bb++;
                            else if(x[k]==1) aa++;
                        }
                    }
                    if(cnt==m-1){
                        loop(k,0,m) {
                            if(y[k]==2 || (y[k]==1 && num[k]==1)) dd++;
                            else if(y[k]==1 || num[k]==1) cc++;
                        }
                    }
                    else{
                        loop(k,0,m) {
                            if(num[k]==1 || y[k]==2) dd++;
                            else if(y[k]==1) cc++;
                        }
                    }
                    cout<<"ADD: "<<nn<<" : "<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" += "<<dp[a][b][c][d]<<endl;
                    add(next[aa][bb][cc][dd], dp[a][b][c][d]);
                }
            }
        }
        loop(a,0,m+1) loop(b,0,m+1) loop(c,0,m+1) loop(d,0,m+1) {
            dp[a][b][c][d] = next[a][b][c][d], next[a][b][c][d] = 0;
        }
    }
    int ans = 0;
    loop(b,0,m+1) loop(d,0,m+1) add(ans, dp[0][b][0][d]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
2 2


3 3 
*/