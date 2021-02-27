#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long double D;
const int INF = 1e9;
const D eps = 1e-6;
vi getv(){
    vi v(3);
    loop(i,0,3) cin>>v[i];
    int g = v[0];
    loop(i,1,3) g = __gcd(g, v[i]);
    loop(i,0,3) v[i]/=g;
    return v;
}
#define vd vector<D>
#define vvd vector<vd>
void inv(vvd& a){
    int n = a.size();
    vvd eye(n, vd(n));
    loop(i,0,n) eye[i][i]=1;
    loop(i,0,n){
        int me = a[i][i];
        loop(j,0,n) {
            a[i][j]/=me;
            eye[i][j]/=me;
        }
        loop(k,0,n){
            if (k==i) continue;
            D r = a[k][i];
            loop(j,0,n) a[k][j]-=r*a[i][j], eye[k][j]-=r*eye[i][j];
        }
    }
    a = eye;
}
vd liner(vvi& a, vi&b){
    int n = a.size();
    vvd mat(n, vd(n));
    loop(i,0,n)loop(j,0,n) mat[i][j]=a[i][j];
    inv(mat);
    //loop(i,0,n) {loop(j,0,n) cout<<mat[i][j]<<" "; cout<<endl;}
    vd ans(n,0);
    loop(i,0,n) loop(j,0,n) ans[i]+=mat[i][j]*b[j];
    return ans;
}
vi cof;
map<int, vi> ing;
bool can2(vi a, vi b){
    if (a==b) return 0;
    vvi mat(2, vi(2));
    loop(i,0,2) mat[i][0]=a[i], mat[i][1]=b[i];
    vd res = liner(mat, cof);
    loop(i,0,2) cout<<res[i]<<endl;
    //loop(i,0,2) if(res[i]+eps<0) return 0;
    D x = a[2]*res[0] + b[2]*res[1];
    cout<<"HI "<<x<<endl;
    return (x-cof[2])<=eps;
}
bool can3(vi a, vi b, vi c){
    if (a==b || a==c || b==c) return 0;
    vvi mat(3, vi(3));
    loop(i,0,3) mat[i][0]=a[i], mat[i][1]=b[i], mat[i][2]=c[i];
    vd res = liner(mat, cof);
    loop(i,0,3) if(res[i]+eps<0) return 0;
    return 1;
}
int solve(){
    vvi a;
    for(auto v:ing) {
        if (v.y==cof) return 1;
        a.pb(v.y);
    }
    int r = a.size();
    loop(i,0,r){
        loop(j,i+1,r){
            if (can2(a[i], a[j])) return 2;
        }
    }
    loop(i,0,r){
        loop(j,i+1,r){
            loop(k,j+1,r)
                if (can3(a[i], a[j], a[k])) return 3;
        }
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cof = getv();
    int n; cin>>n;
    
    int ind=0;
    loop(i,0,n){
        char op; cin>>op;
        if (op=='A'){
            ing[ind++] = getv();
        }
        else{
            int j; cin>>j;
            ing.erase(j);
        }
        cout<<solve()<<endl;
    }
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
1 2 3
6
A 5 6 7
A 3 10 17
R 1
A 15 18 21
A 5 10 15
R 3

*/