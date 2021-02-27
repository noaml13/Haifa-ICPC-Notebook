/*
ID: licht.n1
PROG: sprime
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


bool isprime(int64_t c){
    for(int i=2;i*i<=c;i++){
        if (c%i==0) return 0;
    }
    return 1;
}

int main() {
    ofstream cout("sprime.out");
    ifstream cin("sprime.in");
    int n; cin>>n;
    vi cur = {2,3,5,7}, next;
    loop(i,1,n){
        for(auto c:cur){
            loop(i,0,10){
                int nex = c*10 + i;
                if (isprime(nex)) next.pb(nex);
            }
        }
        cur = next; next.clear();
    }
    sort(all(cur));
    for(auto c:cur) cout<<c<<endl;
    return 0;
}
/*
color a
cls
g++ test.cpp -o a & a
5 100000000
*/