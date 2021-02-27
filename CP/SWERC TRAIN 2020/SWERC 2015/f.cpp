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

typedef long long ll;
struct edge {
    int u, v;
    ll cap, flow;
    edge() {}
    edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
    int N;
    vector<edge> E;
    vector<vector<int> > g;
    vector<int> d, pt;

    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

    void Addedge(int u, int v, ll cap) {
        if (u != v) {
            E.emplace_back(edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(edge(v, u, cap));
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
};
int n,m;
int conv(int i, int j){
    return i*m+j;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int A,B; cin>>n>>m>>A>>B;
    vector<string> a(n);
    loop(i,0,n) cin>>a[i];
    Dinic din(n*m+2);
    int S = n*m, T = n*m+1;
    loop(i,0,n) loop(j,0,m-1) din.Addedge(conv(i,j), conv(i, j+1),A);
    loop(i,0,n-1) loop(j,0,m) din.Addedge(conv(i,j), conv(i+1, j),A);
    loop(i,0,n) loop(j,0,m){
        if (a[i][j]=='.') din.Addedge(S, conv(i,j), B);
        else din.Addedge(T, conv(i,j), B);
    }
    cout<<din.MaxFlow(S,T)<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
5 4 1000 2000
...#
#..#
...#
##..
###.

*/