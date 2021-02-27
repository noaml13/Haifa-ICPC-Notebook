#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 2e9, MOD = 998244353;

vector<map<int, int>> maps(0);
vi ids;
vvi g;
vi t,w;

void dfs(int cur){
    //cout<<"VISIT: "<<cur<<endl;
    if (g[cur].size()==0){ //leaf
        ids[cur] = maps.size();
        maps.pb(map<int,int>());
        if (t[cur]!=-1) maps[ids[cur]][t[cur]] = w[cur];
        //cout<<"BI: "<<cur<<endl;
        return ;
    }
    int big = -1, sz = -1;
    for(auto s:g[cur]){
        dfs(s);
        int ssz = maps[ids[s]].size();
        //cout<<"CHI: "<<ssz<<endl;
        if (ssz>sz){
            sz = ssz;
            big = s;
        }
    }
    //cout<<"BIG: "<<cur<<" = "<<big<<endl;
    ids[cur] = ids[big];
    auto &m = maps[ids[cur]];
    for(auto s:g[cur]) if (s!=big){
        for(auto p:maps[ids[s]]) m[p.x] += p.y;
    }
    if (t[cur]!=-1){
        m[t[cur]] += w[cur];
        int carry = w[cur];
        auto it = m.upper_bound(t[cur]);
        while(it!=m.end() && it->y <= carry){
            carry -= it->y;
            auto tmp = it;  tmp++;
            m.erase(it);
            it = tmp;
        }
        if (it!=m.end()){
            it->y -= carry;
        }
    }
    //cout<<"BI: "<<cur<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m, k; cin>>n>>m>>k;
    g.resize(n); t.resize(n,-1); w.resize(n,0); ids.resize(n);
    loop(i,1,n){
        int x; cin>>x; x--;
        g[x].pb(i);
    }
    loop(i,0,m){
        int v,d,c; cin>>v>>d>>c; v--;
        //cout<<"BI"<<" "<<v<<" "<<d<<" "<<c<<endl;
        t[v] = d; w[v] = c;
        //cout<<"HI"<<" "<<v<<" "<<d<<" "<<c<<endl;
    }
    dfs(0);
    int ans = 0;
    for(auto p:maps[ids[0]]) ans+=p.y;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ magictree.cpp -o a & a
6 4 10
1
2
1
4
4
3 4 5
4 7 2
5 4 1
6 9 3
*/