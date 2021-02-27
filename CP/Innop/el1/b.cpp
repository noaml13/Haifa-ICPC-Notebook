#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;
const int AZ = 'z'-'a'+1;

int32_t main(){
    int n; cin>>n;
    vector<string> w(n);
    int l = 0;
    loop(i,0,n) {
        cin>>w[i];
        if (l<w[i].size()) l = w[i].size();
    }
    vector<vi> cnt(l,vi(AZ,0));
    loop(i,0,n){
        loop(j,0,w[i].size()){
            cnt[j][w[i][j]-'a']++;
        }
    }
    int ans=0;
    loop(i,0,l){
        ii m = {0,0};
        loop(j,0,AZ){
            if (cnt[i][j]>m.x) m = {cnt[i][j],j};
        }
        loop(j,0,AZ) {
            if (j!=m.y) ans+=cnt[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}

