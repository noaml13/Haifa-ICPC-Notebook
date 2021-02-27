#include <bits/stdc++.h>
//#define int int64_t
#define ii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9;

const int MAX = 1e6 + 10;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,w; cin>>n>>w;
    vi pos(n, 0);
    vi rank(MAX, 0), cnt(MAX);
    rank[0] = 1; cnt[0] = n;
    vi ans(n); 
    vi sum_rank(MAX), lastC(MAX, 0);
    auto fix_level = [&](int p, int i){
        sum_rank[p] += rank[p] * (i - lastC[i]);
        lastC[p] = i;
    };
    loop(i,1,w+1){
        int k; cin>>k;
        vi a(k);
        loop(j,0,k){
            int c; cin>>c; c--;
            int p = pos[c];
            fix_level(p, i-1);
            fix_level(p+1, i-1);
            a[i] = c;
        }
        loop(i,0,k){
            int c = a[i], p = pos[c];
            ans[c] += sum_rank[p] - sum_rank[p+1];
            cnt[p]--;
            cnt[p+1]++;
            if (rank[p+1]==0) rank[p+1] = rank[p];
            if (cnt[p]==0) rank[p] = 0;
            else {
                rank[p]++;
            }
            pos[c]++;
        }
        loop(j,0,n) cout<<rank[pos[j]]<<endl;
        // loop(j,0,10) cout<<"J: "<<j<<" "<<rank[j]<<" "<<cnt[j]<<endl;
    }
    loop(i,0,n) {
        fix_level(pos[i], w);
        ans[i] += sum_rank[pos[i]];
    }
    cout<<fixed<<setprecision(10);
    for(auto x:ans) cout<<x * 1.0 / w<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
3 2
2 1 2
2 1 3




*/