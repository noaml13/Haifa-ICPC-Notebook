/*
ID: licht.n1
PROG: runround
LANG: C++14          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
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
const int INF = 1e9, MAXS=800;

bool tryincrease(vi& p, int i, vb& taken, int sz){
    int prev = p[i]; p[i]+=sz;
    while(p[i]<10 && taken[p[i]]) p[i]+=sz;
    if (p[i]<10) return 1;
    p[i] = prev;
    return 0;
}
int32_t main() {
    ofstream cout("runround.out");
    ifstream cin("runround.in");
    int n; cin>>n;
    vi num;
    while(n) num.pb(n%10),n/=10;
    reverse(all(num));
    n = num.size();
    loop(sz,n,n+3){
        vi per(sz), best(sz,INF);
        loop(i,0,sz) per[i]=i;
        do{
            int cur = per[0], cnt=1;
            while(cur!=0) cur=per[cur], cnt++;
            if (cnt==sz){
                vi newp(per);
                loop(i,0,sz) newp[i] = (newp[i] - i + sz)%sz;
                //loop(i,0,sz) cout<<newp[i]<<" "; cout<<endl;
                vb taken(10,0);
                bool pos=true, larger=(n<sz);
                loop(i,0,sz){
                    while(newp[i]<10 && (taken[newp[i]] || (!larger && newp[i]<num[i]) || newp[i]==0)) newp[i]+=sz;
                    if (newp[i]<10) {
                        taken[newp[i]]=1;
                        if (!larger && newp[i]>num[i]) larger = 1;
                    }
                    else {
                        pos=false; break;
                    }
                }
                //if (per==vi({1,4,0,5,3,2})) {loop(i,0,sz) cout<<newp[i]<<" "; cout<<endl;}
                if (pos) {
                    if (newp==num){
                        for(int i=sz-1;i>=0;--i){
                            if (tryincrease(newp, i, taken, sz)) break;
                        }
                    }
                    if (newp!=num) best = min(best, newp);
                }
            }
        }while(next_permutation(all(per)));
        if (best[0]!=INF){
            loop(i,0,sz) cout<<best[i];
            cout<<endl;
            break;
        }
    }
    //cout<<"bi"<<endl;
    return 0;
}
/*
color a
cls
g++ frac1.cpp -o a & a
134259
*/
