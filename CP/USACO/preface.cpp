/*
ID: licht.n1
PROG: preface
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9;

vi vals;
vi times;
vector<map<int,int>> rep;

void add(map<int,int>& a, const map<int,int>& b){
    for(auto p:b) a[p.x]+=p.y;
}
map<int,int> findrep(int x){
    map<int,int> ans;
    for(int i = vals.size()-1;i>=0;--i){
        int cnt = 0;
        while(x>=vals[i] && cnt<times[i]){
            cnt++;
            x-=vals[i];
        }
        loop(j,0,cnt) add(ans,rep[i]);
    }
    if (x!=0) cout<<"FUCK"<<endl;
    return ans;
}
int main() {
    ofstream cout("preface.out");
    ifstream cin("preface.in");
    int n; cin>>n;
    vector<char> simb ={'I','V','X','L','C','D','M'};
    vi tens = {1,10,100,1000};
    vi fives = {5,50,500};
    loop(i,0,tens.size()){
        vals.pb(tens[i]);
        rep.pb({{i*2,1}});
        times.pb(3);
        if (i<tens.size()-1) {
            vals.pb(fives[i]-tens[i]);
            rep.pb({{i*2+1,1}, {i*2,1}});
            times.pb(1);

            vals.pb(fives[i]);
            rep.pb({{i*2+1,1}});
            times.pb(1);

            vals.pb(tens[i+1]-tens[i]);
            rep.pb({{i*2+2,1}, {i*2,1}});
            times.pb(1);
        }
    }
    //loop(i,0,vals.size()) cout<<vals[i]<<" "; cout<<endl;
    map<int, int> ans;
    loop(i,1,n+1){
        map<int,int> cur = findrep(i);
        add(ans,cur);
    }
    for(auto p:ans) cout<<simb[p.x]<<" "<<p.y<<endl;
    return 0;
}
/*
color a
cls
g++ frac1.cpp -o a & a
2 7 7 
*/
