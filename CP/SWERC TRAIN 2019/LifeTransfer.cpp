#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vi>
#define loop(i,s,e) for(int i=s;i<e;++i)
#define pb push_back
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
using namespace std;
const int INF=4e18;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    int lc,pc,lm,pm; cin>>lc>>pc>>lm>>pm;
    int t,d; cin>>t>>d;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vi c_left(n+1,0), c_need(n+1,0);
    vi m_left(n+1,0), m_need(n+1,0);
    vi age_left(n+1,0);
    loop(i,0,n){
        int dif = a[i] - lc;
        if (dif>=0) {
            c_left[i+1] = c_left[i] + min(dif, d);
        }
        else{
            c_left[i+1] = c_left[i];
            dif = -dif;
            if (dif<=d) c_need[i+1] = c_need[i] + dif;
            else c_need[i+1] = INF;
        }
        dif = a[i] - lm;
        if (dif>=0) {
            m_left[i+1] = m_left[i] + min(dif, d);
        }
        else{
            m_left[i+1] = m_left[i];
            dif = -dif;
            if (dif<=d) m_need[i+1] = m_need[i] + dif;
            else m_need[i+1] = INF;
        }
        age_left[i+1] = age_left[i] + min(a[i] -1,d);
    }
    int ans=INF;
    loop(m,0,n+1){
        int c = n-m;
        c = c/k +(c%k!=0);
        if (c_need[c]!=INF && m_need[c+m]!=INF){
            int age_need = c_need[c] + (m_need[c+m]-m_need[c]);
            if (age_need <= c_left[c] + (m_left[c+m]-m_left[c]) + (age_left[n]- age_left[c+m])){
                chkmin(ans, c*pc + m*pm + t*age_need);
            }
        }
    }
    if (ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}

