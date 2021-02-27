/*
ID: licht.n1
PROG: zerosum
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
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
int n;
vi op;
set<vi> ans;
void check(){
    int cur=1, res=0, last=1;
    loop(i,0,n-1){
        if (op[i]==0) cur*=10,cur+=(i+2);
        else{
            if (last==1) res+=cur;
            else res-=cur;
            last = op[i], cur = i+2;
        }
    }
    if (last==1) res+=cur;
    else res-=cur;
    if (res==0) ans.insert(op);
}
void dfs(int i){
    if (i<0) return check();
    op[i]=0; dfs(i-1);
    op[i]=1; dfs(i-1);
    op[i]=2; dfs(i-1);
}
int main() {
    ofstream cout("zerosum.out");
    ifstream cin("zerosum.in");
    cin>>n;
    op.resize(n-1);
    dfs(n-2);
    for(auto a:ans){
        loop(i,0,n-1) cout<<i+1<<(a[i]?(a[i]==1?"+":"-"):" ");
        cout<<n<<endl;
    }
    return 0;
}
/*
color a
cls
g++ zerosum.cpp -o a & a
7
*/
