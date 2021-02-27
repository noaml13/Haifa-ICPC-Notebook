#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    g.resize(n);
    //  g[i] -> vector of all neigboghrs of i
    for(int i=0; i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n, -1); // dist[i] = dist of 0 to i
    vector<int> p(n, -1); // p[i] = parent of i
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(q.size()){
        int cur = q.front();
        q.pop();
        for(int nei:g[cur]){
            if (dist[nei]==-1){
                dist[nei] = dist[cur] + 1;
                q.push(nei);
                p[nei] = cur;
            }
        }
    }
    if (dist[n-1]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n-1]+1<<endl;
    int cur = n-1;
    vector<int> vec;
    while(cur!=-1){
        vec.push_back(cur);
        cur = p[cur];
    }
    reverse(vec.begin(), vec.end());
    for(int x:vec) cout<<x+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o b & b
5 5
1 2
1 3
1 4
2 3
5 4

*/