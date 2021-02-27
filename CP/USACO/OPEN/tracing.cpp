/*
ID: licht.n1
PROG: tracing
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9;

int n,t;
vb fin;
vector<pair<int,ii>> e;
int mink=INF, maxk=0;
bool simK(int s, int k){
    if (!fin[s]) return 0;
    vi times(n, -INF);
    times[s] = k;
    loop(i,0,t){
        int a = e[i].y.x, b=e[i].y.y, tt = e[i].x;
        if (times[a]!=-INF && times[b]!=-INF) {
            times[a]--; times[b]--;
            continue;
        }
        if (times[a]==-INF && times[b]==-INF) continue;
        if (times[a]<times[b]) swap(a,b);
        if (times[a]>0) {
            times[a]--;
            times[b] = k;
            if (!fin[b]) return 0;
        }
    }
    loop(i,0,n) if (fin[i] && times[i]==-INF) return 0;
    return 1;
}
bool sim(int s){
    bool pos=0;
    loop(k,0,t+2){
        if (simK(s,k)){
            chkmin(mink,k);
            chkmax(maxk, k);
            pos=1;
        }
    }
    return pos;
}
int32_t main() {
    ofstream cout("tracing.out");
    ifstream cin("tracing.in");
    cin>>n>>t;
    e.resize(t); fin = vb(n);
    string s; cin>>s; loop(i,0,n) fin[i]=(s[i]=='1');
    for(auto& a:e) {cin>>a.x>>a.y.x>>a.y.y; a.y.x--; a.y.y--;}
    sort(all(e));
    int ans=0;
    loop(i,0,n) ans+=sim(i);
    cout<<ans<<" "<<mink<<" ";
    if (maxk==t+1) cout<<"Infinity"<<endl;
    else cout<<maxk<<endl;
    return 0;
}
/*
color a
cls
g++ tracing.cpp -o a & a
4 3
1100
7 1 2
5 2 3
6 2 4
*/
