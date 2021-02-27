/*
ID: licht.n1
PROG: pprime
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
const int INF = 1e9, MAXM = 2*250*250 + 5;

int a,b;
bool isprime(int64_t c){
    for(int i=2;i*i<=c;i++){
        if (c%i==0) return 0;
    }
    return 1;
}
vi num;
vi ans;
void check(int64_t cur){
    if (cur>=a && cur<=b && isprime(cur)){
        ans.pb(cur);
    }
}
void dfs(int sz, int first=1){
    if (sz==0){
        int64_t cur = 0, cur2;
        int n = num.size();
        loop(i,0,n) cur*=10, cur+=num[i];
        cur2=cur;
        loop(i,0,n) cur*=10, cur+=num[n-i-1];
        loop(i,1,n) cur2*=10, cur2+=num[n-i-1];
        check(cur);
        check(cur2);
    }
    else{
        loop(i,first,10){
            num.pb(i);
            dfs(sz-1,0);
            num.pop_back();
        }
    }
}
int main() {
    ofstream cout("pprime.out");
    ifstream cin("pprime.in");
    cin>>a>>b;
    loop(i,1,6) dfs(i);
    sort(all(ans));
    for(auto c:ans) cout<<c<<endl;
    return 0;
}
/*
color a
cls
g++ test.cpp -o a & a
5 100000000
*/