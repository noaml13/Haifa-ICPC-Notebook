#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
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
const int INF=4e18;


int32_t main(){
    int n,k; cin>>n>>k;
    vi x(2*n);
    loop(i,0,x.size()) cin>>x[i];
    loop(i,0,n){
        k -= (x[i*2+1]-x[i*2]);
    }
    if (k<0){
        cout<<"No"<<endl;
        return 0;
    }
    if(k==0){
        cout<<"Yes"<<endl;
        loop(i,0,n)cout<<i*2+1<<" "<<i*2+2<<endl;
        return 0;
    }
    vii w;
    loop(i,0,n-1){
        int val = x[i*2+2]-x[i*2+1];
        if (val<=k)
            w.pb({val,i});
    }
    int r = w.size();
    if (r==0){
        cout<<"No"<<endl;
        return 0;
    }
    vector<vb> dp(r, vb(k+1, 0));
    vector<vb> from(r,vb(k+1,0));
    dp[0][0] = 1;
    dp[0][w[0].x] = 1;
    from[0][w[0].x] = 1;
    loop(i,1,r){
        loop(j,0,k+1){
            dp[i][j] = dp[i-1][j];
            from[i][j] = 0;
            if (j-w[i].x>=0 && !dp[i][j]){
                if (dp[i-1][j-w[i].x]){
                    dp[i][j] = 1;
                    from[i][j] = 1;
                }
            }
        }
    }

    if (dp[r-1][k]) cout<<"Yes"<<endl;
    else {
        cout<<"No"<<endl;
        return 0;
    }
    vi used;
    int cur = k;
    for(int i=r-1;i>=0;i--){
        if (cur==0) break;
        if (from[i][cur]){
            used.pb(w[i].y);
            cur -= w[i].x;
        }
    }
    //for(auto u:used) cout << u<<" ";
    int m = used.size();
    reverse(all(used));
    vi p(n);
    loop(i,0,n) p[i]=i;
    loop(i,0,m){
        int j = i +1;
        while(j<m && used[j]==used[j-1]+1) ++j;
        --j;
        int a=used[i], b= used[j]+1;
        p[a] = b;
        p[b] = a;
        i = j;
    }
    loop(i,0,n){
        if (p[i]==i){
            cout<<i*2+1<<" "<<i*2+2<<endl;
        }
        else{
            if (p[i]>i){
                cout << i*2 +1<< " "<<p[i]*2+2<<endl;
                cout << i*2+2 << " "<<p[i]*2+1<<endl;
            }
        }
    }
    return 0;
}

