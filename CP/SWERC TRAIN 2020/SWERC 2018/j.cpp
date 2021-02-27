#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int int64_t
#define ii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7;

typedef unsigned long long uint64;
struct hasher {
    uint64 s[2];
    hasher(uint64 seed) {
        s[0] = seed;
        s[1] = seed ^ 0x7263d9bd8409f526;
    }
    uint64 next() {
        uint64 s0 = s[0];
        uint64 s1 = s[1];
        uint64 result = s0 + s1;
        s1 ^= s0;
        s[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
        s[1] = (s1 << 36) | (s1 >> 28);
        return result;
    }
};
const int MAXN = 1e4;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto unidist = uniform_int_distribution<int>(0, MAXN);

int32_t main(){
    int n; cin>>n;
    vector<hasher> h;
    loop(i,0,4) {
        uint64 s; cin>>s;
        h.pb(hasher(s));
    }
    int mask = (int(1)<<n)-1;
    vvii codes(4);
    loop(i,0,4){
        int cnt = 0;
        loop(j,0,MAXN){
            int step = 1 + unidist(rng);
            loop(k,0,step-1) h[i].next();
            cnt += step;
            codes[i].pb({h[i].next()&mask, cnt});
        }
    }
    map<int, ii> table;
    for(auto p:codes[0]) for(auto q:codes[1]){
        table[p.x^q.x] = {p.y, q.y};
    }
    for(auto p:codes[2]) for(auto q:codes[3]){
        auto it = table.find(p.x^q.x);
        if (it!=table.end()){
            cout<<it->y.x<<" "<<it->y.y<<" "<<p.y<<" "<<q.y<<endl;
            exit(0);
        }
    }
    return 0;
}
/*
color a
cls
g++ j.cpp -o a & a
50
3641603982383516983 445363681616962640 868196408185819179 1980241222855773941



*/