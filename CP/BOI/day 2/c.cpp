#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e18;


int n,m,q; 
vi res;
vector<string> str;
vb good;
vector<string> anti;

string norm(string& a){ // 50 char $ 50 char
    int r = a.size();
    if (r<=100) return a;
    string res;
    loop(i,0,50) res+=a[i];
    res+="$";
    loop(i,r-50,r) res+=a[i];
    return res;
}
bool in(string& a){
    int r = a.size();
    for(auto &b:anti){
        int k = b.size();
        if (k>r) continue;
        loop(i,0,r-k+1){
            bool is = 1;
            loop(j,0,k){
                if (b[j]!=a[i+j]) {is=0; break;}
            }
            if (is) return 1;
        }
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>q;
    res.resize(n,0); good.resize(n,1);
    str.resize(n);
    str[0] = "0"; 
    str[1]  = "1";
    res[0] = res[1] = 1;
    vvvi g(n);
    loop(i,0,m){
        //cout<<"HI"<<endl;
        int a,k; cin>>a>>k;
        vi cur(k); loop(j,0,k) cin>>cur[j];
        g[a].pb(cur);
    }
    if (q==0){ // first subtask
        loop(i,2,n) res[i]=INF;
        loop(_,0,n){
            loop(i,2,n){
                for(auto vec:g[i]){
                    int v = 0;
                    for(auto x:vec) {
                        if (res[x]==INF){
                            v=INF; continue;
                        }
                        v+=res[x];
                    }
                    chkmin(res[i], v);
                }
            }
        }
        loop(i,2,n){
            if (res[i]==INF) cout<<"YES"<<endl;
            else cout<<"NO "<<res[i]<<endl;
        }
        return 0;
    }
    anti.resize(q);
    loop(i,0,q){
        anti[i] = "";
        int k; cin>>k;
        loop(j,0,k){
            int x; cin>>x;
            if (k==1){
                good[x]=0;
            }
            anti[i]+=char(x+'0');
        }
    }
    bool flag = 1;
    while(flag){
        flag = 0;
        loop(i,2,n){
            if (res[i]) continue;
            for(auto vec:g[i]){ //1 vec
                bool can = 1;
                for(auto x:vec) if(res[x]==0){
                    can = 0;
                    continue;
                }
                if (can){
                    res[i] = 0;
                    str[i] = "";
                    for(auto x:vec) {
                        res[i]+=res[x];
                        str[i] += str[x];
                        if (!good[x]) good[i]=0;
                    }
                    if (good[i]) good[i]=!in(str[i]);
                    str[i] = norm(str[i]);
                    flag = 1;
                }
            }
        }
    }
    loop(i,2,n){
        /*cout<<good[i]<<" "<<str[i]<<endl;
        cout<<in(str[i])<<endl;*/
        if (!good[i] || res[i]==0) cout<<"YES"<<endl;
        else cout<<"NO "<<res[i]<<endl;
    }
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6 4 2
2 2 0 1
3 3 2 0 0
4 4 0 3 1 2
5 2 2 1
2 1 1
5 0 0 1 0 0




*/