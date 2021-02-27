/*
ID: licht.n1
PROG: prefix
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
const int INF = 1e9;

int sz=1;
vb e(1,0);
vector<map<char,int>> trie(1);
void add(string& s){
    int cur=0;
    for(auto c:s){
        if (!trie[cur][c]){
            trie[cur][c] = sz++;
            e.resize(sz,0); trie.resize(sz);
        }
        cur = trie[cur][c];
    }
    e[cur] = 1;
}
int next(int cur, char c){
    if (!trie[cur][c]) return -1;
    return trie[cur][c];
}
int main() {
    ofstream cout("prefix.out");
    ifstream cin("prefix.in");
    string s,t;
    while(true){
        cin>>s;
        if (s==".") break;
        add(s);
    }
    s = "";
    while(true){
        if (!getline(cin,t)) break;
        s+=t;
    }
    int n = s.size();
    vb can(n+1,0);
    can[0] = 1;
    int ans=0;
    loop(i,0,n+1){
        if (!can[i]) continue;
        ans=i;
        int cur = 0;
        for(int cnt=0;i+cnt<n && cur!=-1;cnt++){
            cur = next(cur,s[i+cnt]);
            if (cur!=-1 && e[cur]) can[i+cnt+1]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
AH AS AZ BW CD CK CN CU CZ DB DH EC ED EN FJ GA GK GM GS GT 
HA HN HZ IN IR JB JD JM JZ KG KI LO LQ LU LW LY MJ MT MV ND 
NM NS OB OI OK OM PG PO PQ PZ QE QP RG RK RN RP RQ RR RS RU 
SA SF SJ SN TK TR TU TY UA UO US UW UX VH VL VO WF WH WL WS 
WZ XU XW XY YA YI YN YT ZF ZH ZJ ZL ZR ZX 
. 
ASCDCKCUEDFJGKGMHAIRJMKILQLWLYMJMTMVNSOIOKOMPOPQQPRGRNRPSJTUTYWSWZXWYIYTAHAZBWCDCNCUDHECENGAGMGSGTHAHNKGLQLULWNMOBOIOKOMPGPOPQPZRGRKRNRPRRSATRTUUWVLVOWFWLWSXUXYYAYIYNYTZFZJZRZXBWCKCUFJGAGSHAHNIRJBJMKILQLUNDNMNSOKOMPQQERGRQRRRSSASFSJSNTUTYUAUOUWVLWHXUXWXYYAYTZFZJZLZRZXASBWCDCNDBECEDFJGSHAHNHZINJMKGKILQMJNMNSOKOMPQQPRRRSSFSJSNTRTUTYUAUWUXVLVOWLWSWZXYYNYTZFZHZRZXAHASAZCDCKCNDBECENGMGSHAHZIRJDKGKILOLYOBOKPGPQQPRRSNTRTYUOUSUXVHVLVOWFWLWSXYYNZJZXZZAHAZBWCDCKCNDB 

*/
