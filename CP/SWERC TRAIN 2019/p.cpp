#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;++i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;

//Aho-Corasick algorithm
struct AhoCorasick{
    vector<map<char,int>> to;
    vector<bool> endw;
    vector<int> link;
    int sz=1;
    AhoCorasick(): to(vector<map<char,int>>(1)), endw(vector<bool>(1,0)){}
    void push_word(string& s){
        int cur = 0;
        for(auto& c: s){
            if (!to[cur][c]) {
                to[cur][c] = sz++;
                to.pb(map<char,int>());
                endw.pb(0);
            }
            cur = to[cur][c];
        }
        endw[cur] = 1;
    }
    void create_links(){
        queue<int> q;
        q.push(0);
        link.resize(to.size(),0);
        link[0] = -1;
        int v,u,j;
        char c;
        while(q.size()){
            v = q.front();
            q.pop();
            for(auto& it:to[v]){
                c = it.x;
                u = it.y;
                j = link[v];
                while(j!=-1 && !to[j][c]) j = link[j];
                if (j!=-1) link[u] = to[j][c];
                else link[u] = 0;
                q.push(u);
                endw[u]=endw[u]||endw[link[u] ];
            }
        }
    }
    int next_state(int cur, char c){
        while(cur!=-1 && !to[cur][c]) cur = link[cur];
        if (cur==-1) return 0;
        return to[cur][c];
    }
};
const int MOD=1e6+3;

void add_mod(int& x, int y){
    x = (x+y)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int a, b, n; cin>>a>>b>>n;
    vector<string> w(n);
    AhoCorasick aho;
    loop(i,0,n){
        cin>>w[i];
        aho.push_word(w[i]);
    }
    aho.create_links();
    vector<pair<char,int>> cs;
    map<char,char> alike;
    loop(c,'a','z'+1) {
        cs.pb({c,0});
        alike[c]=c;
    }
    loop(c,'A','Z'+1) {
        cs.pb({c,1});
        alike[c]=c-'A'+'a';
    }
    loop(c,'0','9'+1){
        cs.pb({c,2});
        alike[c]=c;
    }
    alike['0'] = 'o';
    alike['1'] = 'i';
    alike['3'] = 'e';
    alike['5'] = 's';
    alike['7'] = 't';
    vector<vector<vector<vector<vi>>>> dp(b+1, vector<vector<vector<vi>>>(2, vector<vector<vi>>(2, vector<vi>(2, vi(aho.sz,0 ) ) ) ) );
    dp[0][0][0][0][0] = 1;
    loop(l,0,b){
        loop(lwC,0,2) loop(upC,0,2) loop(dig,0,2){
            loop(state,0,aho.sz){
                if (aho.endw[state]) continue;
                int cur = dp[l][lwC][upC][dig][state];
                for(auto c:cs){
                    int nextS = aho.next_state(state, alike[c.x]);
                    if (aho.endw[nextS]) continue;
                    if (c.y==0) add_mod(dp[l+1][1][upC][dig][nextS],cur);
                    if (c.y==1) add_mod(dp[l+1][lwC][1][dig][nextS],cur);
                    if (c.y==2) add_mod(dp[l+1][lwC][upC][1][nextS],cur);
                }
            }
        }
    }
    int ans=0;
    loop(l, a, b+1){
        loop(state,0,aho.sz){
            if (aho.endw[state]) continue;
            add_mod(ans, dp[l][1][1][1][state]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
