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

struct DSU{
    int n; 
    vi p;
    vector<set<int>> nei;
    DSU(int _n){
        n = _n;
        p.resize(n,-1); nei.resize(n);
    }
    int find(int c){
        if (p[c]==-1) return c;
        return p[c]=find(p[c]);
    }
    void uni(int a, int b){
        a = find(a); b = find(b);
        if (a==b) return;
        if (nei[a].size()>nei[b].size()) swap(a,b);
        p[a] = b;
        for(auto x:nei[a]) nei[b].insert(x);
    }
};
const int MAXC = (900+2)*2;
ii operator+(const ii& a, const ii& b){
    return {a.x+b.x,a.y+b.y};
}
int conv(int x, int y){
    return x*MAXC + y;
}
int conv(ii a){
    return conv(a.x, a.y);
}
int dfs(ii cur, vvb& b){
    if (!b[cur.x][cur.y]) return 0;
    b[cur.x][cur.y] = 0;
    int ans=1;
    loop(i,-1,2){
        loop(j,-1,2){
            ans+=dfs(cur+ii(i,j),b);
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,t; cin>>n>>t;
    if (t==1){
        vii ps(n);
        map<ii, int> conv;
        loop(i,0,n) {
            cin>>ps[i].x>>ps[i].y;
            conv[ps[i]]=i+1;
        }
        sort(all(ps));
        priority_queue<pair<ii, int>, vector<pair<ii,int>>, greater<pair<ii,int>> > q;
        q.push({ps[0],conv[ps[0]]});
        //q.push({{10000,10000},-5});
        conv[ps[0]]=0;
        vi ans;
        while(q.size()){
            ii p = q.top().x;
            int ind = q.top().y;
            q.pop();
            ans.pb(ind);
            loop(i,-1,2) loop(j,-1,2){
                ii nextp = {p.x+i, p.y+j};
                if (conv[nextp]){
                    q.push({nextp, conv[nextp]});
                    conv[nextp]=0;
                }
            }
        }
        if (ans.size()>n) cout<<"FUCK!"<<endl;
        if (ans.size()<n) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            loop(i,0,n) cout<<ans[i]<<endl;
        }
        return 0;
    }
    vii ps(n);
    DSU d(MAXC*MAXC);
    vvb board(MAXC, vb(MAXC,0));
    loop(i,0,n) {
        cin>>ps[i].x>>ps[i].y;
        ps[i].x+=MAXC/2; ps[i].y+=MAXC/2;
        board[ps[i].x][ps[i].y]=1;
        loop(x,-1,2){
            loop(y,-1,2){
                if ((x==0)+(y==0)==1){
                    d.nei[conv(ps[i]+ii(x,y))].insert(-i);
                }
            }
        }
    }
    vvb sb(board);
    if (dfs(ps[0],sb)!=n) return cout<<"NO"<<endl,0;
    loop(i,0,MAXC){
        loop(j,0,MAXC){
            if (i){
                if (!board[i][j] && !board[i-1][j]) d.uni(conv(i,j), conv(i-1,j));
            }
            if (j){
                if (!board[i][j] && !board[i][j-1]) d.uni(conv(i,j), conv(i,j-1));
            }
        }
    }
    //cout<<d.find(conv(2+MAXC/2,1+MAXC/2))<<" "<<d.find(0)<<endl;
    int s = d.find(0);
    //cout<<"IN: "; for(auto x:d.nei[s]) cout<<-x<<" "; cout<<endl;
    map<int,bool> check;
    vi ans;
    while(d.nei[s].size()){
        int cur = -(*d.nei[s].begin());
        d.nei[s].erase(d.nei[s].begin());
        if (check[cur]) continue;
        check[cur]=1;
        ii p = ps[cur];
        board[p.x][p.y] = 0;
        ans.pb(cur+1);
        loop(i,-1,2){
            loop(j,-1,2){
                if ((i==0)+(j==0)==1){
                    ii near = p + ii(i,j);
                    if (!board[p.x][p.y] && !board[near.x][near.y]) d.uni(conv(p), conv(near));
                }
            }
        }
        s = d.find(0);
    }
    reverse(all(ans));
    if (ans.size()<n) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        loop(i,0,n) cout<<ans[i]<<endl;
    }
    return 0;
}
/*
color a
cls
g++ skyscrapers.cpp -o a & a
9
2
1 2 
2 1
2 3
3 2
1 3
3 1
1 1
3 3
2 2







14
2
2 2
3 2 
0 1
0 2
0 3
1 0
2 0
3 0
4 1 
4 2
4 3
1 4
2 4
3 4

*/





