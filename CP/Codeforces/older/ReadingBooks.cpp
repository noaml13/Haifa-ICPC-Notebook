#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,k; cin>>n>>m>>k;
    
    set<ii> nei,a,b,both;
    loop(i,0,n) {
        int t,x,y; cin>>t>>x>>y;
        if (x && y) both.insert({t,i});
        if (x && !y) a.insert({t,i});
        if (!x && y) b.insert({t,i});
        if (!x && !y) nei.insert({t,i});
    }
    int ans = 0, amt = -1;
    k = m-k;
    int r = nei.size();
    loop(x,0,min(r,k)){
        
    }
    return 0;
}
/*
color a
cls
g++ ReadingBooks.cpp -o a & a
6 3 1
6 0 0
11 1 0
9 0 1
21 1 1
10 1 0
8 0 1


*/




