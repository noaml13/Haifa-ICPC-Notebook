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
typedef long double ld;
typedef long long ll;
const ll INF = 1e18;

struct edge {
    int u, v;
    int ind;
    ll cap, flow;
    edge() {}
    edge(int u, int v, ll cap, int ind=0): u(u), v(v), cap(cap), flow(0), ind(ind) {}
};

struct Dinic {
    int N;
    vector<edge> E;
    vector<vector<int> > g;
    vector<int> d, pt;

    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

    void Addedge(int u, int v, ll cap, int ind) {
        if (u != v) {
            E.emplace_back(edge(u, v, cap, ind));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(edge(v, u, 0, ind));
            g[v].emplace_back(E.size() - 1);
        }
    }

    bool BFS(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (u == T) break;
            for (int k: g[u]) {
            edge &e = E[k];
            if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                d[e.v] = d[e.u] + 1;
                q.emplace(e.v);
            }
            }
        }
        return d[T] != N + 1;
    }

    ll DFS(int u, int T, ll flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); ++i) {
            edge &e = E[g[u][i]];
            edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1) {
            ll amt = e.cap - e.flow;
            if (flow != -1 && amt > flow) amt = flow;
            if (ll pushed = DFS(e.v, T, amt)) {
                e.flow += pushed;
                oe.flow -= pushed;
                return pushed;
            }
            }
        }
        return 0;
    }

    ll MaxFlow(int S, int T) {
        ll total = 0;
        while (BFS(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = DFS(S, T))
            total += flow;
        }
        return total;
    }
    vector<vector<edge>> path;
    bool DFS2(int u, int T) {
        if (u == T) {
            path.pb(vector<edge>(0));
            return 1;
        }
        for (int &i = pt[u]; i < g[u].size(); ++i) {
            int ind = g[u][i];
            if (ind%2) continue;
            edge &e = E[ind];
            if (e.flow && DFS2(e.v, T)){
                e.flow--;
                path.back().pb(e);
                return 1;
            }
        }
        return 0;
    }

    void recreate(int S, int T){
        path.clear(); 
        fill(all(pt), 0);
        while(DFS2(S,T));
        for(auto &v:path) reverse(all(v));
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii a(n);
    map<int, int> conv; conv[0];
    loop(i,0,n) cin>>a[i].x>>a[i].y, conv[a[i].x], conv[a[i].y];
    int m; cin>>m;
    vi dest(m);
    loop(i,0,m) cin>>dest[i], conv[dest[i]];
    int cnt = 0;
    for(auto& p:conv) p.y = cnt++;
    Dinic din(cnt+1);
    loop(i,0,n){
        ii& e = a[i];
        e.x = conv[e.x], e.y = conv[e.y];
        din.Addedge(e.x, e.y, 1, i);
    }
    loop(i,1,cnt) din.Addedge(i+1, i, INF, -1);
    loop(i,0,m){
        dest[i] = conv[dest[i]];
        din.Addedge(dest[i], cnt, 1, n+i);
    }
    if (din.MaxFlow(0, cnt)<m) return cout<<"impossible"<<endl,0;
    din.recreate(0, cnt);
    vvi ans(m);
    loop(i,0,m){
        vector<edge>& path = din.path[i];
        auto e = path.back(); path.pop_back();
        int ind = e.ind - n;
        for(auto e:path) if(e.ind!=-1) ans[ind].pb(e.ind);
    }
    loop(i,0,m){for(auto x:ans[i]) cout<<x+1<<" "; cout<<endl;}
    return 0;
}
/*
color a
cls
g++ k.cpp -o a & a
5
0 1
1 2
2 3
3 4
0 2
2
4 2


*/