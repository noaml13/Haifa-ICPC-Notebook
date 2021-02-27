#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define loop(i,s,e) for(int i=(s); i<(e); i++)
#define loopr(i,s,e) for(int i=(e)-1; i>=(s); i--)
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define all(a) a.begin(),a.end()
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max(a,b)
using namespace std;

const int LOGN = 19;
int main(){
    int n,q; cin>>n;
    vi a(n); 
    loop(i,0,n) cin>>a[i];
    vi back[LOGN]; // zero is trap, one is empty segment
    loop(i,0,LOGN) back[i].resize(n+2, 0);
    map<int, int> last; last[1] = 0;
    int sum = 0;
    loop(i,0,n){
        sum += a[i];
        back[0][i+2] = last[sum];
        last[sum] = i+2;
    }
    loop(k,1,LOGN){
        int sz = 1<<(k-1);
        loop(i,0,n+2){
            back[k][i] = back[k-1][back[k-1][i]];
        }
    }
    cin>>q;
    loop(qq,0,q){
        int a,b; cin>>a>>b; b++;
        int ans = 0;
        loopr(i,0,LOGN){
            if (back[b][i]>=a){
                ans += 1<<i;
                b = back[b][i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
color 
cls
g++ SumZero.cpp -o a & a

*/