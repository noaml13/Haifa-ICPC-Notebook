#include <bits/stdc++.h>
#define int int64_t
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
const int INF=4e18;



int32_t main(){
    ios_base::sync_with_stdio(false);
    //unsigned long long x = (unsigned long long)(1)<<64-1;
    //cout<<(x)<<endl;
    unsigned long long a,b,c,n; cin>>a>>b>>c>>n;
    unsigned long long ans;
    if (n%2) ans = (n * (((n-1)/2) * ((n+1)/2))/2 ) / 3;
    else ans = (n * (n-2 + (n/2)*(n/2-1)/2 ) ) / 3;
    int mult;
    if (a==b && b==c) mult = 1;
    else if (a==b || b==c) mult=3;
    else mult = 6;
    ans *= mult;
    cout<<ans<<endl;
    return 0;
}




