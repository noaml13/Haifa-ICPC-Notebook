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
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD=1e9+9;

inline bool in(set<int>& s, int v){
    return s.find(v)!=s.end();
}
int n,m,k;
vi calc(vi& c, vector<set<int>>& a){
    vi ans(n);
    loop(i,0,n){
        loop(j,0,m){
            if (j+i==n) break;
            if (!in(a[j], c[i+j])) break;
            ans[i] = j+1;
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    vi c(n); loop(i,0,n) cin>>c[i];
    vector<set<int>> a(m);
    loop(i,0,m){
        int x,y; cin>>x;
        loop(j,0,x) cin>>y, a[i].insert(y);
    }
    vi forw = calc(c,a);
    reverse(all(c)); reverse(all(a)); 
    vi back = calc(c,a);
    reverse(all(c)); reverse(all(a)); reverse(all(back));
    //int L = n-m+1;
    vb jump(n);
    jump[0] = (forw[0]>=m);
    loop(i,1,n){
        loop(j,0,back[i-1]+1){
            if (j + forw[i] >= m) jump[i-j] = 1;
        }
    }
    //cout<<"HI"<<endl;
    int l = 0, r=0, ans=0;
    while(l<=r){
        if (jump[r]){
            l = r+1;
            r+=m+1;
            ans++;
            //cout<<"HI: "<<r<<endl;
            if (r==n+1) return cout<<ans<<endl,0;
        }
        else r--;
    }
    cout<<-1<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
8 3 5
3 3 1 3 4 4 2 2
3 0 1 2
2 2 3
2 3 4


5 4 4 
1 0 1 2 2
2 0 1
1 1
1 2
1 3
*/






