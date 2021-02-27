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
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9 + 7;

struct SEG{
    int sz;
    vi a;
    SEG(int n){
        for(sz=1; sz<n; sz*=2);
        a.resize(2*sz,INF);
    }
    void update(int i, int x){
        i+=sz;
        a[i] = x;
        for(i/=2;i; i/=2) a[i] = min(a[2*i], a[2*i+1]);
    }
    int query(int l, int r){
        int res = INF;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2==1) res = min(res, a[l++]);
            if (r%2==0) res = min(res, a[r--]);
        }
        return res;
    }
};

struct Node{ // space: O(min(Q*logMAX, MAX))
    int l,r,mid; // [l,r)
    int v=0;
    int prop = 0;
    Node *lp=0, *rp=0;
    Node(int l, int r): l(l), r(r), mid((l+r)/2){}
    void add(int x){
        prop+=x;
        v+=(r-l)*x;
    }
    void fix(){
        if (!lp) lp = new Node(l, mid);
        if (!rp) rp = new Node(mid, r);
        if (prop){
            lp->add(prop);
            rp->add(prop);
            prop = 0;
        }
        v = lp->v + rp->v;
    }
    int query(int a, int b){ // [a,b)
        if (a>=r || b<=l) return INF;
        if (a<=l && r<=b) return v;
        fix();
        return lp->query(a,b) + rp->query(a,b);
    }
    void updateI(int i, int x){
        if (l+1==r){
            v = x;
            return ;
        }
        fix();
        if (i<mid) lp->updateI(i, x);
        else rp->updateI(i, x);
        fix();
    }
    void update(int a, int b, int x){
        if (a>=r || b<=l) return ;
        if (a<=l && r<=b) {
            add(x);
            return ;
        }
        fix();
        lp->update(a,b,x);
        rp->update(a,b,x);
        fix();
    }
};





int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    map<int, int> conv;
    loop(i,0,n) conv[a[i]];
    int cnt = 0;
    for(auto p:conv) p.y = cnt++;
    loop(i,0,n) a[i] = conv[a[i]];

    return 0;
}
/*
color a
cls
g++ CoinCollector.cpp -o a & a

*/