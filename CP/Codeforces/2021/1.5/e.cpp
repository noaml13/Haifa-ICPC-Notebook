#include <bits/stdc++.h>
//#define int int64_t
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
#define all(x) x.begin(),x.end()
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
using namespace std;
const int INF = 2e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto udist = uniform_int_distribution<int>(0, INF);
int mrand(){
    return udist(rng);
}
struct Node{
    int v, sz, maxi;
    int prio;
    bool inv=0; int prop=0;
    Node *l=0, *r=0;
    Node(int v=0): v(v), sz(1), prio(mrand()){}
    void fix();
    void add(int x){
        prop+=x; v+=x; maxi+=x;
    }
};
int sz(Node *t){
    return (t?t->sz:0);
}
int maxi(Node *t){
    return (t?t->maxi:0);
}
void flip(Node *t){
    if (t) t->inv ^= 1;
}
void add(Node *t, int x){
    if (t) t->add(x);
}
void Node::fix(){
    if (inv) swap(l,r), inv = 0, flip(l), flip(r);
    if (prop) ::add(l, prop), ::add(r, prop), prop = 0;
    maxi = max(v, max(::maxi(l), ::maxi(r))), sz = 1 + ::sz(l) + ::sz(r);
}
void merge(Node *&t, Node *l, Node *r){
    if (!l || !r){
        t = (l?l:r);
        return ;
    }
    if (l->prio>r->prio) t = l, merge(t->r, l->r, r), t->fix();
    else t = r, merge(t->l, l, r->l), t->fix();
}
void splitk(Node *t, Node *&l, Node *&r, int k){
    if (!t) return ;
    if (sz(t->l)>=k) r = t, splitk(t->l, l, r->l, k), r->fix();
    else l = t, splitk(t->r, l->r, r, k - (sz(t->l)+1)), l->fix();
}
struct Treap{
    Node *t=0;
    void insert(int i, int x){
        Node *l, *r;
        splitk(t, l, r, i);
        merge(t, l, new Node(x));
        merge(t, t, r);
    }
    void flip(int a, int b){
        Node *l, *r;
        splitk(t, t, r, b+1);
        splitk(t, l, t, a);
        ::flip(t);
        merge(t, l, t);
        merge(t, t, r);
    }
    void add(int a, int b, int x){
        Node *l, *r;
        splitk(t, t, r, b+1);
        splitk(t, l, t, a);
        ::add(t, x);
        merge(t, l, t);
        merge(t, t, r);
    }
    int query(int a, int b){
        Node *l, *r;
        splitk(t, t, r, b+1);
        splitk(t, l, t, a);
        int v = maxi(t);
        merge(t, l, t);
        merge(t, t, r);
        return v;
    }
    int get(int i){
        return query(i, i);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);

    return 0;
}
/*
color a
cls
g++ ק.cpp -o a & a

*/