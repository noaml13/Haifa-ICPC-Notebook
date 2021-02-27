#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
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
    int n=1001;
    int a,b,x; cin>>a>>b>>x;
    int m = 0;
    loop(i,0,n){
        loop(j,0,n){
            if (a*i+b*j>1000) break;
            if (i*a*100 == x * (i*a + j * b)) chkmax(m, i*a+b*j);
        }
    }
    cout<<m<<endl;
    return 0;
}
