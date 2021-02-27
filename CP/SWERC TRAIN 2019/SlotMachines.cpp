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
const int INF=4e18;



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    reverse(all(a));
    int p = 1, m=n;
    ii ans = {1,n-1};
    loop(i,1,n){
        if(a[i] != a[i-p]) p = i+1;
        if (m> p + (n-i-1) || ((m==p + (n-i-1)) && ans.x > p) ){
            m = p + (n-i-1);
            ans = {p, n-i-1};
        }
    }
    cout<<ans.y<<" "<<ans.x<<endl;
    return 0;
}




