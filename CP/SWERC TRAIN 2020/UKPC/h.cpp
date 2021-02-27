#include <bits/stdc++.h>
#define int int64_t
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
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long double ld;
typedef long long ll;
const ll INF = 1e18;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int maxi,m; cin>>maxi>>m;
    vi d(m); loop(i,0,m) cin>>d[i];
    int n; cin>>n;
    vector<pair<ii, int>> aa(n);
    loop(i,0,n) cin>>aa[i].x.y>>aa[i].x.x, aa[i].y=i;
    sort(all(aa));
    vi inds(n), mini(n), pos(n);
    loop(i,0,n) inds[i] = aa[i].y, mini[i] = aa[i].x.y, pos[i] = aa[i].x.x-1;
    auto ok = [&](int i){
        bool b = 0;
        if (pos[i]==m-1) b = 1;
        else if (i && d[pos[i]]-d[pos[i-1]] <= maxi) b = 1;
        else if (i+1<n && d[pos[i+1]]-d[pos[i]] <= maxi) b = 1;
        return b;
    };
    auto check = [&](int i){
        bool b = 1;
        if (pos[i]>=m) b = 0;
        else if (i && (!ok(i) || !ok(i-1))) b = 0;
        else if (i+1<n && pos[i+1]<m-1 && d[pos[i+1]]-d[pos[i]]<max(mini[i], mini[i+1])) b = 0;
        return b;
    };
    auto check2 = [&](int i){
        pos[i]++;
        bool b = check(i);
        pos[i]--;
        return b;
    };
    set<int> move;
    loop(i,0,n) if(check2(i)) move.insert(i);
    vi ans;
    while(move.size()){
        int cur = *move.begin(); move.erase(move.begin());
        //if (!check2(cur)) cout<<"FUCK: "<<cur<<" "<<pos[cur]<<endl;
        pos[cur]++; ans.pb(cur);
        //cout<<"CUR: "<<cur<<" "<<pos[cur]<<endl;
        //cout<<"CUR: "<<cur+1<<endl;
        loop(b,-1,2) {
            if(cur+b>=0 && cur+b<n && check2(cur+b)) 
                move.insert(cur+b);
        }
    }
    bool b = 1;
    //cout<<"POS: "; loop(i,0,n) cout<<pos[i]<<" "; cout<<endl;
    loop(i,0,n) if(pos[i]!=m-1) b = 0;
    if (!b) return cout<<"impossible"<<endl,0;
    for(int x:ans) cout<<inds[x]+1<<" "; cout<<endl;
    return 0;
}
/*
color a
cls
g++ h.cpp -o a & a
10
10
0 1 3 6 10 14 17 19 20 21
3
3 1
1 3
3 5



*/