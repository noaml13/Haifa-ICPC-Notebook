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
struct Seg{
    vi t;
    int sz=1;
    Seg (vb a) {
        for(;a.size()>=sz;sz*=2);
        t.resize(2*sz,0);
        for (int i=sz+a.size()-1;i>0;i--){
            if (i>=sz) t[i]=a[i-sz];
            else t[i]=t[i*2]+t[i*2+1];
        }
    }
    void update(int in,int n){
        t[in+sz]=n;
        for(int i=(in+sz)/2;i;i/=2) t[i]=t[i*2]+t[i*2+1];
    }
    int sum(int l,int r){
        int sum=0;
        for(l+=sz,r+=sz;l<=r;l/=2,r/=2){
            if (l%2) sum+=t[l++];
            if (!r%2) sum+=t[r--];
            if (l>r) break;
        }
        return sum;
    }
    int& operator[](int ind){
        return t[ind+sz];
    }
};
const int MAXL = 1e5 + 5;
int n;
vector<pair<ii,int>> p;
vi check;
void dfs(int i, int p=-1){
    if (check[i]) return ;
    

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    p.resize(n);
    loop(i,0,n) cin>>p[i].x.x>>p[i].x.y, p[i].y = i+1;
    sort(all(p));
    check.resize(n,0);
    loop(i,0,n) dfs(i);
    vb open(MAXL,0);
    SEG sweep(open);
    loop(i,0,n){
        if (i<n-1 && p[i].x.x==p[i+1].x.x){
            if (sweep.sum())
            i++;
        }
        else{
            if(sweep[p[i].x.y]) {
                ans.pb({p[i].y, sweep[p[i].x.y] })
                sweep.update(p[i].x.y,0);
            }
            else sweep.update(p[i].x.y,p[i].y);
        }
    }
    return 0;
}


