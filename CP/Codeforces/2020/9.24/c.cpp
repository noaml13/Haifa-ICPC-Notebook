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

vi sort_cyclic_shifts(string s) {
    int n = s.size();
    const int alphabet = 256;
    //cout<<s<<endl;
    vi p(n), c(n), cnt(max(alphabet, n), 0);
    loop(i,0,n) cnt[s[i]]++;
    loop(i,1,alphabet) cnt[i] += cnt[i-1];
    loop(i,0,n) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vi pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        loop(i,0,n) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        loop(i,0,n) cnt[c[pn[i]]]++;
        loop(i,1,alphabet) cnt[i] += cnt[i-1];
        loop(i,0,n) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        loop(i,1,n) {
            ii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            ii prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vi suffix_array(string s) {
    s += "$";
    vi sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
vi LCP(string& s, vi& p) {
    int n = s.size();
    vi rank(n, 0);
    loop(i,0,n) rank[p[i]] = i;
    int k = 0;
    vi lcp(n-1, 0);
    loop(i,0,n){
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}


int check(string& s){
    int n = s.size();
    vi pref(n+1);
    int cnt = 0, ans = 0; 
    loop(i,0,n) pref[i+1] = pref[i] + (s[i]=='y'?1:-1);
    vi p = suffix_array(s);
    vi lcp = LCP(s, p);
    for(int k = 2; k<n; k+=2){
        vb check(n);
        loop(i,0,n-k+1){
            if (pref[i+k]-pref[i]!=0){ //un bal.
                int j = p[i];
                if (check[j]) continue;
                ans++;
                cout<<"HI: "<<k<<" "<<i<<" "<<j<<endl;
                loop(r,j,n){
                    check[r] = 1;
                    if (r==n-1 || check[r] || lcp[r]<k) break;
                }
                loopr(r,0,j){
                    if (check[r] || lcp[r]<k) break;
                    check[r] = 1;
                }
            }
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    string bests; int best =INF;
    loop(k,1,n){
        string s; 
        int cnt = 0; bool b = 1;
        loop(i,0,n){
            s += (b?'y':'Y');
            if (++cnt==k) b = !b, cnt = 0;
        }
        int val = check(s);
        cout<<s<<endl<<val<<endl;

        if (val < best){
            best = val;
            bests = s;
        }
    }
    cout<<"BEST: "<<best<<endl;
    cout<<bests<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
4
*/