#include <bits/stdc++.h>
#include "sqsort.h"
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e; i++)
#define loopr(i,s,e) for(int i=e-1;i>=s; i--)
#define all(a) a.begin(),a.end()
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using namespace std;
const int INF = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vi inds, back;
void fix(ii& a){
    if (back[a.x]>back[a.y]) swap(a.x, a.y);
}
bool mycamp(ii a, ii b){
    fix(a), fix(b);
    if (back[a.x]<=back[b.x] && back[a.y]<=back[b.y]) return 1;
    if (back[b.x]<=back[a.x] && back[b.y]<=back[a.y]) return 0;
    return cmp(a.x, a.y, b.x, b.y);
}

void merge_sort(vii& a){
    if (a.size()<=1) return ;
    int n = a.size();
    vii x[2];
    loop(i,0,n) x[i<n/2].pb(a[i]);
    merge_sort(x[0]), merge_sort(x[1]);
    int i = 0, j = 0;
    int ind = 0;
    while(i<x[0].size() && j<x[1].size()){
        if (mycamp(x[0][i], x[1][j])) a[ind++] = x[0][i++];
        else a[ind++] = x[1][j++];
    }
    while(i<x[0].size()) a[ind++] = x[0][i++];
    while(j<x[1].size()) a[ind++] = x[1][j++];
}
vii solve(int n){
    inds.resize(n);
    loop(i,0,n) inds[i] = i;
    sort(all(inds), [&](int a, int b){
        return cmp(a,a,b,b);
    });
    back.resize(n);
    loop(i,0,n) back[inds[i]] = i;
    vii ans;
    /*loop(i,0,n) loop(j,0,i+1) ans.pb({inds[j],inds[i]});
    vii res;
    loop(i,0,(ans.size()+1)/2){
        res.pb(ans[i]);
        if (ans[i]!=ans[ans.size()-i-1]) res.pb(ans[ans.size()-i-1]);
    }
    ans = res;*/
    loop(k,0,n){
        vii tmp;
        loop(i,0,n-k) tmp.pb({inds[i], inds[i+k]});
        //if (k%2) reverse(all(tmp));
        //shuffle(all(tmp), rng);
        for(auto p:tmp) ans.pb(p);
    }
    merge_sort(ans);
    return ans;
}
/*
color a
cls
g++ Lgrader.cpp sqsort.h sqsort.cpp -o b & b
2000

*/