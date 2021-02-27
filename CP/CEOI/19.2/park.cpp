#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
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
const int INF = 2e9, MOD = 998244353;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    ii e[100];
    loop(i,0,m) cin>>e[i].x>>e[i].y, e[i].x--, e[i].y--;
    int order[10]; loop(i,0,n) order[i] = i;
    map<int, int> check;
    do{
        int cur = 0;
        int cnt = 0;
        loop(i,0,m) if(order[e[i].x]<order[e[i].y]) {
            cnt++;
            cur |= int(1)<<i;
        }
        check[cur] = cnt;
    }while(next_permutation(order, order+n));
    int ans = 0;
    for(auto p:check) ans = (ans+p.y)%MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ park.cpp -o a & a
10 10
1 2
2 3
1 3
2 4
2 5
6 7
8 9
8 7
9 10
10 1
*/