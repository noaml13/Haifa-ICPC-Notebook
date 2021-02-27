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

struct LP{
    vi a,d;
    int sz,n;
    int h;
    LP(vi& _a){
        n = _a.size();
        for(sz=1, h=1;sz<n;sz<<=1,h++);
        a.resize(2*sz,-INF);
        d.resize(2*sz,0);
        loop(i,0,n) a[i+sz]=_a[i];
        for(int i=sz-1;i>0;--i){
            a[i] = max(a[i*2], a[i*2+1]);
        }
    }
    void apply(int cur, int v){
        a[cur] += v;
        if(cur<sz) d[cur] += v;
    }
    void build(int cur){
        for(cur>>=1;cur>0;cur>>=1){
            a[cur] = max(a[cur*2], a[cur*2+1]) + d[cur];
        }
    }
    void push(int cur){
        for(int s=h;s>0;--s){
            int i = cur >> s;
            if (d[i] != 0) {
                apply(i*2, d[i]);
                apply(i*2+1, d[i]);
                d[i] = 0;
            }
        }
    }
    void upd(int l,int r, int dif){
        l+=sz; r+=sz;
        int l0=l,r0=r;
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) apply(l++,dif);
            if(r&1==0) apply(r--,dif);
            if(l>r) break;
        }
        build(l0); build(r0);
    }
    int query(int l,int r){
        l+=sz; r+=sz;
        push(l); push(r);
        int res=0;
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) chkmax(res, a[l++]);
            if(r&1==0) chkmax(res, a[r--]);
            if(l>r) break;
        }
        return res;
    }
    void print(){
        loop(i,0,n){
            push(i+sz);
            cout<<a[i+sz]<<" ";
        }
        cout<<endl;
    }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vii con(n);
    loop(i,0,n) {
        cin>>con[i].x>>con[i].y;
        con[i].x--;
        con[i].y--;
    }
    sort(all(con));
    vi h(m);
    loop(i,0,m) h[i]=-i-1;
    LP lp(h);
    int coni=0;
    int res=max(int(0),n-m);
    for(int s=0;s<m;s++){
        while(coni<n && con[coni].x<s){
            lp.upd(con[coni].y,m-1,1);
            coni++;
        }
        chkmax(res, lp.query(s,m-1));
        lp.print();
        lp.upd(s,m-1,1);
    }
    cout<<endl;
    cout<<res<<endl;
    return 0;
}



