/*
ID: licht.n1
PROG: haircut
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9;

struct SEG {
    int n,sz;
    vi a;
    SEG(int _n){
        n=_n;
        for(sz=1;sz<n;sz<<=1);
        a.resize(sz*2,0);
    }
    void update(int i, int val){
        i+=sz;
        a[i] += val;
        for(i>>=1;i;i>>=1){
            a[i] = a[i*2] + a[i*2+1];
        }
    }
    int query(int l, int r){
        int ans=0;
        for(l+=sz,r+=sz;l<=r;l>>=1,r>>=1){
            if (l%2) ans+=a[l++];
            if (r%2==0) ans+=a[r--];
            if (l>r) break;
        }
        return ans;
    }
};

int32_t main() {
    ofstream cout("haircut.out");
    ifstream cin("haircut.in");
    int n; cin>>n;
    int sz = n+3;
    SEG seg(sz);
    vi ans(sz,0);
    loop(i,0,n){
        int a; cin>>a;
        ans[a+1]+=seg.query(a+1, sz-1);
        seg.update(a,1);
    }
    loop(i,1,n) ans[i]+=ans[i-1];
    loop(i,0,n) cout<<ans[i]<<endl;
    return 0;
}
/*
color a
cls
g++ haircut.cpp -o a & a
5
5 2 3 3 0
*/
