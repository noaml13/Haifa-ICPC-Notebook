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
const int INF = 1e9;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n; n--;
    int x; cin>>x;
    vi p(n);
    loop(i,0,n) cin>>p[i];
    sort(all(p)); reverse(all(p));
    vi dif(n); 
    loop(i,0,n-1) dif[i] = p[i] - p[i+1];
    int need = x - p[0];
    int ans = dif[0];
    int cnt = 2, k = 1;
    loop(i,1,n){
        int v = dif[i];
        if (i < n-1 && v * k <= need){
            ans += v * (k+1);
            cnt++;
            //while(i+1<n-1 && dif[i+1]==0) i++, cnt++;
            need -= v * k;
            while(cnt >= (int(1)<<(k+1))) k++;
        }
        else{
            v = need / k;
            ans += v * (k+1);
            need -= v * k;
            ans += need;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ j.cpp -o a & a
5
8 4 3 5 2




*/