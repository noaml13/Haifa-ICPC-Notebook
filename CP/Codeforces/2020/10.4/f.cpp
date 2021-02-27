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
const int INF = 4e18, MOD = 1e9 + 7;

struct Node{
    int v=1;
    int l,r,mid;
    Node *lp=0, *rp=0;
    Node(int l, int r): l(l), r(r), mid((l+r)/2){}
    void fix(){
        if (!lp) lp = new Node(l, mid);
        if (!rp) rp = new Node(mid,r);
    }
    void update(int a, int b, int x){
        if (a>=r || b<=l) return;
        if (a<=l && r<=b){
            v = v * x % MOD;
            return ;
        }
        fix();
        lp->update(a,b,x);
        rp->update(a,b,x);
    }
    int query(int i){
        if (l == r-1) return v;
        //cout<<"QUERY: "<<l<<" "<<r<<" "<<v<<endl;
        if (i<mid) return v * (lp?lp->query(i):1)%MOD;
        return v * (rp?rp->query(i):1)%MOD;
    }
};
struct SEG2{
    int n, sz;
    vector<Node*> a;
    SEG2(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
        loop(i,1,2*sz) a[i] = new Node(0,n);
    }
    void update(int l, int r, int ly, int ry, int x){
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) {
                //cout<<"YY: "<<l<<" "<<r<<endl;
                a[l++]->update(ly, ry, x);
            }
            if (r%2==0) {
                //cout<<"YY: "<<l<<" "<<r<<endl;
                a[r--]->update(ly, ry, x);
            }
        }
    }
    int query(int i, int j){
        int res = 1;
        for(i+=sz; i; i/=2){
            res = res * a[i]->query(j) % MOD;
            //cout<<"RES: "<<i<<" "<<res<<" "<<j<<endl;
        }
        return res;
    }
};
struct SEG{
    int n, sz;
    vi a, sum;
    SEG(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz,0);
        sum.resize(2*sz,0);
    }
    void update(int i, int x){
        i+=sz; a[i]+=x; sum[i]+=x;
        //cout<<"HI: "<<i<<" "<<x<<endl;
        for(i/=2; i; i/=2) {
            a[i] = max(a[2*i], a[2*i+1]);
            sum[i] = sum[2*i] + sum[2*i+1];
        }
    }
    ii query(int l, int r){
        int res = 0, s=0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res, a[l]), s+=sum[l++];
            if (r%2==0) chkmax(res, a[r]), s+=sum[r--];
        }
        return {res,s};
    }
};
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) %MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int m = 1;
    vi a(n); loop(i,0,n) cin>>a[i], chkmax(m, a[i]);
    m+=10;
    vi big(m,1);
    loop(i,1,m){
        if (big[i]!=1) continue;
        for(int j=2*i;j<m;j+=i) chkmax(big[j], i);
    }
    vvii ps;
    map<int, vi> inds;
    loop(i,0,n){
        int x = a[i];
        vi ps;
        while(big[x]!=1){
            ps.pb(big[x]);
            x = x/big[x];
        }
        if (x) ps.pb(x);
        for(auto p:ps){
            inds[p].pb(i);
        }
    }
    vector<SEG> segs;
    vi vals;
    SEG2 seg2(n+2);
    for(auto p:inds){
        if (p.x==1) continue;
        vi& vec = p.y;
        int r = vec.size();
        bool b = 0;
        loop(i,0,r-1) if (vec[i]==vec[i+1]) b = 1;
        if (b){
            segs.pb(SEG(n));
            loop(i,0,r) segs.back().update(vec[i], 1);
            vals.pb(p.x);
        }
        else{
            int inv = pp(p.x, MOD - 2);
            loop(i,0,r-1){
                int a = vec[i], b = vec[i+1];
                //cout<<"AB: "<<a<<" "<<b<<" "<<p.x<<endl;
                seg2.update(0, a, b, n, p.x);
            }
        }
    }
    vi pref(n+1,1);
    loop(i,0,n) pref[i+1] = pref[i] * a[i] % MOD;
    int q; cin>>q;
    int last = 0, r = segs.size();
    loop(i,0,q){
        int x,y; cin>>x>>y;
        //cout<<"XY: "<<x<<" "<<y<<endl;
        x = (x+last)%n, y = (y+last)%n;
        if (x>y) swap(x,y);
        //cout<<"XY: "<<x<<" "<<y<<endl;
        int ans = pref[y+1] * pp(pref[x], MOD-2) % MOD;
        ans = ans * pp(seg2.query(x,y), MOD-2) % MOD;
        //cout<<"ANS: "<<x<<" "<<y<<"  : "<<ans<<" "<<endl<<seg2.query(x,y)<<endl;
        loop(j,0,r){
            ii res = segs[j].query(x, y);
            int amt = res.y - res.x;
            ans = ans * pp(pp(vals[j], amt), MOD-2) % MOD;
        }
        //cout<<"ANS: "<<x<<" "<<y<<"  : "<<ans<<endl;
        cout<<ans<<endl;
        last = ans;
    }
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
10
10 2 8 8 8 8 8 10 2 3
10
1 2
6 1
4 10
1 9
9 1
6 10
3 3
8 1
4 10
6 7

*/