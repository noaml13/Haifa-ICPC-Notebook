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

int n;
vi hist;
int cc = 0;

void add(int i, int b){
    if (i<b && hist[i]++==0) cc++;
}
void sub(int i, int b){
    if (i<b && --hist[i]==0) cc--;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    hist.resize(n+1);
    loop(i,0,n) add(a[i], n+1);
    int cnt = 0;
    while(hist[cnt]) cnt++;
    if (cnt == 0) return cout<<1<<" "<<1<<endl,0;
    loop(i,0,n) sub(a[i],n+1);
    int j = 0;
    int len = n-1; ii seg = {0,n-1};
    loop(i,0,n){
        add(a[i], cnt);
        while(j<=i && (a[j]>cnt || hist[a[j]]>1)) {
            sub(a[j++], cnt);
        }
        if (cc==cnt){
            int ll = i - j;
            if (ll<len) len = ll, seg = {j,i};
        }
    }
    cout<<seg.x+1<<" "<<seg.y+1<<endl;
    return 0;
}
/*
color a
cls
g++ k.cpp -o a & a
5
0 1 0 1 2

7
7 2  0 1 8 4 3

4
0 1 2 3
*/