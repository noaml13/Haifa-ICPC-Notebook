#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;

int solve(){
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i], a[i]--;
    vi sz;
    vb check(n);
    loop(i,0,n){
        if (check[i]) continue;
        int c = i, cnt=0;
        while(!check[c]){
            check[c] = 1;
            c = a[c];
            cnt++;
        }
        sz.pb(cnt);
    }
    int m = 1, ans = 0;
    if (n%2){
        loop(i,0,(n-3)/2) m = (m*2)%MOD;
        m = (m*3)%MOD;
        vi cnt(2);
        vi s;
        bool f = 0;
        for(int x:sz){
            if (x%2==0){
                while(x>4){
                    x-=4;
                    ans++;
                }
            }
            else{
                while(x>5){
                    x-=4;
                    ans++;
                }
                if (x==3 && !f) f = 1;
                else s.pb(x);
                /*if (x==5 && !f) f = 1, ans++;
                else{
                    if (x==5) ans++, x-=4;
                    cnt[x/2]++;
                } */
            }
        }
        if(f){
            for(int x:s){
                if (x==5) x-=4, ans++;
                cnt[x/2]++;
            }
            int amt = min(cnt[0], cnt[1]);
            cnt[0]-=amt, cnt[1]-=amt;
            ans+=amt;
            ans+=cnt[0]/2;
            ans+=cnt[1];
        }
        else{
            int cnt = 0;
            for(int x:s){
                if (x==5 && !f) ans++, f = 1;
                else cnt++, ans+=(x==5);
            }
            ans+=(cnt+1)/2;
        }
    }
    else{
        loop(i,0,n/2) m = (m*2)%MOD;
        vi cnt(2);
        for(int x:sz){
            while(x>4){
                x-=4;
                ans++;
            }
            if (x%2) cnt[x/2]++;
        }
        int amt = min(cnt[0], cnt[1]);
        cnt[0]-=amt, cnt[1]-=amt;
        ans+=amt;
        ans+=cnt[0]/2;
        ans+=cnt[1];
    }
    cout<<m<<" "<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
2
9
2 3 4 5 1 7 8 6 9
11
2 3 1 5 6 4 8 9 10 11 7

5
4
2 3 4 1
4
2 3 1 4
4
2 1 4 3
4
2 1 3 4
4
1 2 3 4



*/