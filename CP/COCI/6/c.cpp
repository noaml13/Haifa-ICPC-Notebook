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
    int k; cin>>k;
    cout<<k/2<<endl;
    /*if (k==0){
        cout<<3<<" "<<3<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<3<<endl;
        cout<<1<<" "<<3<<endl;
        return 0;
    }*/
    if (k>=0){
        k++;
        int n = k +2;
        cout<<n<<" "<<(2*k)<<endl;
        loop(i,0,k) cout<<1<<" "<<i+2<<endl;
        loop(i,0,k) cout<<i+2<<" "<<n<<endl;
    }
    else{
        k = 1-k;
        int n = k+4;
        cout<<n<<" "<<3*k+2<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        loop(s,2,4) loop(i,0,k) cout<<s<<" "<<i+4<<endl;
        loop(i,0,k) cout<<i+4<<" "<<n<<endl;
    }
    return 0;
}
/*
color a
cls
g++ c.cpp -std=c++11 -O2 -static -s -lm -o a & a
1


*/


 