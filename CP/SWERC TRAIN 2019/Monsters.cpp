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
vi fib;


int find_ind(int x){
    if (x==1) return 2;
    int l = 0, r = fib.size() -1, mid;
    while(l<r){
        mid =  (l+r)/2;
        //cout<<"B "<<mid<<" " << fib[mid]<<endl;
        if (fib[mid]==x) return mid;
        else if(fib[mid]>x) r = mid;
        else l = mid + 1;
    }
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    fib.pb(0);
    fib.pb(1);
    loop(i,2, INF){
        fib.pb(fib[i-1] + fib[i -2]);
        if (fib[i]>1e7){
            break;
        }
    }
    int n; cin>>n;
    vi one;
    vii m;
    loop(i,0,n){
        int a; cin>>a;
        if (a==1) one.pb(i+1);
        a = find_ind(a);
        if (a!=-1) m.pb({a,i+1});
    }
    if (one.size()>=2){
        cout<<one[0]<<" "<<one[1]<<endl;
        return 0;
    }
    if (m.size()){
    sort(m.begin(), m.end());
    loop(i,0,m.size()-1){
        if (m[i+1].x - m[i].x==1){
            cout<<m[i].y<<" "<<m[i+1].y<<endl;
            return 0;
        }
    }
    }
    cout<<"impossible"<<endl;
    return 0;
}

