#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD = 1e9 + 7;
const int MAXN = 2e5+10;


const int k = 3, n = 1<<k, sz = 1<<n,mask = sz-1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist = uniform_int_distribution<int>(0,n-1);
inline int mrand(){
    return dist(rng);
}
int shift(int m, int x){
    int v = (m<<x);
    return (v&mask) | (v>>n);
}
int col;
bitset<sz> check;
int cur;
vi pos, id;
void go(int v){
    int p = mrand();
    cur ^= shift(v, p);
    check[cur] = col;
    id.pb(v);
    pos.pb(p);
}
string getBinary(int x){
    string s;
    for(int i=0;i<n; i++) 
        s=char(x%2 + '0') + s, x/=2;
    return s;
}
vector<int> solve(int k){
    if (k==0){    
        return vector<int>({1});    
    }
    k--;
    vector<int> sml = solve(k);
    int ss = 1<<k; // 2^k
    vi sol;
    int r = sml.size();
    for(int x:sml)  sol.pb(x | (x<<ss)); // make x|x
    loop(i,0,r){
        sol.pb(sml[i]); // make x|0
        for(int x:sml)  sol.pb(x | (x<<ss)); // make x|x
    }
    return sol;
}
vi sol;


int test(){
    cur = 0, pos.clear(), id.clear();
    check[cur] = col;
    if(!sol.size()) sol = solve(k);
    int who = -1;
    if (sol.size()!=sz-1) who = 0;
    for(int x:sol) {
        cur^=shift(x, mrand());
        int v = check[cur]=check[cur]^1;
        if(v==col) who = x;
    }
    /*
    sol for k=2
    go(mask);
    go(0b1010);
    go(mask);
    go(0b1100);
    go(mask);
    go(0b1010);
    go(mask);
    go(0b1000);
    go(mask);
    go(0b1010);
    go(mask);
    go(0b1100);
    go(mask);
    go(0b1010);
    go(mask);
    */
    if (who!=-1){
        cout<<"NOT OK! "<<col<<endl;
        cout<<"MISSING: "<<getBinary(who)<<endl;
        int r = pos.size();
        loop(i,0,r) cout<<pos[i]<<" "<<getBinary(id[i])<<endl;
        cout<<endl<<"EXIT"<<endl;
        exit(0);
    }
    col = !col;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1000; //cin>>t;
    col = 0;
    cout<<"START"<<endl;
    loop(i,0,t) test();
    cout<<"OK!"<<endl;
    return 0;
}
/*
color a
cls
g++ Binarytest.cpp -o a & a




*/