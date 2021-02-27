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

int getdays(int dist, int k){
    int l=0,r=dist+100, mid, ans=-1;
    while(l<r){
        mid = (l+r)/2;
        int maxd = (mid * (mid+1)) / 2 * k;
        if (dist>maxd) l=mid+1;
        else r=mid, ans=mid;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,q,k; cin>>n>>m>>q>>k;
    vvi g(n);
    vi dist(n,-1);
    queue<int> qu;
    loop(i,0,q){
        int x; cin>>x; x--; 
        dist[x]=0; qu.push(x);
    }
    loop(i,0,m){
        int a,b; cin>>a>>b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    while(qu.size()){
        int cur = qu.front(); qu.pop();
        for(auto nei:g[cur]){
            if (dist[nei]==-1){
                dist[nei] = dist[cur]+1;
                qu.push(nei);
            }
        }
    }
    loop(i,0,n){
        cout<<getdays(dist[i],k)<<" ";
    }
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -std=c++11 -O2 -static -s -lm -o a & a
6 8 1 1
6
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6


*/


 