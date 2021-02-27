#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define iiii pair<ii,ii>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define viiii vector<iiii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long double double;
const int INF = 1e18, MOD = 1e9+7;

ii operator+(ii a, ii b){
    return {a.x+b.x,a.y+b.y};
}
ii operator-(ii a, ii b){
    return {a.x-b.x,a.y-b.y};
}
int operator*(ii a, ii b){
    return (a.x * b.y) - (a.y * b.x);
}
double ang(const ii& p){
    if (p.x==0) return M_PI * (p.y>0?0.5:1.5);
    double rat = p.y * 1.0 / p.x;
    double ang = atan(rat);
    if (ang<0) ang+=M_PI;
    if (p.y<0) ang+=M_PI;
    return ang;
}
int prog(vector<double>& v, int &i, double a){
    int ans = i;
    while(i < v.size() && v[i]<=a) i++;
    return i - ans;
}

ii f;
vector<double> p,m;
void add(ii a, ii b){
    if (a * b < 0) swap(a,b);
    p.pb(ang(a)); m.pb(ang(b));
}
int ans = 0, a = 0, b = 0;
int cnt = 0;
void job(ii c){
    c = c - f;
    double an = ang(c);
    cnt += prog(p,a, an);
    if (cnt==0) ans++;
    cnt-= prog(m,b, an);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,r; cin>>n>>r;
    cin>>f.x>>f.y;
    loop(i,0,r){
        int l; cin>>l;
        ii fir, last, cur; cin>>fir.x>>fir.y;
        last = fir;
        loop(i,1,l){
            cin>>cur.x>>cur.y;
            add(last, cur);
            last = cur;
        }   
        add(last, fir);
    }
    int l = p.size();
    loop(i,0,l){
        if (p[i] > m[i]) cnt++;
    }
    sort(all(p)); sort(all(m));
    loop(i,f.y,n+1){
        job(ii(n,i));
    }
    loopr(i,0,n){
        job({i,n});
    }
    loopr(i,0,n){
        job({0,i});
    }
    loop(i,1,n+1){
        job({i,0});
    }
    loop(i,1,f.x){
        job({n,i});
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
100 1
60 50
5
70 40
75 40
80 40
80 50
70 60


*/