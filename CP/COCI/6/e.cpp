#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
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
const int INF = 1e18, MOD = 1e9+7;
int mult(int a, int b){
    if (b==0) return 0;
    int v = mult(a,b/2);
    v = (v+v)%MOD;
    if (b%2) v = (v+a)%MOD;
    return v;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vector<map<string,int>> names(n);
    vector<map<string,int>> numbers(n);
    string s;
    loop(i,0,n){
        loop(j,0,k){
            cin>>s;
            if (numbers[i].find(s)==numbers[i].end()){
                numbers[i][s] = names[i].size();
                names[i][s]=0;
            }
            names[i][s]++;
        }
    }
    vvi dp(n,vi(k,0));
    int ans=0;
    for(auto pa:numbers[0]){
        s = pa.x; int j = pa.y;
        dp[0][j]=names[0][s];
        ans+=dp[0][j];
    }
    loop(i,1,n){
        ans=0;
        for(auto pa:numbers[i]){
            s = pa.x; int j = pa.y;
            int dup = names[i][s];
            string a,b;
            loop(i,0,s.size()-1) a+=s[i],b+=s[i+1];
            //cout<<i<<" "<<j<<" "<<s<<" "<<a<<" "<<b<<" "<<names[i][s]<<endl;
            dp[i][j] = 0;
            if (numbers[i-1].find(a)!=numbers[i-1].end()) dp[i][j]+=dp[i-1][numbers[i-1][a]];
            if (a!=b && numbers[i-1].find(b)!=numbers[i-1].end()) dp[i][j]+=dp[i-1][numbers[i-1][b]];
            dp[i][j]%=MOD;
            dp[i][j] = mult(dp[i][j], names[i][s]);
            ans=(ans + dp[i][j])%MOD;
        }
    }
    //loop(i,0,n) {loop(j,0,k) cout<<dp[i][j]<<" ";cout<<endl;}
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -std=c++11 -O2 -static -s -lm -o a & a
3 2
a a
aa aa
aaa aab



*/


 