#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;



int solve(int t){
    int n; cin>>n;
    vector<pair<ii,int>> s(n); loop(i,0,n) cin>>s[i].x.x>>s[i].x.y, s[i].y = i;
    sort(all(s));
    int end1=-1, end2=-1;
    vi ans(n);
    loop(i,0,n){
        int st = s[i].x.x;
        if (end1>st && end2>st) return cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl,0;
        if (end1>st){
            ans[s[i].y] = 1;
            end2 = s[i].x.y;
        }
        else{
            ans[s[i].y] = 0;
            end1 = s[i].x.y;
        }
    }
    cout<<"Case #"<<t<<": ";
    loop(i,0,n) cout<<(ans[i]?'C':'J');
    cout<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve(i+1);
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440

*/




