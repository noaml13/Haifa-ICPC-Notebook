#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
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
const int INF=4e18;


struct BINARY{
    int n, LOGN=1;
    vvi g;
    vi depth;
    vvi anc;
    BINARY(vvi& _g):g(_g), n(_g.size()){
        //cout<<n<<endl;
        for(int i=1;i<=n;i<<=1,++LOGN);
        //cout<<":) "<<LOGN<<endl;
        depth.resize(n,0);
        anc.resize(n,vi(LOGN,-1));
        dfs(0);
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
        return res + 2;
    }
};

int n, m, q, N;


int conv(int i, int j){
    return i*m+j;
}
void addEdge(vvi& g,int a,int b){
    //cout<<a<<" "<<b<<endl;
    g[a].pb(b);
    g[b].pb(a);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    N=n*m;
    vvi g(N);
    string s;
    getline(cin,s); getline(cin,s);
    loop(i,0,n){
        getline(cin,s);
        loop(j,0,2*m){
            if (j%2==0){
                if(s[j+1]!='_'&& i!=n-1) addEdge(g,conv(i,j/2),conv(i+1,j/2));
            }
            else{
                if(s[j+1]!='|') addEdge(g,conv(i,j/2),conv(i,j/2+1));
            }
        }
    }
    BINARY bin(g);
    int last, cur;
    ii po;
    int ans=0;
    cin>>q;
    loop(i,0,q){
        last = cur;
        cin>>po.x>>po.y;
        cur = conv(po.x-1,po.y-1);
        if (i){
            ans+=bin.query(last,cur);
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
2 6
 _ _ _ _ _ _
|  _ _ _ _ _|
|_ _ _ _ _ _|
5
1 5
1 1
1 6
1 1
1 5


5 5
 _ _ _ _ _
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|
7
4 4
1 4
3 1
4 5
1 2
2 2
5 4
*/


