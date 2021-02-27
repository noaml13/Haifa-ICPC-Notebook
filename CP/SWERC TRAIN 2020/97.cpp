#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;
 

struct Seg{
    int n,sz;
    vi a;
    Seg(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i){
        i+=sz;
        a[i]++;
        for(i/=2;i;i/=2){
            a[i] = a[2*i] + a[2*i+1];
        }
    }
    int query(int l, int r){
        int ans = 0;
        for(l+=sz,r+=sz; l<=r; l/=2, r/=2){
            if (l%2) ans+=a[l++];
            if (r%2==0) ans+=a[r--];
        }
        return ans;
    }
};  



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n);
    map<int, int> m;
    loop(i,0,n){
        cin>>a[i];
        m[a[i]];
    }
    int cnt = 0;
    for(auto &p:m) p.y=cnt++;
    loop(i,0,n) a[i] = m[a[i]];
    Seg seg(cnt+1);
    vi left(n);
    loop(i,0,n){
        left[i] = seg.query(a[i]+1, cnt);
        seg.update(a[i]);
    }
    seg = Seg(cnt+1);
    int ans = 0;
    loopr(i,0,n){
        ans += left[i] * seg.query(0, a[i]-1);
        seg.update(a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ 97.cpp -o a & a
3
3 2 1







RMQ 
1 2 5 100 789 -10 5
  |-------|
table - 2^n

complextiy - O(nlogn)/O(1)
dp[i][k] = min in arr[i...i+2^k]
dp[i][k] = min(dp[i][k-1], dp[i+2^(k-1)][k-1])


trivial:
bulid O(n)
update O(1)
query O(n)


segment tree:
bulid O(n)
update O(logn)
query O(logn)


*/