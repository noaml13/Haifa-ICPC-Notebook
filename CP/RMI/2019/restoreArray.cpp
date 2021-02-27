#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
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
const int INF=4e18;

struct Edge{
    int u,v,w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w){}
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin>>n>>m; n++;
    vector<Edge> es;
    vi dis(n,INF);
    dis[0] = 0;
    loop(i,0,n-1){
        es.pb(Edge(i+1,i,0));
        es.pb(Edge(i,i+1,1));
    }
    int l,r,k,val;
    loop(i,0,m){
        cin>>l>>r>>k>>val;
        l++, r++; // 1<= l,r <=n
        if (val==0)
            es.pb(Edge(l-1, r, r-l+1-k));
        else
            es.pb(Edge(r, l-1, l+k-r-2));
    }
    loop(i,0,n){
        for(Edge& e: es){
            chkmin(dis[e.v],dis[e.u]+e.w);
        }
    }
    bool b=true;
    for(Edge& e: es){
        if (dis[e.v]>dis[e.u]+e.w) b=false;
    }
    if (b){
        loop(i,0,n-1){
            cout<<dis[i+1]-dis[i]<<" ";
        }
    }
    else cout<<"-1";
    cout<<endl;
    return 0;
}
/*
4 5
0 1 2 1
0 2 2 0
2 2 1 0
0 1 1 0
1 2 1 0
*/





