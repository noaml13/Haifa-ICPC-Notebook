/*
ID: licht.n1
PROG: moop
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
const int INF = 1e18;


int32_t main() {
    ofstream cout("moop.out");
    ifstream cin("moop.in");
    int n; cin>>n;
    vii p(n);
    for(auto &x:p) cin>>x.x>>x.y;
    sort(all(p));
    vii line;
    loop(i,0,n){
        if (line.size()==0 || line.back().y>p[i].y) line.pb(p[i]);
    }
    reverse(all(p));
    map<ii, int> conv;
    loop(i,0,n) conv[p[i]]=i;
    vi maxpref(n+1,-INF);
    loop(i,0,n) maxpref[i+1]=max(maxpref[i], p[i].y);
    int ans=line.size();
    loop(i,0,line.size()-1){
        if (maxpref[conv[line[i+1]]]>=line[i].y) ans--;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ moop.cpp -o a & a
3
0 0
1 1
-1 3
*/
