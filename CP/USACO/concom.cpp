/*
ID: licht.n1
PROG: concom
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
    ofstream cout("concom.out");
    ifstream cin("concom.in");
    int m; cin>>m;
    map<int,int> conv; int cnt=1;
    vi aconv(1,-1);
    vector<pair<ii,int>> tmp(m);
    loop(i,0,m){
        int a,b,p; cin>>a>>b>>p; 
        if (!conv[a]) conv[a]=cnt++, aconv.pb(a);
        if (!conv[b]) conv[b]=cnt++, aconv.pb(b);
        tmp[i] = {{conv[a],conv[b]},p};
    }
    int n = cnt;
    vvi own(n,vi(n,0));
    for(auto t:tmp) own[t.x.x][t.x.y] = t.y;
    //loop(i,0,n) {loop(j,0,n) cout<<own[i][j]<<" "; cout<<endl;}
    vvb cont(n,vb(n,0));
    loop(i,0,n) cont[i][i] = 1;
    vii ans;
    loop(i,0,n){
        vi me = own[i];
        set<ii> s;
        loop(j,0,n) if(i!=j) s.insert({-me[j],j});
        while(s.size()){
            ii cur = *s.begin(); s.erase(s.begin());
            if (cur.x>=-50) break;
            cont[i][cur.y] = 1;
            loop(j,0,n){
                if (!cont[i][j]){
                    s.erase({-me[j],j});
                    me[j]+=own[cur.y][j];
                    s.insert({-me[j],j});
                }
            }
        }
        loop(j,0,n) if(i!=j && cont[i][j]) ans.pb({i,j});
    }
    for(auto& a:ans) a.x=aconv[a.x],a.y=aconv[a.y];
    sort(all(ans));
    for(auto a:ans) cout<<a.x<<" "<<a.y<<endl;
    return 0;
}
/*
color a
cls
g++ concom.cpp -o b & b
1 
30 80 100
*/
