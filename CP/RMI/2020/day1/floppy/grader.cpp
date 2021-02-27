#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "floppy.h"
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);++i)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);--i)
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max(a,b)
using namespace std;
const int MOD = 1e9+7, INF = 1e9+20;
void save_to_floppy(const string& s){
    cout<<s<<endl;
}

int main(){
    int n,q; cin>>n>>q;
    vi v(n); loop(i,0,n) cin>>v[i];
    //loop(i,0,n) cout<<v[i]<<" "; cout<<endl;
    read_array(0, v);
    solve_queries(0, n, bits, vi(0), vi(0));
    loop(i,0,n) cout<<arr[i]<<" ";
    return 0;
}
