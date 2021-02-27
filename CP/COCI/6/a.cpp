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

void printnum(int x, int len){
    vi num;
    while(x) num.pb(x%10),x/=10;
    reverse(all(num));
    loop(i,num.size(),len) cout<<0;
    for(auto d:num) cout<<d;
}
struct Date{
    int d, m, y;
    Date(int _d=0, int _m=0, int _y=0){
        d = _d; m =_m; y = _y;
    }
    bool operator<(const Date& o){
        if (y==o.y){
            if (m==o.m) d<o.d;
            return m<o.m;
        }
        return y<o.y;
    }
    void print(){
        printnum(d,2);
        cout<<".";
        printnum(m,2);
        cout<<".";
        printnum(y,4);
        cout<<"."<<endl;
    }
};
bool comp(const Date& a, const Date& o){
    if (a.y==o.y){
        if (a.m==o.m) a.d<o.d;
        return a.m<o.m;
    }
    return a.y<o.y;
}
int geti(string& s, int i){
    return s[i]-'0';
}
int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool legal(int d, int m, int y){
    if (m==2 && y%4==0) return d<=29;
    return d<=days[m];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<Date> pal;
    loop(d,1,32){
        loop(m,1,13){
            int y = (d/10) + (d%10)*10 + (m/10)*100 + (m%10)*1000;
            if (legal(d,m,y)) pal.pb(Date(d,m,y));
        }
    }
    sort(all(pal));
    vector<Date> d(n);
    loop(i,0,n){
        string s; cin>>s;
        d[i].d = geti(s,0)*10 + geti(s,1);
        d[i].m = geti(s,3)*10 + geti(s,4);
        d[i].y = geti(s,6)*1000 + geti(s,7)*100  + geti(s,8)*10  + geti(s,9);
        auto next = upper_bound(all(pal), d[i], comp);
        next->print();
    }

    return 0;
}
/*
color a
cls
g++ a.cpp -std=c++11 -O2 -static -s -lm -o a & a
1
02.02.2020.

*/


 