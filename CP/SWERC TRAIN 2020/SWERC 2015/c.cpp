#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const double eps = 1e-6;

double X = 0;
bool ok(double T, vector<int> x, vector<int> v){
    int x;
    int n = x.size();
    double maxL = -INF;
    double minR = INF;
    long long x = (long long)(a) * b;
    for(int i=0; i<n; i++){
        double li = x[i] - v[i] * T;
        double ri = x[i] + v[i] * T;
        maxL = max(maxL, li);
        minR = min(minR, ri);
        if (maxL>minR) break;
    }
    if (maxL<=minR) X = maxL; // X <- [maxL, minR]
    return maxL <= minR; // [maxL, minR]
}


int main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vector<int> a(n);
    vector<vector<int>> inds(k+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        inds[a[i]].push_back(i);
    }
    // calc prev
    for(int m=1;m<=k;m++){
        for(int i:inds[m]){
            // calc dp[i] = dp[prev[i]]

        }
    }



    int n; cin >> n;
    vector<int> x(n), v(n);
    for(int i=0;i<n;i++) cin >> x[i] >> v[i];
    double l = 0, r = INF, T;
    while(r-l>eps){
        T = (l+r)/2;
        if (ok(T, x, v)) {
            r = T;
        }
        else {
            l = T;
        }
    }
    cout << l << " " << X << endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a


*/