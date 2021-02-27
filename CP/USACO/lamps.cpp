/*
ID: licht.n1
PROG: lamps
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
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
int n,c;
vi clue;
vb cur(4);
set<vb> ans;
void check(){
    int cnt=0;
    loop(i,0,4) cnt+=cur[i];
    if (cnt>c) return;
    if (cnt==c-1) return;
    if (cnt==c-4) return;
    vb me(n,1);
    if (cur[0]) for(int i=0;i<n;i++) me[i]=!me[i];
    if (cur[1]) for(int i=0;i<n;i+=2) me[i]=!me[i];
    if (cur[2]) for(int i=1;i<n;i+=2) me[i]=!me[i];
    if (cur[3]) for(int i=0;i<n;i+=3) me[i]=!me[i];
    loop(i,0,n) if (clue[i]!=-1 && clue[i]!=me[i]) return;
    ans.insert(me);
}
void dfs(int i=3){
    if (i<0) return check();
    cur[i]=0; dfs(i-1);
    cur[i]=1; dfs(i-1);
}
int main() {
    ofstream cout("lamps.out");
    ifstream cin("lamps.in");
    cin>>n>>c;
    clue.resize(n,-1);
    loop(b,0,2) while(true){
        int x; cin>>x;
        if (x==-1) break;
        clue[x-1]=1-b;
    }
    dfs();
    if (!ans.size()) return cout<<"IMPOSSIBLE"<<endl,0;
    for(auto& a:ans) {loop(i,0,n) cout<<a[i];cout<<endl;}
    return 0;
}
/*
color a
cls
g++ lamps.cpp -o a & a
10
1
-1
7 -1
*/
