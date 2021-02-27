#include <bits/stdc++.h>
#define int int64_t
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
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    string s; cin>>s;
    int n = s.size();
    bool b = 0;
    string t = "ACM";
    loop(i,0,n-2){
        bool bb = 1;
        loop(j,0,3) if (t[j]!=s[i+j]) bb = 0;
        if (bb) b = 1;
    }
    if (b) cout<<"Fun!"<<endl;
    else cout<<"boring..."<<endl;
    return 0;
}
/*
color a
cls
g++ k.cpp -o a & a
SWISSSUBREGIONALACMICPC



*/