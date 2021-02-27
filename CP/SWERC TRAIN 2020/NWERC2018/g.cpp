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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

ii operator+(const ii& a, const ii& b){
    return {a.x+b.x, a.y+b.y};
}
int operator*(ii a, ii b){
    return a.x*b.x + a.y*b.y;
}
map<char, ii> conv = {{'D', {0,-1}}, {'U',{0,1}}, {'R',{1,0}}, {'L',{-1,0}}};
int32_t main(){
    ios_base::sync_with_stdio(false);
    string s; cin>>s;
    int n = s.size();
    int d = 1000;    
    ii pos = {0,0};
    vii res = {pos};
    ii last = {0,0};
    for(char c:s){
        ii dir = conv[c];
        if (dir*last<0){
            
        }
        dir.x*=d, dir.y*=d;
        last = dir;
    }
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
DLDLRUR






*/