#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
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
const int INF=4e18;

int n,m;
vector<string> b;
void stam(vector<vb>& l,int x,int y){
    loop(i,0,n){
        loop(j,0,m) l[i+x][j+y] = l[i+x][j+y]||b[i][j];
    }
}

bool can(int a, int b){
    vector<vb> l(a,vb(b,0));
    loop(i,0,a-n+1){
        loop(j,0,b-m+1){
            stam(l,i,j);
        }
    }
    loop(i,0,l.size()){
        loop(j,0,l[0].size()){
            if (!l[i][j]) return 0;
        }
    }
    return 1;
}

int32_t main(){
    cin>>n>>m;
    loop(i,0,n){
        b.pb("");
        cin>>b[i];
        loop(j,0,m) b[i][j] = (b[i][j]=='X');
    }
    vii s;
    loop(i,0,n){
        loop(j,0,m) s.pb({(i+n)*(j+m),i+n});
    }
    sort(all(s));
    for (auto p: s){
            int a=p.y, b= p.x/p.y;
            if (can(a,b)){
                cout<< a<<" "<<b<<endl;
                return 0;
            }
    }
    return 0;
}

