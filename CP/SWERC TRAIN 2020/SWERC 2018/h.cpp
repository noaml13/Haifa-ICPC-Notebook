#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define pqii priority_queue<ii>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, s, n) for (int i = (s); i < (n); i++)
#define repr(...) GET_MACRO(__VA_ARGS__, repr3, repr2, repr1)(__VA_ARGS__)
#define repr1(n) for (int i = (n)-1; i >= 0; i--)
#define repr2(i, n) for (int i = (n)-1; i >= 0; i--)
#define repr3(i, n, s) for (int i = (n)-1; i >= (s); i--)
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
const int INF = 1e18;

#define vvii vector<vii>
vvii g;

vi min_dist;

void dijkstra(int source){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0LL,source);
    min_dist[source] = 0;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        if(top.x != min_dist[top.y]) continue;
        for(auto nei: g[top.y]){
            if(min_dist[nei.x] > min_dist[top.y] + nei.y){
                min_dist[nei.x] = min_dist[top.y] + nei.y;
                pq.emplace(min_dist[nei.x], nei.x);
            }
        }
    }
}

#define iii pair<int, ii>
#define viii vector<iii>
struct D{
    int d1,d2,d3;
    int i;
    bool operator<(D o){
        return vi({d1,d2,d3}) < vi({o.d1, o.d2, o.d3});
    }
    bool operator==(D o){
        return vi({d1,d2,d3}) == vi({o.d1, o.d2, o.d3});
    }
};
void solve(){
    int n, m; cin >> n >> m;
    g.resize(n);
    min_dist.resize(n, INF);
    rep(m){
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    // vi d1(n), d2(n), d3(n);
    vector<D> d(n);
    dijkstra(0);
    rep(n) d[i].d1 = min_dist[i], min_dist[i] = INF;
    dijkstra(1);
    rep(n) d[i].d2 = min_dist[i], min_dist[i] = INF;
    dijkstra(2);
    rep(n) d[i].d3 = min_dist[i], min_dist[i] = INF;
    d[0] = {0, 2, 2};
    d[1] = {2, 0, 2};
    d[2] = {2, 2, 0};
    d[3] = {1, 1, 1};
    d[4] = {1, 1, 1};
    sort(all(d));
    loop(i,0,n) d[i].i = i;
    vi w(n, 1);
    loop(i,0,n){
        int j = i;
        while(j+1<n && d[j+1]==d[i]) j++;
        loop(k,i,j+1) w[k] = j-i+1;
        i = j+1;
    }
    d.resize(unique(all(d))-d.begin());
    map<int, int> s;
    int ans = 0;
    loop(i,0,d.size()){
        auto it = s.upper_bound(d[i].d2);
        if(it != s.begin()){
            it = prev(it);
            if (it->y > d[i].d3){
                s[d[i].d2] = d[i].d3;
                auto it = s.find(d[i].d2);
                ans+=w[d[i].i];
                while(1){
                    auto t = it;
                    t++;
                    if (t==s.end()) break;
                    if (t->y < d[i].d3) break;
                    s.erase(t);
                }
            }
        }
        else{
            s[d[i].d2] = d[i].d3;
            ans+=w[d[i].i];
        }
    }

    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
/*
color a
cls
g++ h.cpp -o a & a
5 0

5 6
0 3 1
1 3 1
2 3 1
4 3 1
0 1 1
0 2 1


5 4
0 3 1
1 3 1
2 3 1
4 3 1



*/