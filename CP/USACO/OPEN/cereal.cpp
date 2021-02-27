/*
ID: licht.n1
PROG: cereal
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
    ofstream cout("cereal.out");
    ifstream cin("cereal.in");
    int n,m; cin>>n>>m;
    vii e(n);
    for(auto &p:e) {cin>>p.x>>p.y;p.x--; p.y--;}
    reverse(all(e));
    vi ans(n);
    vi ocp(m,-1);
    int cnt=0;
    loop(i,0,n){
        int cur = e[i].x, last = i;
        while(1){
            int who = ocp[cur];
            if (who==-1){
                ocp[cur] = last;
                cnt++;
                break;
            }
            if (last<=who) break;
            int next = e[who].y;
            ocp[cur] = last;
            last = who;
            cur = next;
        }
        //if (ocp[cur]==-1) ocp[cur]=1, cnt++;
        ans[i] = cnt;
    }
    loop(i,0,n) cout<<ans[n-i-1]<<endl;
    return 0;
}
/*
color a
cls
g++ cereal.cpp -o a & a
6 6
2 3
1 4
4 1
5 2
4 5
5 6
*/
