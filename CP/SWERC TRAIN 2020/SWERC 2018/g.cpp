#include <bits/stdc++.h>
// #define int int64_t
#define ii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const ll INF = 2e18, MOD = 1e9 + 7;

void add(int &a, int b){ a = (a+b)%MOD;}
// void add(ll &a, ll b){ a = (a+b)%MOD;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto unidist = uniform_int_distribution<ll>(0, INF);
inline ll mrand(ll sz){ return uniform_int_distribution<ll>(0, sz)(rng);}
struct Node{
    char v=0;
    ll sz = 1;
    int l=0, r=0, sum=0;
};
const int MAXN = 4e6;
Node *nodes;
inline prio(int t){
    return mrand(nodes[t].sz);
}
inline ll sz(int t){
    return (t?nodes[t].sz:0);
}
void fix(int t){
    if (!t) return ;
    nodes[t].sz = 1 + sz(nodes[t].l) + sz(nodes[t].r);
    nodes[t].sum = nodes[t].v;
    add(nodes[t].sum, nodes[nodes[t].l].sum);
    add(nodes[t].sum, nodes[nodes[t].r].sum);
}
int cnt = 1;
int copy(int t){
    int c = cnt++;
    nodes[c] = nodes[t];
    return c;
}
int merge(int l, int r){
    if (!l || !r){
        return (l?l:r);
    }
    int v;
    if (prio(l) > prio(r)){
        v = copy(l);
        nodes[v].r = merge(nodes[l].r, r);
    }
    else{
        v = copy(r);
        nodes[v].l = merge(l, nodes[r].l);
    }
    fix(v);
    return v;
}
/*
void split(Node *t, Node *&l, Node *&r, ll k){
    if (!t){
        l = r = t;
        return ;
    }
    //cout<<"K: "<<k<<endl;
    if (sz(t->l)>=k){
        r = copy(t);
        split(t->l, l, r->l, k);
        r->fix();
    }
    else{
        l = copy(t);
        split(t->r, l->r, r, k - sz(t->l) - 1);
        l->fix();
    }
}*/
int splitLR(int t, ll l, ll r){ // [l,r)
    if (!t) return t;
    if (l==0 && r ==sz(t)){
        return t;
    }
    ll s = sz(nodes[t].l)+1;
    if (l<s && s<=r){
        int v = copy(t);
        nodes[v].l = splitLR(nodes[t].l, l, s-1);
        nodes[v].r = splitLR(nodes[t].r, 0, r-s);
        fix(v);
        return v;
    }
    if (l >= s) return splitLR(nodes[t].r, l - s, r-s);
    else return splitLR(nodes[t].l, l, r);
}  
/*void __print(Node *t){
    if (!t) return ;
    //cout<<"(";
    __print(t->l);
    cout<<char(t->v);
    __print(t->r);
    //cout<<")";
}
void print(Node *t){
    __print(t);
    cout<<endl;
}*/
int newNode(char c){
    int v = cnt++;
    nodes[v].v = nodes[v].sum = c;
    return v;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    nodes = new Node[MAXN];
    nodes[0].sz = 0;
    int n; cin>>n;
    vi strs(n, 0);
    string s; cin>>s;
    for(char c:s) strs[0] = merge(strs[0], newNode(c));
    //print(nodes[0]);
    loop(i,1,n){
        string op; cin>>op;
        if (op=="SUB"){
            ll x,l,r; cin>>x>>l>>r;
            strs[i] = splitLR(strs[x], l, r);
            //split(nodes[x], nodes[i], t, r);
            //if (l) split(nodes[i], t, nodes[i], l);
        }
        else{
            int x,y; cin>>x>>y;
            strs[i] = merge(strs[x], strs[y]);
        }
        // print(nodes[i]);
    }
    /*loop(i,1,cnt) {
        res[i] = nodes[i].v;
        add(res[i], res[nodes[i].l]);
        add(res[i], res[nodes[i].r]);
    }*/
    // cout<<cnt<<endl;
    cout<<nodes[strs[n-1]].sum<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
3
foobar
SUB 0 0 3
APP 1 1


*/