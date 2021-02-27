#include "brperm.h"
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);++i)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);--i)
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max(a,b)
#define all(a) a.begin(),a.end()
using namespace std;
const int MOD = 1e9+7, INF = 1e9;

int n;
string s;
vi inda, indb;
bool isT = 1;
void init(int N, const char S[]) {
    n = N;
    loop(i,0,n) {
        s+=S[i];
        if (s[i]!='a' && s[i]!='b') isT = 0;
    }
    if (isT){
        loop(i,0,n){
            if (s[i]=='a') inda.pb(i);
            else indb.pb(i);
        }
        inda.pb(n);
        indb.pb(n);
    }
    return;
}
int back(int x, int k){
    int y = 0;
    loop(i,0,k) if(x&(1<<i)) y|=(1<<(k-i-1));
    return y;
}
int query(int ind, int k) {
    if (ind + (1<<k) > n) return 0;
    if (isT){
        int sa = lower_bound(all(inda), ind)-inda.begin(), ea = lower_bound(all(inda), ind+(1<<k))-inda.begin();
        int sb = lower_bound(all(indb), ind)-indb.begin(), eb = lower_bound(all(indb), ind+(1<<k))-indb.begin();
        if (ea-sa > eb - sb) {
            loop(i,sb,eb){
                int j = back(indb[i]-ind, k);
                if (s[indb[i]]!=s[ind+j]) return 0;
            }
        }
        else{
            loop(i,sa,ea){
                int j = back(inda[i]-ind, k);
                if (s[inda[i]]!=s[ind+j]) return 0;
            }
        }
        return 1;
    }
    loop(i,0,(1<<k)){
        int j = back(i, k);
        if (s[ind+i]!=s[ind+j]) return 0;
    }
    return 1;
}
/*
color
cls
g++ brperm.cpp brperm.h grader.cpp -o a & a
aaabaabb
0 3
1 1
1 2
3 2
*/