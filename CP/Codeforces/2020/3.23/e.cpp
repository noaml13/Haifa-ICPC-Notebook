#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
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
const int INF = 1e18, MOD=998244353;

void add(int &a, int b){
    a = (a+b)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi pow(n+1,1);
    loop(i,1,n+1) pow[i]=(pow[i-1]*10)%MOD;
    loop(k,1,n){
        int x = (n-k+1) - 2;//boundry
        int mult = (pow[n-2-(k-1)] * 81) %MOD;
        int ans=0;
        if (x>0) add(ans,(mult*x)%MOD);
        add(ans,(pow[n-1-(k-1)] * 9 * 2) %MOD);
        cout<<ans<<" ";
    }
    cout<<10<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
1

*/




