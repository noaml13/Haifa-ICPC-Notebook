#include <bits/stdc++.h>
#define int int64_t
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


int n;
vi g,t;
int conv(int x, int y){
    return x*n + y;
}
ii get(int v){
    return {v/n,v%n};
}
bool flag = true;
int dfs(int cur, int k, int p=-1){
    if (k==0) return cur;
    if (t[cur]!=-1) {
        flag = true;
        return dfs(cur,k%(t[p] - t[cur] + 1), p);
    }
    dfs(g[cur],k-1,cur);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>n>>k;
    g.resize(n*n,0); 
    t.resize(n*n,-1);
    loop(i,0,n){
        loop(j,0,n){
            int x; cin>>x;
            g[conv(i,j)] = conv(x,i);
        }
    }
    cout<<get(dfs(conv(1,0), k)).x+1<<endl;
    return 0;
}


