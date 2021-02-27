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
int32_t main(){
    ios_base::sync_with_stdio(false);
    char op;
    string a,b; 
    cin>>a>>op>>b;
    if (op=='+'){
        if (a.size()==b.size()){
            cout<<2;
            loop(i,1,a.size()) cout<<0;
            cout<<endl;
        }
        else{
            if (a.size()>b.size()) swap(a,b);
            cout<<1;
            loop(i,1,b.size()-a.size()) cout<<0;
            cout<<1;
            loop(i,1,a.size()) cout<<0;
            cout<<endl;
        }
    }
    else{
        cout<<1;
        loop(i,0,a.size()+b.size()-2) cout<<0;
        cout<<endl;
    }
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
1000
*
100

*/


 