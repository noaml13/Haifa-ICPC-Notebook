#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e9;

int n;
vvi g;
vi dp1, dp2;
vvi inbest, best1;
vb tookbest, leaf;

void dfs(int cur, int f=-1){
    int r = 0;
    for(auto nei:g[cur]) if(nei!=f) dfs(nei, cur), r++;
    int &v1 = dp1[cur], &v2=dp2[cur];
    if (r==0){
        v1 = 2; v2 = 0; leaf[cur] = 1;
        return ;
    }
    int s1 = 0;
    vii dif;
    for(auto nei:g[cur]) if(nei!=f) {
        s1+=dp1[nei], dif.pb(ii((dp2[nei]+2)-dp1[nei], nei));
    }
    sort(all(dif));
    int curp = dif[0].x;
    ii bb = {0,-1};
    loop(i,1,r){
        curp+=dif[i].x;
        chkmin(bb, ii(curp, dif[i].y));
    }
    loop(i,0,bb.y+1) inbest[cur].pb(dif[i].y);
    int best = bb.x;
    v2 = s1 + best;
    v1 = s1 + dif[0].x;
    best1[cur] = {dif[0].y};
    if (best<0 && s1+best<v1) {
        v1 = s1+best;
        best1[cur] = inbest[cur];
    }
}
vb check;
vi ans;
void recon(int cur, int state=0, int f=-1){
    if (check[cur]) return ;
    //cout<<cur<<endl;
    check[cur] = 1; 
    if (leaf[cur]){
        swap(ans[cur], ans[f]); return ;
    }
    if (state){
        swap(ans[cur], ans[f]);
        for(auto nei:inbest[cur]) recon(nei,1,cur);
    }
    else{
        for(auto nei:best1[cur]) recon(nei,1,cur);
    }
    for(auto nei:g[cur]) if(nei!=f){
        recon(nei, 0, cur);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    /*if (n<11)
    {
        vvi dist(n, vi(n, INF));
        loop(i,0,n-1){
            int a,b; cin>>a>>b; a--; b--;
            dist[a][b] = dist[b][a] = 1;
        }
        loop(i,0,n) dist[i][i]=0;
        loop(k,0,n){
            loop(i,0,n){
                loop(j,0,n){
                    chkmin(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vi per(n); loop(i,0,n) per[i]=i;
        int best = INF;
        vi ans;
        do{
            int cur = 0;
            loop(i,0,n) {
                if (i==per[i]){
                    cur = INF; 
                    break;
                }
                cur+=dist[i][per[i]];
            }
            //cout<<cur<<" : "; loop(i,0,n) cout<<per[i]+1<<" "; cout<<endl;
            if (best>cur){
                best = cur;
                ans = per;
            }
        }while(next_permutation(all(per)));
        cout<<best<<endl;
        loop(i,0,n) cout<<ans[i]+1<<" ";
        return 0;
    }*/
    g.resize(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    dp1.resize(n); dp2.resize(n); inbest.resize(n); tookbest.resize(n);
    check.resize(n); ans.resize(n); leaf.resize(n); best1.resize(n);
    dfs(0);
    //loop(i,0,n) cout<<dp1[i]<<" "<<dp2[i]<<endl;
    cout<<dp1[0]<<endl;
    loop(i,0,n) ans[i]=i;
    recon(0);
    loop(i,0,n) cout<<ans[i]+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
5
1 2
2 3
2 4
4 5




*/