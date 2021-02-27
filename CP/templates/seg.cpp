struct SEG{
    int n, sz;
    vi a;
    SEG(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i, int x){
        a[i+=sz]=x;
        for(i/=2;i;i/=2) a[i] = max(a[2*i], a[2*i+1]);
    }
    int query(int l, int r){
        int res = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res, a[l++]);
            if (r%2==0) chkmax(res, a[r--]);
        }
        return res;
    }
};

struct Node{
    int maxi, v, prop;
    bool resp;
    int l,r,mid;
    Node *lp, *rp;
    Node(int l, int r): l(l), r(r), mid((l+r)/2), resp(0), v(-INF), maxi(-INF), prop(-INF), lp(0), rp(0){}
    void setprop(int p){
        prop = p; resp = 1;
        v = maxi + prop;
    }
    void fix(){
        if (!lp) lp = new Node(l, mid);
        if (!rp) rp = new Node(mid+1,r);
        if (resp){
            lp->setprop(prop);
            rp->setprop(prop);
            resp = 0;
        }
        maxi = max(lp->maxi, rp->maxi);
        v = max(lp->v, rp->v);
    }
    void build(vi& a){
        if (l==r){
            maxi = a[l];
        }
        else{
            fix();
            lp->build(a); rp->build(a);
            fix();
        }
    }
    void update(int a, int b, int x){
        if (a>r || b<l) return;
        if (a<=l && r<=b){
            setprop(x);
            return ;
        }
        fix();
        lp->update(a,b,x);
        rp->update(a,b,x);
        fix();
    }
    int query(int a, int b){
        if (a>r || b<l) return -INF;
        if (a<=l && r<=b){
            return v;
        }
        fix();
        return max(lp->query(a,b),rp->query(a,b));
    }
};


struct PerNode{
    int lr,rr,mid, amt;
    int val=0;
    PerNode *l=NULL,*r=NULL;
    PerNode(int _l, int _r): lr(_l), rr(_r), mid((_l+_r)/2), amt(_r-_l){}
    void push(){
        if (!l) l = new PerNode(lr, mid);
        if (!r) r = new PerNode(mid, rr);
    }
    void pull(){
        val = l->val + r->val;
    }
    PerNode* update(int i, int x){
        if (lr>i || rr<=i) return this;
        if (lr==i && rr==i+1){
            PerNode* newn = new PerNode(lr,rr);
            newn->val=x;
            return newn;
        }
        push();
        PerNode* newn = new PerNode(lr,rr);
        newn->l = l->update(i,x);
        newn->r = r->update(i,x);
        newn->pull();
        return newn;
    }
    int query(int a, int b){
        if (a>=rr || b<=lr) return 0;
        if (a<=lr && rr<=b) return val;
        push();
        return l->query(a,b) + r->query(a,b);
    }
};