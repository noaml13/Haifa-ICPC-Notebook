#include <bits/stdc++.h>
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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
typedef int64_t ll;
const ll INF = 1e18, MAXN = 1005;


int main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    string a,w; cin>>w>>a;
    reverse(all(w)), reverse(all(a));
    loop(i,0,m-n){
        int v = (a[i] - w[i])%26;
        if (v<0) v+=26;
        w+=char('a'+v);
    }
    reverse(all(w));
    cout<<w<<endl;
    return 0;
}
/*
color a
cls
g++ k.cpp -o a & a
5 16
again
pirpumsemoystoal


*/