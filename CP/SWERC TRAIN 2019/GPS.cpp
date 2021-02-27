#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
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
#define PI 3.14159265358979323846
#define R 6371
#define C 299792.458
using namespace std;
const int INF=4e18;


#define X 0
#define Y 1
#define Z 2
struct Point{
    double x=0,y=0,z=0;
    double& get(int ind){
        if (ind==0) return x;
        if (ind==1) return y;
        return z;
    }
    void rotate_plane(double al, int d1, int d2){
        ///example: p.rotate_plane(alpha, X, Y) for alpha Radian rotation in XY plane
        double &a= get(d1);
        double &b= get(d2);
        double tmp = a*cos(al) - b*sin(al);
        b = b*cos(al) + a*sin(al);
        a = tmp;
    }
    void print(){
        cout<<"POINT: "<<x<<" "<<y<<" "<<z<<endl;
    }
    double dis(Point& p){
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));
    }
};

Point o;
void fix(double& a){
    a *=  PI /180;
}

void calc(Point&p, Point& q){
    double dis = p.dis(q);
    double r = o.dis(q);
    //cout<<"DIST: "<<r<<" "<<R<<" "<<dis<<endl;
    if (r*r>=dis*dis+R*R){
        cout<<dis/C<<endl;
    }
    else{
        cout<<"no signal"<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int s; cin>>s;
    Point p; p.x = R;
    double lo, la; cin>>lo>>la;
    fix(lo); fix(la);
    p.rotate_plane(la,0,2);
    p.rotate_plane(lo,0,1);
    //cout<<abs(R-o.dis(p))<<endl;
    //p.print();
    loop(i,0,s){
        cin >> lo >> la; fix(lo); fix(la);
        double r, x; cin>>r>>x;
        x *= 2*PI;
        Point q; q.x = r;
        q.rotate_plane(x, 0,1);
        q.rotate_plane(la, 1,2);
        q.rotate_plane(lo, 0,1);
        //q.print();
        //cout<<abs(r-o.dis(q))<<endl;
        calc(p, q);
    }
    return 0;
}
/*
3
45.0 45.0
0.0 45.0 7500.0 0.125
0.0 60.0 7000.0 0.3
-50.0 5.0 25000.0 0.3
*/


