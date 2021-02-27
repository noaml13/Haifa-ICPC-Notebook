#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
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
const int INF = 2e9;
struct Edge {
    int u, v;
    int cap, flow;
    Edge() {}
    Edge(int u, int v, int cap): u(u), v(v), cap(cap), flow(0) {}
};
struct Dinic {
    int N;
    vector<Edge> E;
    vector<vector<int> > g;
    vector<int> d, pt;
    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
    void addEdge(int u, int v, int cap) {
        if (u != v) {
            E.emplace_back(Edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(Edge(v, u, 0));
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
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }
    int DFS(int u, int T, int flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); ++i) {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1) {
                int amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (int pushed = DFS(e.v, T, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    int maxFlow(int S, int T) {
        int total = 0;
        while (BFS(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (int flow = DFS(S, T))
            total += flow;
        }
        return total;
    }
};

inline void print(int a, int b, int v){
    cout<<a+1<<" "<<b+1<<" "<<v<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    int M=0; 
    vi w(n);
    vii qur(m);
    loop(i,0,n) cin>>w[i], M+=w[i];
    M/=2;
    Dinic din(n+m+2);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        qur[i]={a,b};
        din.addEdge(i+n, a, 2);
        din.addEdge(i+n, b, 2);
    }
    /*loop(i,m,M){
        loop(j,0,n){
            din.addEdge(i+n, j, 2);
        }
    }*/
    int s=n+m, t=n+m+1;
    loop(i,0,m) din.addEdge(s, i+n, 2);
    loop(i,0,n) din.addEdge(i, t, w[i]);
    if (din.maxFlow(s,t)!=2*m) cout<<"FUCK!"<<endl;
    cout<<M<<endl;
    loop(i,0,m){
        Edge& a=din.E[i*4],b=din.E[i*4+2];
        //cout<<a.flow<<" "<<b.flow<<endl;
        if (a.flow+b.flow!=2) cout<<"FUCKFF"<<endl;
        print(qur[i].x, qur[i].y, a.flow);
        w[qur[i].x]-=a.flow;
        w[qur[i].y]-=b.flow;
    }
    int one=-1;
    loop(i,0,n){
        if (w[i]<0) cout<<"FUCK NEG"<<endl;
        while(w[i]>=2){
            print(i,(i?0:1),2);
            w[i]-=2;
        }
        if (w[i]>0){
            if (one==-1) one=i;
            else{
                print(i,one,1);
                w[one]--; w[i]--;
                one = -1;
            }
        }
    }
    //for(auto a: ans) cout<<a.x.x<<" "<<a.x.y<<" "<<a.y<<endl;
    return 0;
}
/*
color a
cls
g++ SLICICE.cpp -o a & a
4 3
5 3 1 1
1 3
2 3
4 1

*/


 



