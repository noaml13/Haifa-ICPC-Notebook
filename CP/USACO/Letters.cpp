#include <bits/stdc++.h>
// #define int int64_t
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
const int INF = 1e9, MOD = 1e9+7;

struct Rect{
    int n,m, res=0, cnt = 1;
    vi up, down, left, right;
    vi u,d,l,r;
};
Rect getRect(int n, int m){
    Rect r;
    r.n = n, r.m = m;
    r.u = r.d = r.up = r.down = vi(m, 0);
    r.l = r.r = r.left = r.right = vi(n, 0);
    return r;
}
Rect getRect(int x){
    Rect r;
    r.n = r.m = 1;
    r.u = r.d = r.l = r.r = vi(1, 0);
    r.up = r.down = r.left = r.right = vi(1,x);
    return r;
}
void flip(Rect &r){
    swap(r.n, r.m);
    swap(r.up, r.left);
    swap(r.down, r.right);
    swap(r.u, r.l);
    swap(r.d, r.r);
}
int getRes(const Rect &r){
    return r.res + r.cnt;
}
void print(const Rect &r){
    cout<<"RECT "<<getRes(r)<<endl;
    loop(i,0,r.n) cout<<char(r.right[i])<<" "; 
    cout<<endl;
    loop(i,0,r.n) cout<<r.l[i]<<" "; 
    cout<<endl;
    loop(i,0,r.n) cout<<r.r[i]<<" "; 
    cout<<endl;
    cout<<endl;
}
Rect combX(const Rect &a, const Rect &b){
    int n = a.n, m1 = a.m, m2 = b.m;
    Rect c = getRect(n, m1 + m2);
    c.res = a.res + b.res;
    c.left = a.left, c.right = b.right;
    //print(a), print(b);
    loop(i,0,m1) c.up[i] = a.up[i], c.down[i] = a.down[i];
    loop(i,0,m2) c.up[m1 + i] = b.up[i], c.down[m1 + i] = b.down[i];
    int sz1 = a.cnt, sz2 = b.cnt;
    vvi ag(sz1), bg(sz2);
    loop(i,0,n) if(a.right[i] == b.left[i]) {
        ag[a.r[i]].pb(b.l[i]);
        bg[b.l[i]].pb(a.r[i]);
    }
    vi c1(sz1, -1), c2(sz2, -1);
    int cnt = 0;
    auto dfs = [&](int i, int sd){
        vii st = {{i,sd}};
        if (sd) c2[i] = cnt;
        else c1[i] = cnt;
        //cout<<"HI: "<<endl;
        while(st.size()){
            int cur = st.back().x, sd = st.back().y; st.pop_back();
            if (sd) {
                for(int nei:bg[cur]) if (c1[nei]<0){
                    c1[nei] = cnt;
                    st.pb({nei, 0});
                }
            }
            else {
                //cout<<"CUR: "<<cur<<" "<<sd<<endl;
                for(int nei:ag[cur]) if (c2[nei]<0){
                    c2[nei] = cnt;
                    st.pb({nei, 1});
                }
            }
        }
        //cout<<"BI: "<<endl;
        cnt++;
    };
    loop(i,0,n) c1[a.l[i]] = c2[b.r[i]] = -2;
    loop(i,0,m1) c1[a.u[i]] = c1[a.d[i]] = -2;
    loop(i,0,m2) c2[b.u[i]] = c2[b.d[i]] = -2;
    loop(i,0,sz1) if (c1[i]==-2) dfs(i, 0);
    loop(i,0,sz2) if (c2[i]==-2) dfs(i, 1);
    loop(i,0,n) c.l[i] = c1[a.l[i]];
    loop(i,0,n) c.r[i] = c2[b.r[i]];
    loop(i,0,m1) c.u[i] = c1[a.u[i]], c.d[i] = c1[a.d[i]];
    loop(i,0,m2) c.u[m1 + i] = c2[b.u[i]], c.d[m1 + i] = c2[b.d[i]];
    c.cnt = cnt;
    //cout<<"N: "<<n<<" "<<b.n<<" "<<m1<<" "<<m2<<endl;
    loop(i,0,n) if (c1[a.r[i]]==-1) dfs(a.r[i], 0), c.res++;
    loop(i,0,n) if (c2[b.l[i]]==-1) dfs(b.l[i], 1), c.res++;
    return c;
}
Rect combY(Rect a, Rect b){
    flip(a), flip(b);
    Rect c = combX(a,b);
    flip(c);
    return c;
}
struct SEG{
    int n, sz;
    vector<Rect> a;
    SEG(){}
    SEG(SEG &up, SEG &down): sz(up.sz), n(up.n){
        a.resize(2*sz);
        loop(i,1,2*sz) a[i] = combY(up.a[i], down.a[i]);
    }
    SEG(vi arr): n(arr.size()){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
        arr.resize(sz);
        loop(i,0,sz) a[i+sz] = getRect(arr[i]);
        loopr(i,1,sz) a[i] = combX(a[2*i], a[2*i+1]);
    }
    Rect query(int l, int r){
        Rect lr, rr;
        bool fl=1, fr=1;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            //cout<<"LR: "<<l<<" "<<r<<endl;
            if (l%2==1) {
                if (fl) fl = 0, lr = a[l++];
                else lr = combX(lr, a[l++]);
            }
            if (r%2==0) {
                if (fr) fr = 0, rr = a[r--];
                else rr = combX(a[r--], rr);
            }
        }
        if (fl) return rr;
        if (fr) return lr;
        return combX(lr, rr);
    }
};
struct SEG2D{
    int n, sz;
    vector<SEG> a;
    SEG2D(vvi arr): n(arr.size()){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
        arr.resize(sz, arr[0]);
        loop(i,0,sz) a[i+sz] = SEG(arr[i]);
        loopr(i,1,sz) {
            a[i] = SEG(a[2*i], a[2*i+1]);
        }
    }
    Rect query(int l, int r, int ly, int ry){
        Rect lr, rr;
        bool fl=1, fr=1;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2==1) {
                if (fl) fl = 0, lr = a[l++].query(ly, ry);
                else lr = combY(lr, a[l++].query(ly, ry));
            }
            if (r%2==0) {
                if (fr) fr = 0, rr = a[r--].query(ly, ry);
                else rr = combY(a[r--].query(ly, ry), rr);
            }
        }
        if (fl) return rr;
        if (fr) return lr;
        return combY(lr, rr);
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,q; cin>>n>>m>>q;
    vector<string> s(n);
    loop(i,0,n) cin>>s[i];
    vvi a(n, vi(m));
    loop(i,0,n) loop(j,0,m) a[i][j] = s[i][j];
    SEG2D seg(a);
    //loop(i,1,2*seg.sz) print(seg.a[i]);
    loop(ind,0,q){
        int ax,ay,bx,by; 
        cin>>ax>>ay>>bx>>by;
        ax--,ay--,bx--,by--;
        Rect r = seg.query(ax, bx, ay, by); 
        /*bool f = 1;
        loop(i,ax,bx+1){
            Rect row = getRect(a[i][ay]);
            loop(j,ay+1,by+1) row = combX(row, getRect(a[i][j]));
            if (f) r = row, f = 0;
            else r = combY(r, row);
        }*/
        /*int nn = bx - ax + 1, mm = by - ay + 1;
        loop(i,0,mm) cout<<char(r.up[i])<<" "; cout<<endl;*/
        // print(r);
        cout << r.res + r.cnt << endl;
    }
    return 0;
}
/*
color a
cls
g++ Letters.cpp -o a & a
4 8 9
ABBAAAAA
ABAAAABA
CAADABBA
AAAAAAAA
1 1 4 8
3 5 3 8
1 3 2 4
1 4 2 5
1 1 3 3
4 4 4 4
2 6 4 8
3 5 4 6
1 6 3 8


4 8 3
AAAAAAAA
AAAAAAAA
CAADAAAA
AAAAAAAA
1 1 1 2
1 1 1 1
1 1 2 2



*/