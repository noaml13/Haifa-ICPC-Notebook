#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define pb push_back
#define loop(i,s,e) for(int i=(s); i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1; i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e8+120, MOD = 1e9+7;

const int MAX = 1e7;
int maxi[MAX], prop[MAX], lp[MAX], rp[MAX]; int cnt = 1;
void add(int c, int p){
    prop[c]+=p, maxi[c]+=p;
}
int Node(){
    maxi[cnt] = prop[cnt] = lp[cnt] = rp[cnt] = 0;
    return cnt++;
}
void fix(int c){
    if (!lp[c]) lp[c] = Node();
    if (!rp[c]) rp[c] = Node();
    if (prop[c]){
        add(lp[c], prop[c]);
        add(rp[c], prop[c]);
        prop[c] = 0;
    }
    
}
void update(int a, int b, int dx, int c=0, int l=0, int r=INF){
    if (a>=r || b<=l) return ;
    if (a<=l && r<=b) return add(c, dx);
    fix(c);
    int mid = (l+r)/2;
    update(a,b,dx, lp[c], l, mid);
    update(a,b,dx, rp[c], mid, r);
    maxi[c] = max(maxi[lp[c]], maxi[rp[c]]);
}
int query(){
    return maxi[0];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    int n,w,h; cin>>n>>w>>h;
    vii a(n); 
    vector<pair<ii,int>> eve;
    loop(i,0,n) {
        cin>>a[i].x>>a[i].y;
        eve.pb({{a[i].x, 0},i}); // in
        eve.pb({{a[i].x+w, 1},i}); // out
    }
    sort(all(eve));
    int ans = 0;
    for(auto e:eve){
        int i = e.y, op = e.x.y;
        int ly = a[i].y - h, ry = a[i].y +1; // not include - [l,r)
        chkmax(ly, 1);
        update(ly, ry, (op?-1:1));
        //cout<<"HI: "<<i<<" "<<seg.query()<<endl;
        chkmax(ans, query());
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
6 2 3
1 1
3 1
2 2
3 3
5 3
3 5
*/