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
const int INF = 4e18;

struct SEG{
    int n, sz;
    vii a;
    SEG(const vi& arr): n(arr.size()){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
        loop(i,0,n) a[i+sz] = {arr[i],i};
        loopr(i,1,sz) a[i] = max(a[2*i], a[2*i+1]);
    }
    int query(int l, int r){
        ii res = {0,-1};
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res, a[l++]);
            if (r%2==0) chkmax(res, a[r--]);
        }
        return res.y;
    }
};
int partial(int x){
    return (x*(x+1))/2;
}
int trip(int x){
    return (partial(x)*(2*x+1))/3;
}
int in(int x){
    int ans = partial(x) + trip(x);
    return ans/2 -x;
    /*int ans = 0;
    loop(i,0,x) ans+=partial(x-i);
    return ans-x;*/
}
int getv(int cnt, int sz){
    return max(partial(cnt)-partial(max(int(0), sz)),0LL);
}
int getvv(int a, int b, int base){
    if (a<=0 || b<=0) return 0;
    if (a>b) swap(a,b);
    int ans = 0;
    ans += base * partial(b) + trip(a);
    ans += base * partial(a) + trip(a);
    ans+=a*(partial(b)-partial(a));
    ans+=base * (b-a);
    ans -= (partial(base+a) - partial(base));

    /*loop(i,1,a+1){
        ans+=(base+i) * min(i,b);
    }
    loop(i,1,b+1){
        ans+=(base+i) * min(i,a);
    }
    loop(i,1,min(a,b)+1){
        ans-=base+i;
    }*/
    return ans;
}
int n;
string s;
int ans = 0;
vector<pair<int, ii>> segs;
SEG seg(vi(0));
void solve(int l, int r, int lx, int rx, int cntl=0, int cntr=0){    
    if (l>r){ 
        ans+=getvv(cntl, cntr, 0);    
        //cout<<"CNT: "<<cntl<<" "<<cntr<<endl;
        //cout<<"ANS: "<<ans<<" "<<lx<<" "<<rx<<" "<<getvv(cntr, cntl,0)<<endl;
        ans+=(rx-lx+1-cntl-cntr)*(partial(cntl)+partial(cntr));
        return ;
    }
    int i = seg.query(l, r);
    //cout<<"S: "<<lx<<" "<<rx<<" "<<i<<" "<<l<<" "<<r<<endl;
    int sz = segs[i].x;
    int ls = segs[i].y.x, rs = segs[i].y.y;
    int szl = max(int(0), cntl-sz), szr = max(int(0), cntr-sz);
    int ly = lx + szl, ry = rx - szr;
    //cout<<"ANS: "<<ans<<endl;
    ans+=(ls-ly+1)*(ry-rs+1)*sz;
    //cout<<"ANS: "<<ans<<endl;
    ans+=in(sz);
    //cout<<"ANS: "<<ans<<endl;
    ans+= (ls-ly+1) * getv(cntr, sz);
    ans+= (ry-rs+1) * getv(cntl, sz);
    //cout<<"ANS: "<<ans<<endl;
    ans+=getvv(szl, szr, sz);
    //cout<<"ANS: "<<ans<<endl;
    //cout<<"SEG: "<<ls<<" "<<rs<<endl;
    solve(l, i-1, lx, rs-1, cntl, sz-1);
    solve(i+1, r, ls+1, rx, sz-1, cntr);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    cin>>s; loop(i,0,n) s[i]-='0';
    int cnt = 0;
    loop(i,0,n) {
        if (s[i]) cnt++;
        else {
            if (cnt) segs.pb({cnt, {i-cnt,i-1}});
            cnt = 0;
        }
    }
    if (cnt) segs.pb({cnt, {n-cnt,n-1}});
    int r = segs.size();
    if (!r) return cout<<0<<endl,0;
    vi sz(r);
    loop(i,0,r) sz[i] = segs[i].x;
    seg = SEG(sz);
    solve(0,r-1,0,n-1);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
12
011100011100



4
0110


7
1101001




*/