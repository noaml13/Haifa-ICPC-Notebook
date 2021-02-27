#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
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

int check(vector<vb>& rows){

}


int32_t main(){
    cin>>n>>m;
    loop(i,0,n){
        b.pb("");
        cin>>b[i];
        loop(j,0,m) b[i][j] = (b[i][j]=='X');
    }
    vector<vb> rows(n,vi(m));
    loop(i,0,n){
        loop(j,0,m) rows[i][j]==b[i][j];
    }
    int m=INF;
    ii v= {INF,INF};
    loop(k,0,m){ //O(N^3)
        int h = check(rows);  //O(N^2)
        if (h*(k+m)<m){
            m= h*(k+m);
            v = {h, k+m};
        }
        loop(i,0,n) { //O(N^2)
            rows[i].pb(0);
            loop(i,0,rows[0].size()-1){
                rows[i][j]|=rows[i][j-1];
            }
        }
    }
    cout<< v.x<<" "<<v.y<<endl;
    return 0;
}

