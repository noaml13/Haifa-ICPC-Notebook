#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e9;
const int SZ = 4e5+12;
#define iii pair<ii, int>
int k = 10000;

int n;
int p[SZ], sz[SZ];
int cnt = 0;
void init(int n){
    cnt = n;
    loop(i,0,n) p[i]=-1, sz[i]=1;
}
int find(int c, int &d){
    int a = -1, b = -1;
    while(p[c]!=-1){
        if (a!=-1) p[a] = p[c]; //keep pairity
        a = b;
        b = c;
        c = p[c];
        d++;
    }
    return c;
}
int uni(int a, int b){
    int d = 0;
    a = find(a, d);
    b = find(b, d);
    if (a==b){
        //cout<<"IN UNI: "<<d<<" "<<da<<endl;
        return d%2==0; 
    }
    if (d%2){
        sz[cnt] = sz[a]+1;
        p[cnt] = -1;
        p[a] = cnt;
        a = cnt++;
    }
    if (sz[a]>sz[b]) swap(a,b);
    sz[b]+=sz[a];
    p[a]=b;
    return 0;
}


int h(ii p){
    return p.x * 2 + p.y; 
}

vi g[2*SZ];
int d[2*SZ];



bool can;
void dfs(int cur,int p=-1, int dd=0){
    //cout<<"CUR: "<<cur<<" "<<dd<<endl;
    if (d[cur]!=-1){
        //cout<<"WOW: "<<endl;
        if (d[cur]%2!=dd%2) {
            can=1;
        }
        return ;
    }
    d[cur] = dd;
    for(auto nei:g[cur]) if(nei!=p) {
        if (can) break;
        dfs(nei, cur, dd+1);
    }
}
bool cmp(iii& a, iii& b){
    return a.x.y>b.x.y;
}
int32_t main(){ 
    int n,m,q; scanf("%d%d%d",&n,&m,&q);
    vii edge(m);
    for(auto &e:edge) scanf("%d%d",&e.x,&e.y), e.x--, e.y--;
    loop(i,0,m){
        int a = edge[i].x, b = edge[i].y;
    }
    vii tmp(q); 
    bool small = 1;
    loop(i,0,q){
        int a,b; scanf("%d%d",&a,&b); a--; b--;
        tmp[i] = {a,b};
        if (a>200) small=0;
    }
    if (small) k = 50;
    int r = (m+k-1)/ k;
    vector<vector<iii>> qur(r);
    loop(i,0,q) {
        qur[tmp[i].x/k].pb({{tmp[i]},i});
    }
    vi ans(q); 
    loop(i,0,r){
        if (qur[i].size()==0) continue;
        sort(all(qur[i]), cmp);
        init(n);
        int last = m-1, res = 0;
        loop(j,0,min(i*k,m)) { //before
            chkmax(res,uni(edge[j].x, edge[j].y));
        }
        for(auto p:qur[i]){
            int a = p.x.x, b = p.x.y, ind = p.y;
            //cout<<a<<" "<<b<<" "<<ind<<endl;
            for(;last>b;last--) chkmax(res,uni(edge[last].x, edge[last].y));
            if (res) ans[ind] = 1;
            else {
                //cout<<"AB :"<<i*k<<" "<<a<<" "<<b<<endl;
                vi s;
                vii curedge;
                loop(j,i*k,a){
                    //cout<<"J: "<<j<<endl;
                    int x = edge[j].x, y = edge[j].y;
                    int dx=0, dy=0;
                    x = find(x, dx); y = find(y, dy);
                    x = h({x, dx%2}), y= h({y, dy%2});
                    curedge.pb({x,y});
                    s.pb(x); s.pb(y);
                }
                //sort(all(s)); s.resize(unique(all(s))-s.begin());
                for(auto x:s){
                    g[x].clear(); d[x]=-1;
                    g[x^1].clear(); d[x^1]=-1;
                }
                for(auto x:s) g[x].pb(x^1);
                for(auto e:curedge) g[e.x].pb(e.y), g[e.y].pb(e.x);
                can = 0;
                for(auto x:s){
                    if (d[x]==-1) dfs(x);
                    if (can) break;
                }
                ans[ind] = can;
            }
        }
    }
    loop(i,0,q) printf("%s\n",(ans[i]?"YES":"NO"));
    return 0;
}
/*
color a
cls
g++ cc.cpp -o a & a
6 8 2
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
4 8
4 7

*/