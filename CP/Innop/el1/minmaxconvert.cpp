#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define iiii pair<ii,ii>
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
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n), b(n);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    int ind = 0;
    vector<pair<ii,bool>> ans, af;
    loop(i,0,n){
        if (a[max(ind,i)]==b[i]) continue;
        if (i && b[i-1]==b[i]) {
            chkmax(ind,i);
            af.pb({{i-1,i},a[ind]<b[i-1]});
            continue;
        }
        if (i && ind==i-1 && a[i-1]==b[i]){
            chkmax(ind,i);
            ans.pb({{i-1,i},a[i-1]>a[i]});
            continue;
        }
        chkmax(ind,i);
        int mini = INF;
        while(ind<n && a[ind]!=b[i]){
            chkmin(mini, a[ind]);
            ind++;
        }
        if (ind==n) return cout<<-1<<endl,0;
        bool type = mini>a[ind];
        ans.pb({{i,ind-1}, type});
        ans.pb({{i,ind}, !type});
    }
    cout<<ans.size()+af.size()<<endl;
    for(auto x: ans) cout<<(x.y?'M':'m') <<" " <<x.x.x+1<<" " << x.x.y+1<<endl;
    for(auto x: af) cout<<(x.y?'M':'m') <<" " <<x.x.x+1<<" " << x.x.y+1<<endl;
    return 0;
}





