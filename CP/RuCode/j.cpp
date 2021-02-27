#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD=1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,k; cin>>n>>m>>k;
    vvi g(n), ag(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b);
        ag[b].pb(a);
    }
    queue<int> q;
    loop(i,0,n) if(g[i].size()==0) q.push(i);
    vi cnt(n), dist(n);
    vb win(n);
    while(q.size()){
        int cur = q.front(); q.pop();
        for(auto nei:ag[cur]){
            if (++cnt[nei]==g[nei].size()) q.push(nei);
        }
        dist[cur] = INF;
        for(auto nei:g[cur]) chkmin(dist[cur], dist[nei]+1);
        if (dist[cur]==INF) dist[cur] = 0, win[cur] = 0;
        else{
            if (dist[cur]<=k) win[cur] = 1;
            else{
                win[cur] = 0;
                for(auto nei:g[cur]) if(!win[nei]) win[cur] = 1;
            }
        }
    }
    loop(i,0,n) if(cnt[i]!=g[i].size()) loop(j,0,2) j--;
    if (win[0]) cout<<"Dasha"<<endl;
    else cout<<"Denis"<<endl;
    return 0;
}
/*
color a
cls
g++ j.cpp -o a & a
7 0 2

7 8 2
1 2
2 3
3 4
2 5
3 6
4 6
5 6
6 7

7 8 2
1 2
2 3
3 4
2 5
3 6
4 6
5 6
6 7


9 9 2
1 2 
2 3 
3 4  
4 5
3 6 
6 7
7 8 
8 4
5 9
*/