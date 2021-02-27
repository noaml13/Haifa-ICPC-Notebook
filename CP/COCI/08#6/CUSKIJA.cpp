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
const int INF = 1e18;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n; 
    vvi x(3,vi(0));
    loop(i,0,n){
        int a; cin>>a;
        x[a%3].pb(a);
    }
    int sz=x[0].size();
    if ( sz*2-1>n ) return cout<<"impossible"<<endl,0;
    if (sz==0){
        if (x[1].size() && x[2].size()) return cout<<"impossible"<<endl,0;
        if (x[2].size()) swap(x[1],x[2]);
        loop(i,0,n) cout<<x[1][i]<<" ";
        cout<<endl;
        return 0;
    }
    int cnt = sz-1;
    int ind=0;
    for(;ind<n;ind++){
        if (ind%2){
            if (x[1].size()==0) {cout<<x[2].back()<<" ";  x[2].pop_back();}
            else {cout<<x[1].back()<<" ";  x[1].pop_back();}
        }
        else{
            if (!cnt) break;
            cout<<x[0].back()<<" "; x[0].pop_back();
            cnt--;
        }
    }
    for(auto a:x[1]) cout<<a<<" ";
    cout<<x[0][0]<<" ";
    for(auto a:x[2]) cout<<a<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ CUSKIJA.cpp -o a & a
3
1 2 3
*/


 


