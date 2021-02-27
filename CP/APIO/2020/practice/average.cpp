#include <bits/stdc++.h>
#include "average.h"
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;

ii operator+(const ii& a, const ii& b){
    return {a.x+b.x, a.y+b.y};
}
ii operator-(const ii& a, const ii& b){
    return {a.x-b.x, a.y-b.y};
}
__int128_t cross(const ii& a, const ii& b){
    return __int128_t(a.x) * b.y - __int128_t(b.x) * a.y;
}
bool right(const ii& a, const ii& b, const ii& c){
    return cross(b-a, c-b) <= 0;
}

ii cur = {0,0};
double slope(const ii& a){
    return double(a.y - cur.y) / (a.x - cur.x);
}
void inserthull(vii& h, ii& x){
    while(h.size()>1 && !right(x, h.back(), h[h.size()-2])) {
        //cout<<hull.back().x<<" "<<hull.back().y<<endl;
        h.pop_back();
    }
    h.push_back(x);
}
double queryhull(vii& hull){
    int l = 0, r = hull.size(), mid;
    double best = 0;
    while(l<r-1){
        int mid = (l+r)/2;
        double s1 = slope(hull[mid-1]), s2=slope(hull[mid]);
        chkmax(best, s1); chkmax(best, s2);
        if (s1 > s2) r = mid-1;
        else l = mid+1;
    }
    if (l!=r){
        chkmax(best, slope(hull[l]));
    }
    return best;
}

int sz;
vvii hulls;
vb fin;


void init() {
    int n = 2e5;
    for(sz=1;sz<n;sz*=2);
    hulls.resize(2*sz);
    fin.resize(2*sz,0);
}
int ind = 0;
void addMonth(int32_t k) {
    int i = sz + (ind++);
    fin[i] = 1;
    hulls[i].pb(cur);
    cur = cur - ii(1,int(k));
    for(i/=2;i;i/=2){
        if (fin[i]) continue;
        if (!fin[2*i+1]) break;
        hulls[i] = hulls[2*i];
        for(auto x:hulls[2*i+1]){
            inserthull(hulls[i], x);
        }
        fin[i] = 1;
    }
}

double maximumAverage(int32_t l, int32_t r) {
    double best = 0;
    for(l+=sz, r+=sz; l<=r; l/=2,r/=2){
        if (l%2) chkmax(best, queryhull(hulls[l++]));
        if (r%2==0) chkmax(best, queryhull(hulls[r--]));
    }
    return best;
}
/*int32_t main(){
    cout<< right({0,0},{1,0},{1,1}) << endl;
}*/
/*
color a
cls
g++ -std=c++11 -o "average" "grader.cpp" "average.cpp" -O2 -lm & average.exe


g++ -std=c++11 -o a average.cpp -O2 -lm
*/