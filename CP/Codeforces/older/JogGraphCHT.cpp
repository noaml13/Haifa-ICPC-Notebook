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
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e18, MOD = 1e9+7;
 
 
bool cmp(ii a, ii b){
    if (a.x==b.x) a.y > b.y;
    return a.x < b.x;
}
int at(ii l, int x){
    return (l.x * x + l.y);
}
bool check(ii a, ii b, ii c){
    return __int128_t(a.y-b.y)*__int128_t(c.x - b.x) > __int128_t(c.y-b.y)*__int128_t(a.x - b.x);
}
int intinter(ii a, ii b){
    int x=(a.y-b.y), y = (b.x - a.x);
    if (y<0) x=-x, y=-y;
    if (x<0) return -INF;
    return x/y;
}
void add(int &a, int b){
    a = (MOD + (a+b)%MOD)%MOD;
}
int inv2 = (MOD+1)/2;
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b, p/2);
    return (v*v)% MOD * (p%2?b:1) %MOD;
}

int sum(int a, int b, int n){
    //cout<<"SUM: "<<a<<" "<<b<<" "<<n<<endl;
    int v = ((a * (n-1)))%MOD * inv2 % MOD;
    add(v, b);
    return v * n % MOD;
}
 

int32_t main() {
    ios_base::sync_with_stdio(false);
    //inv2 = pp(2, MOD-2);
    int n,m,q; cin>>n>>m>>q;
    vector<pair<ii,int>> edge(m);
    for(auto &e:edge) cin>>e.x.x>>e.x.y>>e.y, e.x.x--, e.x.y--;
    vi dist(n,-INF), next(n, -INF);
    dist[0] = 0;
    int ans = 0;
    loop(i,0,m){
        loop(j,0,m){
            auto e = edge[j];
            chkmax(next[e.x.x], dist[e.x.y]+e.y);
            chkmax(next[e.x.y], dist[e.x.x]+e.y);
        }
        int best = -INF;
        loop(j,0,n){
            dist[j] = next[j], next[j] = -INF;
            chkmax(best, dist[j]);
        }
        add(ans, best%MOD);
    }
    vii lines;
    for(auto e:edge) lines.pb({e.y, max(dist[e.x.x],dist[e.x.y])});
    //cout<<"ANS: "<<ans<<endl;
    sort(all(lines), cmp);
    lines.resize(unique(all(lines),[](ii a, ii b){return a.x==b.x;})-lines.begin());
    vii stack;
    for(auto l:lines){
        while(stack.size()>1 && check(stack[stack.size()-2], stack.back(),l) ){
            //cout<<"OUT: "<<stack.back().x<<" "<<stack.back().y<<endl;
            stack.pop_back();

        }
        //cout<<"IN: "<<l.x<<" "<<l.y<<endl;
        stack.pb(l);
    }
    
    //for(auto l:stack) cout<<l.x<<" "<<l.y<<endl;
    int k = stack.size();
    q-=m;
    int last = 1;
    loop(i,0,k){
        int x = q;
        if (i+1<k) chkmin(x,intinter(stack[i], stack[i+1]));
        //cout<<"HI "<<stack[i].x<<" "<<stack[i].y<<" : "<<x<<endl;
        if (x<last) continue;
        int v = sum(stack[i].x, at(stack[i],last)%MOD, x-last+1);
        //cout<<"BI "<<v<<endl;
        add(ans, v);
        last = x + 1;
    }
    //if (last<=q) add(ans, sum(stack[k-1].x, at(stack[k-1],last)%MOD, q-last+1));
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ JogGraphCHT.cpp -o a & a
7 8 25
1 2 1
2 3 10
3 4 2
1 5 2
5 6 7
6 4 15
5 3 1
1 7 3

 
 
 
 
 
*/