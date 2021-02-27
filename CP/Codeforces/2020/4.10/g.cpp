#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;

struct com {
    double a, b;
    com(double a = 0, double b = 0) : a(a), b(b){}
};
com inline operator + (com l, com r) { return com(l.a + r.a, l.b + r.b); }
com inline operator - (com l, com r) { return com(l.a - r.a, l.b - r.b); }
com inline operator * (com l, com r) { return com(l.a * r.a - l.b * r.b, l.b * r.a + l.a * r.b); }
com inline operator / (com c, double b) { return com(c.a / b, c.b / b); }
void inline dft(vector<com> &a, int len, const vi &rev, int tp = 1) {
    const double pi = acos(-1);
    for(int i=0;i<= len ;i++)
        if (rev[i] > i) swap(a[i], a[rev[i]]);
    for (int k = 1; k < len; k <<= 1) {
        com w0(cos(2 * pi / (k << 1)), tp * sin(2 * pi / (k << 1)));
        for (int l = 0; l < len; l += (k << 1)) {
            com w(1);
            for (int i = 0; i < k; ++i, w = w * w0) {
                com p0 = a[l + i], p1 = w * a[l + k + i];
                a[l + i] = p0 + p1, a[l + k + i] = p0 - p1;
            }
        }
    }
}
const double eps = 1e-7;
vi conv(const vi &a,const vi & b){
    int n = a.size(), m = b.size();
    vector<com> p(n), q(m);
    loop(i,0,n) p[i].a = a[i];
    loop(i,0,m) q[i].a = b[m-i-1];
    int len, k = 0;
    for (len = 1; len <= p.size() + q.size(); len <<= 1, ++k);
    vector<com> res(len*2, 0);
    p.resize(2*len, 0); q.resize(2*len, 0);
    vi rev(len+1, 0);
    for(int i=0;i <= len;i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    dft(p, len, rev), dft(q,len, rev);
    for(int i=0;i <= len;i++) res[i] = p[i] * q[i];
    dft(res, len, rev, -1);
    vi ans(n-m+1);
    loop(i,0,n-m+1) ans[i] = llround(res[i+m-1].a / len);
    /*vi ans(n-m+1);
    loop(i,0,n-m+1){
        loop(j,0,m) ans[i]+=a[i+j]*b[j];
    }*/
    return ans;
}
vi nconv(const vi &a,const vi & b){
    int n = a.size(), m = b.size();
    vi ans(n-m+1);
    loop(i,0,n-m+1){
        loop(j,0,m) ans[i]+=a[i+j]*b[j];
    }
    return ans;
}
const int AZ = 'z'-'a'+1;
string s,t;
int p[AZ];
int n,m;
int brute(int i){
    int v = 0;
    loop(j,0,m) v+=(s[i+j]-t[j])*(s[i+j]-t[j]) * (p[s[i+j]]-t[j])*(p[s[i+j]]-t[j]);
    return v;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    loop(i,0,AZ) cin>>p[i], p[i]--;
    cin>>s>>t;
    for(char& c:s) c-='a'; for(char& c:t) c-='a';
    n = s.size(), m = t.size();
    vi a1(n),b1(m);
    vi a2(n),b2(m);
    vi a3(n),b3(m);
    vi prefs(n+1,0), preft(m+1,0);
    loop(i,0,n){
        int a = s[i], b = p[s[i]];
        a1[i] = a*a*b + b*b*a;
        a2[i] = a*a + b*b + 4*a*b;
        a3[i] = a + b;
        prefs[i+1] = prefs[i] + a*a*b*b;
    }
    loop(i,0,m){
        int x = t[i];
        b1[i] = -2*x; b2[i] = x*x; b3[i] = -2*x*x*x;
        preft[i+1] = preft[i] + x*x*x*x;
    }
    vi m1 = conv(b1,a1), m2 = conv(b2,a2), m3 = conv(b3,a3);
    /*vi nm1 = nconv(a1,b1);
    loop(i,0,n-m+1) cout<<m1[i]<<" "<<nm1[i]<<endl;*/
    loop(i,0,m-n+1){
        int v = preft[i+n] - preft[i] + prefs[n];
        //cout<<"PREF: "<<m1[i]<<endl;
        v += m1[i] + m2[i] + m3[i];
        //cout<<"V: "<<v<<" "<<brute(i)<<endl;
        //if (v<0) cout<<"FUCK"<<endl;
        cout<<(v?0:1);
    }
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
2 3 1 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
abc
abcaaba
*/ 