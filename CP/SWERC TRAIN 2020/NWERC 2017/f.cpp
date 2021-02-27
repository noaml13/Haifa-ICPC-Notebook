#include <bits/stdc++.h>
#define ii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7;

struct Seg{
    int n, sz;
    vi l, r;
    vector<vector<pair<ii, int>>> a;
    Seg(){}
    Seg(vi& l, vi& r): l(l), r(r), n(l.size()){
        for(sz=1;sz<n; sz*=2);
        a.resize(2*sz);
        l.resize(sz), r.resize(sz);
        loop(i,0,sz) a[i+sz] = {{{l[i], r[i]}, i}};
        loopr(i,1,sz){
            a[i].resize(a[2*i].size() + a[2*i+1].size());
            merge(all(a[2*i]), all(a[2*i+1]), a[i].begin());
        }
        loopr(i,1,sz){
            int m = a[i].size();
            loop(j,1,m) {
                if (a[i][j].x.y<a[i][j-1].x.y){
                    a[i][j].x.y = a[i][j-1].x.y;
                    a[i][j].y = a[i][j-1].y;
                }
            }
        }
    }
    int check(int i, int l, int r){
        pair<ii, int> p = {ii(l, -INF),-INF};
        int j = lower_bound(all(a[i]), p) - a[i].begin() - 1;
        if (j>=0 && a[i][j].x.y > r) return a[i][j].y;
        return -1;
    }
    int query(int l, int r){
        int ll = l, rr = r;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2==1){
                int v = check(l++,ll, rr);
                if (v!=-1) return v;
            }
            if (r%2==0){
                int v = check(r--,ll, rr);
                if (v!=-1) return v;
            }
        }
        return -1;
    }
};

const int MAX = 1e7 + 21;
vi f;
Seg seg;
void solve(int l, int r, int p=-1){
    if (l>r) return ;
    int ind = seg.query(l, r);
    if (ind == -1){
        cout<<"impossible"<<endl;
        exit(0);
    }
    f[ind] = p;
    solve(l, ind-1, ind);
    solve(ind+1, r, ind);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    vi div(MAX, -1);
    loop(i,2,MAX){
        if (div[i]!=-1) continue;
        for(int j = i; j<MAX; j+=i) div[j] = i;
    }
    int n; cin>>n;
    vvi ps(n);
    vi a(n); 
    loop(i,0,n) {
        cin>>a[i];
        int x = a[i];
        while(x>1){
            int p = div[x];
            while(x%p==0) x/=p;
            ps[i].pb(p);
        }
    }
    auto getL = [&](){
        vi res(n, -1);
        map<int, int> last;
        loop(i,0,n){
            for(auto p:ps[i]) {
                if(last.find(p)!=last.end()) chkmax(res[i], last[p]);
                last[p] = i;
            }
        }
        return res;
    };
    vi l = getL();
    reverse(all(ps));
    vi r = getL();
    reverse(all(r)); loop(i,0,n) r[i] = n-r[i]-1;
    reverse(all(ps));
    seg = Seg(l, r);
    f.resize(n);
    solve(0,n-1);
    loop(i,0,n) cout<<f[i]+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
6
2 7 15 8 9 6


6
2 7 15 8 9 5


*/