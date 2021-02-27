#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define iiii pair<ii,ii>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
using ull=unsigned long long;
const ull INF=4e18;
const int MAXN=19;
vi arr;
vector<bool> overflow(MAXN,false);
int x[MAXN], y[MAXN];
int a[MAXN];
int sz;
ull ans=0;

void equal_solve(int n){
    loop(i,0,(n+1)/2) if (a[i]!=a[n-i-1]) return ;
    ull op = 1;
    for(int i=0;i<(n+1)/2;i++){
        int m = 0;
        loop(d,0,10){
            if (i==0){
                if (d>0 && a[i]-d>0 && a[i]-d<10) m++;
            }
            else{
                if (a[i]-d>=0 && a[i]-d<10) m++;
            }
        }
        op *= m;
    }
    ans += op;
}
void dif_solve(int n, int k){
    loop(i,0,n) y[i]=0;
    for(int i=0;i<(n+1)/2;i++){
        x[i] = a[n-i-1] - y[n-i-1];
        x[n-i-1] = x[i];
        if (i<(k+1)/2){
            y[i] = a[i] - x[i];
            y[k-i-1] = y[i];
        }
    }
    if (x[0]==0)return;
    if (y[0]==0) return;
    loop(i,0,n){
        if (a[i]!=x[i]+y[i]) return;
        if (x[i]<0 || x[i]>9) return;
        if (y[i]<0 || y[i]>9) return;
    }
    ans+=2;
}

void solve(){
    int n=sz;
    loop(i,0,sz) {
        a[i] = arr[i] + overflow[i]*10 - (i>0?overflow[i-1]:0);
        if (a[i]<0) return;
    }
    while(n>0 && a[n-1]==0) n--;
    if (n==0) return;
    equal_solve(n);
    loop(i,1,n) dif_solve(n, i);
    /*for(auto d: a) cerr<<d<<" ";
    cerr<<endl;
    cerr<<ans<<endl;*/
}

void dfs(int depth){
    if (depth<0) return solve();
    overflow[depth] = false;
    dfs(depth-1);
    overflow[depth] = true;
    dfs(depth-1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ull n;
    cin>>n;
    //n = 12456245123546845;
    while(n>0){
        arr.pb(n%10);
        n/=10;
    }
    sz = arr.size();
    dfs(sz-2);
    cout<< ans<<endl;
    return 0;
}







