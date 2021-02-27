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
const int INF = 4e18, MOD = 1e9 + 7;

const int MAX = 1e5 + 10;
map<ii, int> mem;
vii comps;
int cnt = MAX;
vi getSt(){
    vi st(MAX);
    loop(i,0,MAX) st[i] = i;
    return st;
}
bool solve(string &s, vi& st){
    for(auto op:s){
        //cout<<"OP: "<<op<<endl;
        switch (op)
        {
        case 'C':
            st.pb(st.back());
            break;
        case 'D':
            st.pop_back();
            break;
        case 'P':
        {
            ii p = {st.back(), st[st.size()-2]};
            st.pop_back();
            if (mem.find(p)==mem.end()) mem[p] = cnt++, comps.pb(p);
            st.back() = mem[p];
            break;
        }
        case 'U':
        {
            if (st.back()<MAX) return 1;
            ii p = comps[st.back()];
            st.back() = p.y;
            st.pb(p.x);
            break;
        }
        case 'L':
            // cout<<"S: "<<st.back()<<" "<<MAX<<endl;
            if (st.back()<MAX) return 1;
            st.back() = comps[st.back()].x;
            break;
        case 'R':
            if (st.back()<MAX) return 1;
            st.back() = comps[st.back()].y;
            break;
        case 'S':
            swap(st.back(), st[st.size()-2]);
            break;
        }
        /*cout<<"ST: ";
        loop(x,1,10) cout<<st[st.size()-x]<<" ";
        cout<<endl;*/
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    comps.resize(MAX);
    string a,b; cin>>a>>b;
    vi ans1  = getSt(), ans2 = getSt();
    bool v1 = solve(a, ans1), v2 = solve(b, ans2);
    //cout<<"V: "<<v1<<" "<<v2<<endl;
    if (v1 || v2){
        if (v1 && v2) cout<<"True"<<endl;
        else cout<<"False"<<endl;
        return 0;
    }
    if (ans1.size()!=ans2.size()) return cout<<"False"<<endl,0;
    // cout<<ans1.size()<<endl;
    loop(i,0,ans1.size()) {
        //cout<<ans1[i]<<" "<<ans2[i]<<endl;
        if(ans1[i]!=ans2[i]) return cout<<"False"<<endl,0;
    }
    cout<<"True"<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
PSPCRSL
PS



*/