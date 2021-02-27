vvi g;
vb check;
vi dp, depth;
void dfs(int cur, int p=-1, int d=0){
    dp[cur] = depth[cur] = d;
    check[cur] = 1;
    for(int nei:g[cur]) if(nei!=p){
        if (check[nei]){
            dp[cur] = min(dp[cur], depth[nei]);
        }
        else{
            dfs(nei, cur, d+1);
            dp[cur] = min(dp[cur], dp[nei]);
        }
    }
}



vvi g, ag;
vb check;
vi order;
void dfs1(int cur){
    if (check[cur]) return ;
    check[cur] = 1;
    for(int nei:g[cur]) dfs1(nei);
    order.pb(cur);
}
vi vec;
void dfs2(int cur, int col){
    if (check[cur]) return ;
    check[cur] = 1;
    vec[cur] = col;
    for(int nei:ag[cur]) dfs2(nei, col);
}
int main(){
    loop(i,0,n) dfs1(i);
    reverse(all(order));
    fill(all(check),0);
    vec.resize(n,-1); int cnt = 0;
    for(int i:order){
        if (check[i]) continue;
        dfs2(i, cnt++);
    }
}

int main(){
    vvi g, gT;
    vi degin(n);
    queue<int> q;
    loop(i,0,n) {
        degin[i] = gT[i].size();
        if (degin[i]==0) q.push(i);
    }
    int cnt = 0;
    while(q.size()){
        int cur = q.front(); q.pop();
        cnt++;
        // do somthing
        for(int nei:g[cur]){
            degin[nei]--;
            if (degin[nei]==0) q.push(nei);
        }
    }
    if (cnt==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
