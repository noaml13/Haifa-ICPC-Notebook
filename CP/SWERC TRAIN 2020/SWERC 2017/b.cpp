#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 1e18;

struct Node{
    Node *lp=0, *rp=0;
    int i, h;
    Node(int i, int h): i(i), h(h){}
};
vvi ans;
int cnt = 0;
void add(int dx, int ay, int by){
    if (ay<=1) cnt+=dx;
    //loop(i,0,dx+1) loop(j,ay,by+1) ans[j][i]+=dx-i+1;
    ans[ay][dx]++;
    ans[by+1][dx]--;
}
void solve(Node *t, int l, int r, int minh=0){
    if (!t) return ;
    int i = t->i;
    add(r-l, minh + 1, t->h);
    solve(t->lp, l, i, t->h);
    solve(t->rp, i+1, r, t->h);
}
void solve(vi& h){
    int n = h.size();
    vector<Node*> st;
    loop(i,0,n){
        Node *last =0;
        while(st.size() && st.back()->h > h[i]){
            last = st.back();
            st.pop_back();
        }
        Node* cur = new Node(i, h[i]);
        cur->lp = last;
        if (st.size()) st.back()->rp = cur;
        st.pb(cur);
        /*while(st.size() && st.back().y > h[i]){
            int y2 = st.back().y, y1 = 0;
            int x1 = -1, x2 = i;
            if (st.size()>1) {
                x1 = st[st.size()-2].x;
                y1 = st[st.size()-2].y;
            }
            // (x1, x2)
            // (0, x2-x1-1] X (y1, y2]
            int dx = x2 - x1 - 1;
            cout<<"ADD: "<<dx<<" "<<y1<<" "<<y2<<endl;
            add(dx, y1+1, y2);
            st.pop_back();
        }*/
    }
    solve(st[0], 0, n);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m, r, q; cin>>n>>m>>r>>q;
    vvi mat(n+1, vi(m+1));
    loop(i,0,r){
        int a,b,c,d; cin>>a>>b>>c>>d;
        mat[a][c]++;
        mat[a][d]--;
        mat[b][c]--;
        mat[b][d]++;
    }
    loop(i,0,n+1) loop(j,0,m+1){
        if (i) mat[i][j]+=mat[i-1][j];
        if (j) mat[i][j]+=mat[i][j-1];
        if (i && j) mat[i][j]-=mat[i-1][j-1];
    }
    //loop(i,0,n) {loop(j,0,m) cout<<mat[i][j]<<" "; cout<<endl;}
    loop(i,0,n) mat[i][m] = 1;
    vi close(m+1, 0);
    ans.resize(n+2, vi(m+2,0));
    loop(i,0,n){
        loop(j,0,m+1) close[j]++;
        loop(j,0,m+1) if(mat[i][j]) close[j] = 0;
        solve(close);
        //cout<<endl;
    }
    loop(i,1,n+1) loop(j,0,m+1){
        ans[i][j]+=ans[i-1][j];
    }
    loop(i,0,n+1){
        loopr(j,1,m+1){
            ans[i][j-1] += 2*ans[i][j];
            if (j>1) ans[i][j-2] -= ans[i][j];
        }
    }
    //cout<<"CNT: "<<cnt<<endl;
    //loop(i,0,n+1) {loop(j,0,m+1) cout<<ans[i][j]<<" "; cout<<endl;}
    loop(i,0,q){
        int x,y; cin>>x>>y;
        cout<<ans[x][y]<<endl;
    }
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
7 5 3 9
1 2 0 1
5 7 2 5
0 1 2 4
7 1
3 5
5 3
2 2
3 3
4 4
4 5
6 2
1 1



*/