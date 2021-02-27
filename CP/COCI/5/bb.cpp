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
    return ii(v/n,v%n);
}
bool flag = true;
int cnt=0;
int dfs(int cur, int k){
    if (k==0) return cur;
    if (flag && t[cur]!=-1) {
        flag = false;
        //k++;
        k =  k%(cnt - t[cur]);
        //cout << "CYC"<<(t[p] - t[cur] + 1) <<" "<<k<<endl;
        if (k==0) return cur;
    }
    t[cur]=cnt++;
    return dfs(g[cur],k-1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>n>>k; k-=2;
    if (k==-1) return cout<<1<<endl,0;
    g.resize(n*n,0); 
    t.resize(n*n,-1);
    loop(i,0,n){
        loop(j,0,n){
            int x; cin>>x; x--;
            g[conv(i,j)] = conv(x,i);
        }
    }
    cout<<get(dfs(conv(1,0), k)).x+1<<endl;
    return 0;
}


