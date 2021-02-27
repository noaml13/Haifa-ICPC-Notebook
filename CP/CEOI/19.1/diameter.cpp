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
const int INF = 1e18;
struct Node{ //SEGMENT TREE
    int lr,rr,mid;
    int val=0;
    int prop=0; bool resp=0;
    Node *l=NULL,*r=NULL;
    Node(int _l, int _r): lr(_l), rr(_r), mid((_l+_r)/2){}
    void fix(){
        if (!l) l = new Node(lr, mid);
        if (!r) r = new Node(mid, rr);
        if (resp){
            l->resp = r->resp = 1; resp=0;
            l->prop += prop;
            r->prop += prop; 
            l->val += prop;
            r->val += prop;
            prop = 0;
        }
        val = max(l->val, r->val);
    }
    void update(int a, int b, int dx){
        if (a>=rr || b<=lr) return;
        if (a<=lr && rr<=b){
            resp = 1; prop += dx; val+=dx;
            return;
        }
        fix();
        l->update(a,b,dx);
        r->update(a,b,dx);
        fix();
    }
    int query(int a, int b){
        if (a>=rr || b<=lr) return 0;
        if (a<=lr && rr<=b) return val;
        fix();
        return max(l->query(a,b),r->query(a,b));
    }
};
vvii g;
vi price;
vi father, depth, h, dim;
vii liner;
vii resp;
vi anc;
void root(int cur, int p=-1, int d=0){
    depth[cur] = d;
    father[cur] = p;
    vii newg;
    for(auto& x:g[cur]) if (x.x!=p) newg.pb(x);
    g[cur]=newg;
    for(auto x:g[cur]) root(x.x, cur, d+1);
}
void precalc(int cur, bool rec=1){
    int fir=0, sec=0;
    int d=0;
    for(auto nei:g[cur]){
        if (rec) precalc(nei.x);
        int nh = h[nei.x] + price[nei.y];
        if (nh>fir) sec=fir, fir=nh;
        else if (nh>sec) sec=nh;
        chkmax(d, dim[nei.x]);
    }
    chkmax(d, fir+sec);
    h[cur] = fir;
    dim[cur] = d;
}
void update(int cur){
    if (cur==-1) return;
    precalc(cur, 0);
    update(father[cur]);
}
void line(int cur, int an, int d=0){
    anc[cur] = an;
    resp[cur].x = liner.size();
    if (g[cur].size()==0) liner.pb({cur,d});
    for(auto ch:g[cur]) line(ch.x, an, d+price[ch.y]);
    resp[cur].y = liner.size();
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q,w; cin>>n>>q>>w;
    g.resize(n);
    vii edge(n-1);
    price.resize(n-1);
    bool light = (n<=5001 && q<=5001);
    bool binary = 1;
    bool easy=1;
    vi v(n-1);
    set<ii> s;    
    loop(i,0,n-1){
        int a,b,c; cin>>a>>b>>c;
        if (a>b) swap(a,b);
        if (b!=2*a+1 && b!=2*a) binary=0;
        a--;b--;
        edge[i]={a,b};
        g[a].pb({b,i}); g[b].pb({a,i});
        price[i]=c;
        if (a!=0) easy=0;
        v[i]=c;
        s.insert({-c,i});
    }
    if (easy){
        int last=0;
        loop(i,0,q){
            int dj, ej; cin>>dj>>ej;
            dj = (dj+last)%(n-1);
            ej = (ej+last)%w;
            s.erase({-v[dj], dj});
            v[dj] = ej;
            s.insert({-v[dj], dj});
            auto it = s.begin();
            last = -it->x;
            if (s.size()>1){
                it++;
                last+= -it->x;
            }
            cout<<last<<endl;
        }
        return 0;
    }
    father.resize(n,-1); depth.resize(n,-1); h.resize(n,-1); dim.resize(n,-1);
    root(0);
    if (light || binary){
        precalc(0);
        int last=0;
        loop(i,0,q){
            int dj, ej; cin>>dj>>ej;
            dj = (dj+last)%(n-1);
            ej = (ej+last)%w;
            ii cur = edge[dj];
            if (depth[cur.x]>depth[cur.y]) swap(cur.x, cur.y);
            price[dj]=ej;
            update(cur.x);
            last = dim[0]; 
            cout<<last<<endl;
        }
        return 0;
    }
    anc.resize(n,-1);
    resp.resize(n,{-1,-1});
    for(auto ch:g[0]){
        line(ch.x, ch.x, price[ch.y]);
    }
    Node* seg = new Node(0,liner.size()+10);
    loop(i,0,liner.size()) seg->update(i,i+1,liner[i].y);
    map<int, int> results;
    set<ii> maxi;
    for(auto ch:g[0]){
        results[ch.x] =  seg->query(resp[ch.x].x, resp[ch.x].y);
        maxi.insert({-results[ch.x],ch.x});
    }
    int last=0;
    loop(i,0,q){
        int dj, ej; cin>>dj>>ej;
        dj = (dj+last)%(n-1);
        ej = (ej+last)%w;
        ii cur = edge[dj];
        if (depth[cur.x]>depth[cur.y]) swap(cur.x, cur.y);
        int a = cur.y;
        int fat = anc[a];
        //cout<<"A FAT: "<<a<<" "<<fat<<endl;
        maxi.erase({-results[fat],fat});
        seg->update(resp[a].x, resp[a].y, ej-price[dj]);
        price[dj]=ej;
        results[fat] = seg->query(resp[fat].x, resp[fat].y);
        maxi.insert({-results[fat],fat});
        auto it = maxi.begin();
        last = -it->x; 
        if (maxi.size()>1){
            it++;
            last += -it->x; 
        }
        //for(auto res:results) cout<<res.y<<" ";cout<<endl;
        cout<<last<<endl;
    }
    return 0;
}
/*
cls
color a
g++ diameter.cpp -o a & a
8 100 10000
1 2 2
1 3 3
1 4 100
2 5 1
2 6 2
6 7 3
6 8 4

*/




