#include <bits/stdc++.h>
#define ll int64_t
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define pb push_back
#define loop(i,s,e) for(int i=(s); i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1; i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const ll INF = 1e18, MOD = 1e9+7;
void add(ll &a, ll b){ a = (a+b)%MOD;}

int32_t main(){
    ios_base::sync_with_stdio(0);
    int n = 26;
    vvi a(n);
    loop(i,0,n){
        string s; cin>>s;
        for(auto c:s) a[i].pb(c-'A');
        sort(all(a[i]));
        a[i].resize(unique(all(a[i]))-a[i].begin());
    }
    vvi b[2];
    loop(i,0,n) b[i<n/2].pb(a[i]);
    vii subset[2];
    vi ans, vals;
    int sml = 1e5; 
    vi smlans(sml); 
    vvi smlval(sml);
    ll pp = 60; vvi p2(pp);
    int mask = (1<<n) - 1;
    ll res = 0;
    loop(k,0,2){
        #define dp subset[op]
        #define next subset[op^1]
        int op = 0;
        dp.clear(), next.clear();
        dp.pb({0,1});
        for(auto v:b[k]){
            while(dp.size()) {
                auto &p = dp.back();
                for(auto x:v){
                    if (p.x & (1<<x)) continue;
                    next.pb({p.x|(1<<x), p.y});
                }
                dp.pop_back();
            }
            sort(all(next));
            reverse(all(next));
            while(next.size()){
                auto &p = next.back();
                if (dp.size() && dp.back().x==p.x) dp.back().y+=p.y;
                else dp.pb(p);
                next.pop_back();
            }
        }
        if (k){
            int sz[2] = {(int)ans.size(), (int)dp.size()};
            loop(i,0,sz[0]){
                //cout<<p.x<<" "<<p.y<<endl;
                int m = mask^ans[i];
                int l = 0, r = sz[1], mid;
                while(l<r){
                    mid = (l+r)/2;
                    if (dp[mid].x==m){
                        res+=ll(vals[i])*dp[mid].y;
                        break;
                    }
                    if (dp[mid].x>m) r = mid;
                    else l = mid + 1;
                }
            }
            loop(mult,0,sml){
                for(auto x:smlval[mult]){
                    int m = mask^x;
                    int l = 0, r = sz[1], mid;
                    while(l<r){
                        mid = (l+r)/2;
                        if (dp[mid].x==m){
                            res+=ll(mult)*dp[mid].y;
                            break;
                        }
                        if (dp[mid].x>m) r = mid;
                        else l = mid + 1;
                    }
                }
            }
            loop(x,0,sml){
                int mult = smlans[x];
                if (!mult) continue;
                int m = mask^x;
                int l = 0, r = sz[1], mid;
                while(l<r){
                    mid = (l+r)/2;
                    if (dp[mid].x==m){
                        res+=ll(mult)*dp[mid].y;
                        break;
                    }
                    if (dp[mid].x>m) r = mid;
                    else l = mid + 1;
                }
            }
            loop(mult,0,pp){
                for(auto x:p2[mult]){
                    int m = mask^x;
                    int l = 0, r = sz[1], mid;
                    while(l<r){
                        mid = (l+r)/2;
                        if (dp[mid].x==m){
                            res+=(ll(1) << mult)*dp[mid].y;
                            break;
                        }
                        if (dp[mid].x>m) r = mid;
                        else l = mid + 1;
                    }
                }
            }
        }
        else for(auto p:dp) {
            if (p.y<sml) smlval[p.y].pb(p.x);
            else if (p.x<sml) smlans[p.x]=p.y;
            else {
                int j = 0;
                for(;p.y>(ll(1)<<j);j++);
                if (p.y==ll(1)<<j){
                    p2[j].pb(p.x);
                }   
                else ans.pb(p.x), vals.pb(p.y);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o c & c
ELLY KRISS STAN WU ALEX ZOE POOH
KATE VILI MAXIM QT G ZAEK BOBI TEO
YOYO DEQN FIL CECO DAWG JORO MONI
SASHO DUDA VESKO POOH
*/