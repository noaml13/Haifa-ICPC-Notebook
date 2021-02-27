#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD = 1e9+7;

const int k = 700;
struct DSU{
    int n;
    vi p,sz;
    vvi g;
    DSU(int n): p(n,-1), sz(n,1),g(n), n(n){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    inline int effective(int c){
        return sz[c] + 100*g[c].size();
    }
    void uni(int a,int b){
        a = find(a); b = find(b);
        if (a==b) return;
        if (effective(a)>effective(b)) swap(a,b);
        p[a] = b;
        sz[b]+=sz[a];
        for(auto x:g[a]) g[b].pb(x);
    }
};
struct Edge{
    int u,v,w;
    int timew[k+1];
};
struct simpleEdge{
    int u,v,w;
    simpleEdge(int u=0, int v=0, int w=0):u(u),v(v),w(w){}
};
bool operator<(const simpleEdge& a, const simpleEdge& b){
    return a.w>b.w;
}

struct Query{
    int op,ind,w;
};
bool operator<(const Query& a, const Query& b){
    return a.w>b.w;
}

int n,m,q;

vector<Edge> edges;
vector<pair<Query,int>> qurs;
vb check;
vi checkcolor;
int dfs(int cur, int w, int t, DSU& d, int color){
    if (checkcolor[cur]==color) return 0;
    //cout<<"VISIT: "<<cur<<endl;
    checkcolor[cur] = color;
    int ans = d.sz[cur];
    for(auto ind:d.g[cur]){
        Edge& e = edges[ind];
        int ew = e.timew[t];
        //cout<<"w["<<ind<<"] = "<<ew<<" (T="<<t<<")"<<endl;
        if (ew >= w){
            int a = d.find(e.u), b = d.find(e.v);
            if (a!=cur) ans+=dfs(a,w,t,d,color);
            if (b!=cur) ans+=dfs(b,w,t,d,color);
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    edges.resize(m); check.resize(m); checkcolor.resize(n,-1);
    for(auto& e:edges){
        cin>>e.u>>e.v>>e.w;
        e.u--; e.v--;
    }
    //cout<<"WS: "; loop(i,0,m) cout<<edges[i].w<<" "; cout<<endl;
    cin>>q;
    for(int start=0;start<q;start+=k){
        //init
        loop(i,0,m) check[i] = 0;
        int sz = min(k, q-start);
        qurs.resize(sz);
        vi quest;
        vi ans(sz);
        //input
        loop(i,0,sz){
            qurs[i].y = i;
            cin>>qurs[i].x.op>>qurs[i].x.ind>>qurs[i].x.w;
            qurs[i].x.op--; qurs[i].x.ind--;
            if (!qurs[i].x.op) check[qurs[i].x.ind]=1;
            else quest.pb(i);
        }
        //split
        vector<simpleEdge> non;
        vi changed;
        loop(i,0,m) if (check[i]) changed.pb(i);
                    else non.pb(simpleEdge(edges[i].u, edges[i].v,edges[i].w));
        //init DSU
        DSU d(n);
        for(auto i:changed){
            edges[i].timew[0] = edges[i].w;
            loop(j,1,sz+1) edges[i].timew[j]=-1;
            //cout<<"W "<<i<<": "<<edges[i].timew[0]<<endl;
            int a = edges[i].u, b=edges[i].v;
            d.g[a].pb(i); d.g[b].pb(i);
        }
        loop(time,0,sz){
            Query& qur = qurs[time].x;
            if (!qur.op){
                edges[qur.ind].timew[time+1] = qur.w;
            }
        }
        //cout<<"HI::"<<endl;
        for(auto i:changed){
            loop(j,1,sz+1) if (edges[i].timew[j]==-1) edges[i].timew[j] = edges[i].timew[j-1];
        }
        //two pointers
        sort(all(non));
        sort(all(qurs));
        //cout<<"NON_SZ: "<<non.size()<<endl;
        for(int i=0,j=0;i<sz;i++){
            for(;i<sz && !qurs[i].x.op;i++);
            if (i>=sz) break;
            //cout<<"W: "<<qurs[i].x.w<<" "<<non[j].w<<endl;
            for(;j<non.size() && non[j].w>=qurs[i].x.w;j++){
                //cout<<"UNI: "<<non[j].u<<" "<< non[j].v<<endl;
                d.uni(non[j].u, non[j].v);
            }
            int head = d.find(qurs[i].x.ind);
            //cout<<"QURS ["<<qurs[i].y<<"] = "<<d.sz[head]<<endl;
            ans[qurs[i].y] = dfs(d.find(qurs[i].x.ind),qurs[i].x.w, qurs[i].y+1, d, start+i);
        }
        for(auto i:quest) {
            cout<<ans[i]<<endl;
        }
        //updating weights
        for(auto i: changed){
            edges[i].w = edges[i].timew[sz];
        }
    }
    return 0;
}
