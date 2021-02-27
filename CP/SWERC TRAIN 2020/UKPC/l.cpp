#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 1e18;

int operator*(ii a, ii b){
    return a.x*b.y-a.y*b.x;
}
bool cmp(pair<ii, int> a, pair<ii, int> b){
    return a.x*b.x>0;
}

int solve(vector<pair<ii, int>>& ps){
    vii a;
    for(auto p:ps) a.pb({p.x.x*p.x.x+p.x.y*p.x.y, p.y});
    sort(all(a));
    int n = a.size();
    vi lis(n+1, INF); lis[0] = 0;
    for(auto x:a){
        int ind = lower_bound(all(lis), x.y) - lis.begin();
        lis[ind] = x.y;
    }
    loopr(i,0,n+1) if(lis[i]<INF) return i;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int x,y; cin>>x>>y;
    int n; cin>>n;
    vector<pair<ii, int>> up, down;
    loop(i,0,n){
        int a,b,h; cin>>a>>b>>h;
        a-=x, b-=y;
        if (b>0 || (b==0 && a<0)) up.pb({{a,b}, h});
        else down.pb({{a,b}, h});
    }
    sort(all(up), cmp), sort(all(down), cmp);
    int ans = 0;
    for(auto vec:{up, down}){
        vector<pair<ii, int>> ln;
        for(auto p:vec){
            if (ln.size() && ln.back().x*p.x!=0){
                ans+=solve(ln);
                ln.clear();
            }
            ln.pb(p);
        }
        //cout<<"HI: "<<endl;
        ans+=solve(ln);
        //cout<<"BI: "<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ l.cpp -o a & a
50 50
3
60 55 1
70 60 1
40 45 1






*/