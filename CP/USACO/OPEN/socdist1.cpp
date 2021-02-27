/*
ID: licht.n1
PROG: socdist1
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define int int64_t
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


int32_t main() {
    ofstream cout("socdist1.out");
    ifstream cin("socdist1.in");
    int n; cin>>n;
    string s; cin>>s;
    n = s.size();
    int fir=0, sec=0, cur=-INF;
    int pre=0, suf=0;
    for(int i=0;i<n && s[i]=='0';i++) pre++;
    for(int i=n-1;i>=0 && s[i]=='0';i--) suf++;
    int minD =  INF;
    loop(i,0,n){
        if (s[i]=='1'){
            if (cur>=0) chkmin(minD,cur+1);
            if (cur>fir) swap(fir, cur);
            if (cur>sec) swap(sec, cur);
            cur=0;
        }
        else cur++;
    }
    if (pre==n){
        return cout<<n-1<<endl,0;
    }
    int ans1 = (fir+1)/3;
    int anspref = pre/2, anssuf = suf/2;
    vi vec = {pre, suf, (fir+1)/2, (sec+1)/2};
    sort(all(vec));
    int ansdist = vec[2];
    int ans = max(max(anspref, anssuf ),max(ans1,ansdist));
    chkmin(ans, minD);
    cout<<ans<<endl;
    /*cout<<pre<<" "<<suf<<endl;
    cout<<fir<<" "<<sec<<endl;*/
    return 0;
}
/*
color a
cls
g++ socdist1.cpp -o a & a
14
10001001000010

0
10000
*/
