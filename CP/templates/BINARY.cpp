
struct BINARY{
    int n, LOGN=1;
    vvi g;
    vi depth;
    vvi anc;
    BINARY(vvi& _g, int s=0):g(_g), n(_g.size()){
        for(int i=1;i<=n;i<<=1,++LOGN);
        depth.resize(n,0);
        anc.resize(n,vi(LOGN,-1));
        dfs(s);
    }
    void dfs(int cur, int p=-1,int d=0){
        anc[cur][0] = p;
        for(int i=1;anc[cur][i-1]!=-1;i++){
            anc[cur][i] = anc[anc[cur][i-1] ][i-1];
        }
        depth[cur] = d;
        for(auto nei:g[cur]){
            if (nei==p) continue;
            dfs(nei, cur, d+1);
        }
    }
    int lift(int& a, int d){
        int res=0;
        for(int i=LOGN-1;i>=0;--i){
            if (a==-1) return res;
            if (d>= 1<<i){
                d-=1<<i;
                res += 1<<i;
                a = anc[a][i];
            }
        }
        return res;
    }
    int query(int a,int b){
        if(depth[a]<depth[b]) swap(a,b);
        int res = lift(a, depth[a]-depth[b]);
        if (a==b) return res;
        for(int i=LOGN-1;i>=0;--i){
            if (anc[a][i]!=anc[b][i]){
                res += 2 * (1<<i);
                a=anc[a][i];
                b=anc[b][i];
            }
        }
        return res+2;
    }
};