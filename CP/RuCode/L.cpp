#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD=1e9+7;



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i], a[i]--;
    vi len;
    vb check(n);
    loop(i,0,n){
        if (check[i]) continue;
        int cur = i, cnt = 1;
        while(a[cur]!=i) cur = a[cur], check[cur] = 1, cnt++;
        len.pb(cnt);
    }
    vb can(n+1);
    sort(all(len));
    int m = len.size();
    int mm = len.back();
    loop(i,1,mm+1) can[i] = 1;
    loop(i,0,m-1) if(len[i]==len[i+1]) can[2*len[i]] = 1;
    len.resize(unique(all(len)) - len.begin());
    m = len.size();
    loop(i,0,m){
        loop(j,0,i){
            can[len[i]+len[j]] = 1;
        }
    }
    loop(i,1,n+1) cout<<(can[i]?"Yes":"No")<<endl;
    return 0;
}
/*
color a
cls
g++ L.cpp -o a & a
10
2 3 4 5 1 10 8 9 7 6
*/