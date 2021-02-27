#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

int n;
vi inv(const vi& a){
    vi v(n);
    loop(i,0,n) v[a[i]] = i;
    return v;
}
vvi tran(const vvi& a){
    vvi b(n, vi(n));
    loop(i,0,n) loop(j,0,n) b[i][j] = a[j][i];
    return b;
}
vi shift(const vi& a, int x){
    vi v(n); 
    loop(i,0,n) v[(i+x)%n] = a[i];
    return v;
}
int solve(){
    int m; cin>>n>>m;
    vvi mat(n, vi(n));
    loop(i,0,n) loop(j,0,n) cin>>mat[i][j], mat[i][j]--;
    int a=0,b=0,c=0,d=0,p=0,t=0;
    string s; cin>>s;
    loop(i,0,m){
        switch(s[i]){
            case 'R':
                a = (a+1)%n;
                break;
            case 'L':
                a = (a+n-1)%n;
                break;
            case 'D':
                b = (b+1)%n;
                break;
            case 'U':
                b = (b+n-1)%n;
                break;
            case 'C':
                swap(a,b);
                swap(c,d);
                t^=1;
                a = (n-a)%n, c = (n-c)%n;
                b = (n-b)%n, d = (n-d)%n;
                
            case 'I':
                swap(a,c);
                swap(b,d);
                p^=1;
                b = (n-b)%n, d = (n-d)%n;
                a = (n-a)%n, c = (n-c)%n;
                break;
        }
    }
    //cout<<"HI: "<<endl;
    if (p){
        loop(i,0,n) mat[i] = inv(mat[i]);
    }
    if (t){
        mat = tran(mat);
        loop(i,0,n) mat[i] = inv(mat[i]);
        mat = tran(mat);
    }
    //cout<<"ABCD: "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    loop(i,0,n) mat[i] = shift(mat[i], a);
    loop(i,0,n) mat[i] = inv(mat[i]);
    loop(i,0,n) mat[i] = shift(mat[i], c);
    loop(i,0,n) mat[i] = inv(mat[i]);

    mat = tran(mat);
    loop(i,0,n) mat[i] = shift(mat[i], b);
    loop(i,0,n) mat[i] = inv(mat[i]);
    loop(i,0,n) mat[i] = shift(mat[i], d);
    loop(i,0,n) mat[i] = inv(mat[i]);
    mat = tran(mat);

    loop(i,0,n) {loop(j,0,n) cout<<mat[i][j]+1<<" "; cout<<endl;}
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
1
3 1
1 2 3
2 3 1
3 1 2
C



5
3 2
1 2 3
2 3 1
3 1 2
DR
3 2
1 2 3
2 3 1
3 1 2
LU
3 1
1 2 3
2 3 1
3 1 2
I
3 1
1 2 3
2 3 1
3 1 2
C
3 16
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI


*/