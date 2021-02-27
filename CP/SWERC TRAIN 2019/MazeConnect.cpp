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
#define loop(i,s,e) for(int i=s;i<e;++i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;


struct DSU{
    int n;
    vi p,sz;
    DSU(int _n){
        n=_n;
        p.resize(n,-1);
        sz.resize(n,1);
    }
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    bool uni(int a,int b){
        a= find(a); b= find(b);
        if (a==b) return false;
        if (sz[a]<sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int n,m,N,M;
int conv(int i,int j){
    return i*M + j;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    N=2*n+2, M=2*m+2;
    vvb g(N, vb(M,false));
    string s;
    loop(i,0,n){
        cin>>s;
        loop(j,0,m){
            if (s[j]=='.') continue;
            if (s[j]=='/'){
                g[2*i+2][2*j+1]=1;
                g[2*i+1][2*j+2]=1;
            }
            else{
                g[2*i+1][2*j+1]=1;
                g[2*i+2][2*j+2]=1;
            }
        }
    }
    loop(i,0,N){
        loop(j,0,M) cout<<(g[i][j]?'#':'.');
        cout<<endl;
    }
    int ans=0;
    DSU d(N*M);
    loop(i,0,N){
        loop(j,0,M){
            if (g[i][j]) continue;
            ans++;
            if (i>0 && (!g[i-1][j]) && d.uni(conv(i,j), conv(i-1,j))){
                ans--;
            }
            if (j>0 && (!g[i][j-1]) && d.uni(conv(i,j), conv(i,j-1))){
                ans--;
            }
        }
    }
    cout<< (ans-1)<<endl;
    return 0;
}
