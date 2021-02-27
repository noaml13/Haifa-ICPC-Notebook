/*
ID: licht.n1
PROG: socdist2
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


int32_t main() {
    ofstream cout("socdist2.out");
    ifstream cin("socdist2.in");
    int n; cin>>n;
    vii cows(n);
    vi sick;
    loop(i,0,n){
        cin>>cows[i].x>>cows[i].y; 
        if (cows[i].y) sick.pb(cows[i].x);
    }
    sort(all(cows)); sort(all(sick));
    int maxR = INF;
    loop(i,0,n-1){
        if (cows[i].y != cows[i+1].y) chkmin(maxR,cows[i+1].x  - cows[i].x);
    }
    //cout<<maxR<<endl;
    int ans=1, m=sick.size();
    loop(i,0,m-1) if (sick[i+1]-sick[i]>=maxR) ans++;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ socdist2.cpp -o a & a
6
7 1
1 1
15 1
3 1
10 0
6 1
*/
