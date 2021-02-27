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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vii a(n); loop(i,0,n) cin>>a[i].x, a[i].y=i;
    vector<pair<ii, int>> b(m); 
    loop(i,0,m) cin>>b[i].x.x, b[i].y = i;
    loop(i,0,m) cin>>b[i].x.y;
    sort(all(a)); reverse(all(a));
    sort(all(b)); reverse(all(b));
    set<ii> s;
    int j = 0;
    vi ans(n);
    loop(i,0,n){
        while(j<m && b[j].x.x>=a[i].x) s.insert({b[j].x.y, b[j].y}), j++;
        if (s.size()==0) return cout<<"impossible"<<endl,0;
        ans[a[i].y] = s.begin()->y;
        s.erase(s.begin());
    }
    loop(i,0,n) cout<<ans[i]+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
2 5
40 200
1000 199 201 10 50
600 300 400 200 800





*/