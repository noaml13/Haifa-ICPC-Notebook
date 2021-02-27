#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=998244353;
const int MAXAZ = 2*('z'-'a'+1)+10, MAXLEN=11, CORNERS=4;

vvi cnt;
char corn[CORNERS];
vvvi precalc;
int ans=0;

inline int getv(int a, int b, int c){
    int res=0, cur;
    loop(i,0,MAXAZ){
        cur = cnt[a][i] * cnt[b][i] * cnt[c][i] % MOD;
        res = (res+cur)%MOD;
    }
    return res;
}
void check(){
    int mult = 24; //4!
    loop(i,0,4) {
        int cnt=1;
        loop(j,i+1,4) if (corn[i]==corn[j]) cnt++;
        mult/=cnt;
    }
    int cur=mult;
    loop(a,0,4){
        loop(b,a+1,4){
            loop(c,b+1,4){
                cur = cur*precalc[corn[a]][corn[b]][corn[c]] %MOD;
                if (!cur) return;
            }
        }
    }
    ans=(ans+cur)%MOD;
}
void dfs(int ind=CORNERS-1, int last=0){
    if (ind<0) return check();
    loop(c,last,MAXAZ) {
        corn[ind]=c; dfs(ind-1, c);
    }
}
void solve(vector<string>& a, int len){
    if (a.size()==0) return ;
    set<string> ss;
    for(auto& s:a) {
        ss.insert(s);
        reverse(all(s));
        ss.insert(s);
    }
    cnt.clear(); cnt.resize(MAXAZ, vi(MAXAZ,0));
    for(auto& s:ss) cnt[s[0]][s[len-1]]++;
    precalc.clear();
    precalc.resize(MAXAZ, vvi(MAXAZ, vi(MAXAZ)));;
    loop(a,0,MAXAZ) loop(b,a,MAXAZ) loop(c,b,MAXAZ) 
        precalc[a][b][c] = precalc[a][c][a] = precalc[b][a][c] = precalc[b][c][a] = precalc[c][a][b] = precalc[c][b][a] = getv(a,b,c);
    dfs();
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<vector<string>> len(MAXLEN);
    string s;
    loop(i,0,n){
        cin>>s;
        int sz= s.size();
        for(auto& c:s) {
            if (c>='a' && c<='z') c-='a';
            else if (c>='A' && c<='Z') c = c-'A'+'z'-'a'+1;
            else c = c-'0'+('z'-'a'+1)*2;
        }
        len[sz].pb(s);
    }
    loop(i,1,MAXLEN) solve(len[i], i);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ Cubeword.cpp -o a & a
1
fabadf

*/



