#include <bits/stdc++.h>
#include "party.h"
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
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;



int findUnusualGuest(int n, int m, int q) {
    vi a(n+m); loop(i,0,n+m) a[i] = i;
    a = ask(a);
    loop(i,0,n+m){
        if (a.size()==i || a[i]!=i) {
            return i;
        }
    }
    int sz = min(n,m);
    bool b = (m==sz);
    int l=0, r=sz, mid, ans=-1;
    while(l<r){
        mid = (l+r)/2;
        a.clear();
        loop(i,0,mid+1) a.pb(i+(b?n:0));
        a = ask(a);
        if (a.size() > mid+1) r = ans = mid;
        else l = mid + 1;
    }
    return ans + (b?n:0);
}
/*
cls
g++ -std=c++11 -o "party" "grader.cpp" "party.cpp" -O2 -lm
party.exe
3 2 10
00010
00001
00001
10000
01100
*/
