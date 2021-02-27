#include <bits/stdc++.h>
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
const int INF = 1e9, MOD = 1e9+7;

struct Node{
    int lr,rr,mid;
    int val=0;
    Node *l=NULL,*r=NULL;
    Node(int _l, int _r): lr(_l), rr(_r), mid((_l+_r)/2){}
    void fix(){
        if (!l) l = new Node(lr, mid);
        if (!r) r = new Node(mid, rr);
    }
    void update(int a, int b, int x){
        if (a>=rr || b<=lr) return;
        if (a<=lr && rr<=b){
            val+=x;
            return;
        }
        fix();
        l->update(a,b,x);
        r->update(a,b,x);
    }
    int query(int i){
        if (rr-lr<=1) return val;
        fix();
        if (i>=mid) return val+r->query(i);
        else return val+l->query(i);
    }
};
struct POINTS_SEG{
    vi points;
    int n,sz;
    vi a;
    POINTS_SEG(const vi& p): points(p), n(p.size()){
        for(sz=1;sz<n;sz<<=1);
        a.resize(2*sz);
        points.resize(sz,INF);
    }
    void update(int maxy, int v, int cur=1, int l=0,int r=-1){
        if (r==-1) r+=sz;
        if (points[l]>maxy){
            return;
        }
        //cout<<cur<<": "<<l<<" "<<r<<endl;
        if (points[r]<=maxy){
            a[cur]+=v;
            return ;
        }
        int mid = (l+r)/2;
        update(maxy,v,cur*2,l,mid);
        update(maxy,v,cur*2+1,mid+1,r);
    }
    int query(int y, int cur=1, int l=0, int r=-1){
        if (r==-1) r+=sz;
        //cout<<"QUR: "<<cur<<": "<<l<<" "<<r<<endl;
        if (cur>=sz) return a[cur];
        int mid = (l+r)/2;
        if (points[mid]>=y) return a[cur] + query(y,cur*2,l,mid);
        else return a[cur] + query(y,cur*2+1,mid+1,r);
    }
};
struct SEG{
    int n,sz;
    vector<POINTS_SEG> a;
    SEG(vvi &ys){
        n=ys.size();
        for(sz=1;sz<n;sz<<=1);
        a.resize(sz*2, POINTS_SEG(vi(0)));
        ys.resize(sz);
        loop(i,0,sz) a[i+sz]=POINTS_SEG(ys[i]);
        for(int i=sz-1;i;--i){
            vi y(a[2*i].n+a[2*i+1].n);
            vi &l = a[2*i].points, &r = a[2*i+1].points;
            y.resize(set_union(l.begin(), l.begin()+a[2*i].n, r.begin(), r.begin()+a[2*i+1].n, y.begin())-y.begin());
            a[i] = POINTS_SEG(y);
        }
    }
    void update(int x, int y, int v){
        for(int l=x+sz,r=y+sz-1;l<=r;l>>=1,r>>=1){
            if (l%2) a[l++].update(y,v);
            if (r%2==0) a[r--].update(y,v);
            if (l>r) break;
        }
    }
    int query(int x, int y){
        int ans=0;
        for(x+=sz;x;x>>=1){
            ans+=a[x].query(y);
        }
        return ans;
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    /*vi p(n); loop(i,0,n) cin>>p[i];
    POINTS_SEG seg(p);
    loop(i,0,q){
        string op; cin>>op;
        if (op=="1"){
            int a; cin>>a;
            cout<<seg.query(a)<<endl;
        }
        else{
            int maxy,v; cin>>maxy>>v;
            seg.update(maxy,v);
        }
    }*/
    string s; cin>>s;
    vb a(n); loop(i,0,n) a[i]=(s[i]=='1');
    set<ii> sseg;
    loop(i,0,n+1){
        int j = i;
        while(j<n && a[j]) j++;
        sseg.insert({i,j});
        i = j;
    }
    vector<pair<int,ii>> qur(q+1);
    vvi ys(n);
    loop(i,1,q+1){
        string op; cin>>op;
        if (op=="query"){
            int a,b; cin>>a>>b; a--; b--;
            qur[i] = {1,{a,b}};
            ys[a].pb(b);
        }
        else{
            int x; cin>>x; x--;
            qur[i] = {0,{x,-1}};
        }
    }
    loop(i,0,n){
        sort(all(ys[i]));
        ys[i].resize(unique(all(ys[i]))-ys[i].begin());
    }
    SEG segment(ys);
    loop(t,1,q+1){
        if (qur[t].x){
            int a = qur[t].y.x, b = qur[t].y.y;
            int ans = segment.query(a,b);
            auto it = sseg.lower_bound({a,INF}); it--;
            if ((it->y)>=b) {
                ans+=t;
            }
            cout<<ans<<endl;
        }
        else{
            int x= qur[t].y.x;
            if (a[x]){
                auto it = sseg.lower_bound({x,INF});
                it--;
                int l = it->x, r = it->y; 
                sseg.erase(it);
                segment.update(l,r,t);
                segment.update(l,x,-t);
                segment.update(x+1,r,-t);
                sseg.insert({l,x}); sseg.insert({x+1,r});
            }
            else{
                auto it = sseg.lower_bound({x,INF});
                auto pre = prev(it);
                int l = pre->x, r = it->y; 
                sseg.erase(it); sseg.erase(pre);
                segment.update(l,x,t);
                segment.update(x+1,r,t);
                segment.update(l,r,-t);
                sseg.insert({l,r});
            }
            a[x] = !a[x];
        }
    }
    return 0;
}
