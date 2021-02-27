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
const double eps = 1e-9;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int ts = (250*250)/2;
    double sqr = sqrt(2);
    int x,y; cin>>x>>y;
    bool rev=0;
    if (x==0) swap(x,y), rev=1;
    if (y==0){
        x = 250-x;
        double a = (1.0 * ts * sqr)/(x);
        double ny = a / sqr;
        double nx = 250 - ny;
        nx+=eps; ny+=eps;
        if (rev) swap(nx, ny);
        if (nx>=0 && ny>=0) return cout<<fixed<<setprecision(2)<<nx<<" "<<ny<<endl,0;
        x = 250-x;
        ny = (1.0 * ts)/(x) + eps;
        nx = 0+eps;
        if (rev) swap(nx, ny);
        cout<<fixed<<setprecision(2)<<nx<<" "<<ny<<endl,0;
    }
    else{
        x = 250 - x;
        double a = sqrt(x*x + y*y);
        //cout<<a<<endl;
        double nx = 250 - (1.0 * ts * sqr)/(a) + eps;
        if (nx>=0) return cout<<fixed<<setprecision(2)<<nx<<" "<<double(0)<<endl,0;
        x = 250-x; y=250-y;
        a = sqrt(x*x + y*y);
        double ny = 250 - (1.0 * ts * sqr)/(a) + eps;
        cout<<fixed<<setprecision(2)<<double(0)<<" "<<ny<<endl;
    }
    return 0;
}
/*
color a
cls
g++ BAZEN.cpp -o a & a
0 40
230 20
*/


 

