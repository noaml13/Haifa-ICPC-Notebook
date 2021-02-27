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
const int INF = 1e14, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int t,n; cin>>t>>n;
    vi c(n+1); loop(i,0,n) cin>>c[i+1];
    int q; cin>>q;
    vector<pair<ii, int>> qur(q);
    vi ans(q);
    loop(i,0,q) cin>>qur[i].x.y>>qur[i].x.x, qur[i].y = i;
    sort(all(qur));
    vi st;
    int endM = 0, endDv = 0, endV = 0, pos = 1;
    int j = 1;
    for(auto p:qur){
        int i = p.y, x = p.x.y, y = p.x.x;
        while(j <= y){
            // enter c[j]
            endDv += 2 * pos - 1;
            endV += pos * pos;
            while (endDv > c[j]){
                if (st.size()){
                    int xx = st.back();
                    if (endDv - 2*(x-xx) > c[j]){
                        endDv -= 2 * (x-xx);
                        endV -= x*x - xx*xx;
                    }
                    else{
                        xx = x - (endDv - c[j] + 1)/2;
                    }
                }
                else{

                }
            }
            if (endDv < c[j]) //
            j++;
        }
        ans[i] = 0; // 
    }
    return 0;
}
/*
color a
cls
g++ CostPaths.cpp -o a & a
5 4
1 100 100 20
20
1 1
2 1
3 1
4 1
5 1
1 2
2 2
3 2
4 2
5 2
1 3
2 3
3 3
4 3
5 3
1 4
2 4
3 4
4 4
5 4

*/