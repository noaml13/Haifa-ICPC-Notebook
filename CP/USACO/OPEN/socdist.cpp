/*
ID: licht.n1
PROG: socdist
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
const int INF = 1e18+2;

int n,m;
vii inter;
bool can(int d){
    int cnt=0, last=-INF;
    int ind=0;
    loop(i,0,n){
        int cur;
        while(1){
            cur = max(last+d, inter[ind].x);
            if (cur<=inter[ind].y) break;
            ind++;
            if (ind==m) return 0;
        }
        last = cur;
    }
    return 1;
}
int32_t main() {
    ofstream cout("socdist.out");
    ifstream cin("socdist.in");
    cin>>n>>m;
    inter.resize(m);
    for(auto &p:inter) cin>>p.x>>p.y;
    sort(all(inter));
    int l=1, r=INF, mid, ans=-1;
    while(l<r){
        mid = (l+r)/2;
        if (can(mid)) l=mid+1, ans=mid;
        else r=mid;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ socdist.cpp -o a & a
5 3
0 2
4 7
9 9
*/
