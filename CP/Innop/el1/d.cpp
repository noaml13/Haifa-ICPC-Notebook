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
    int s,k; cin>>k>>s;
    if (k==1){
        cout<<1<<endl;
        cout<<0<<endl;
        return 0;
    }
    if (k==2){
        cout<<2<<endl;
        cout<<"1 3"<<endl;
        return 0;
    }
    cout<<k-1<<endl;
    int cur = 1;
    loop(i,0,k-1){
        cout<<cur<<" ";
        cur<<=1;
    }
    return 0;
}

