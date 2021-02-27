#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
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
const int INF=4e18;



void solve(){
    int n; cin>>n;
    string c; cin>>c;
    loop(i,0,n){
        c[i]-='0';
    }
    vector<pair<ii,int>> dig(n-3);
    vector<set<ii>> g(n);
    map<ii,int> edge;
    loop(i,0,n){
        int a=i, b=(i+1)%n;
        g[a].insert({b,c[i]});
        g[b].insert({a,c[i]});
        edge[{a,b}]=c[i];
        edge[{b,a}]=c[i];
    }
    for(auto& d: dig){
        cin>>d.x.x>>d.x.y>>d.y;
        d.x.x--; d.x.y--;
        g[d.x.x].insert({d.x.y,d.y});
        g[d.x.y].insert({d.x.x,d.y});
        edge[{d.x.x,d.x.y}]=d.y;
        edge[{d.x.y,d.x.x}]=d.y;
    }
    set<ii> deg;
    vi a_deg(n);
    loop(i,0,n){
        deg.insert({g[i].size(),i});
        a_deg[i] = g[i].size();
    }
    while(deg.size()>2){
        ii f = *deg.begin();
        deg.erase(deg.begin());
        int cur = f.y;
        //cout<<"CUR: "<<cur<<" " << f.x<<endl;
        if (f.x!=2){
            cout<<"neispravna triangulacija"<<endl;
            return ;
        }
        auto it = g[cur].begin();
        ii a= *it;
        it++;
        ii b=*it;
        // update deg
        auto a_it = deg.find({a_deg[a.x],a.x});
        auto b_it = deg.find({a_deg[b.x],b.x});
        deg.erase(a_it);
        deg.erase(b_it);
        a_deg[a.x]--; a_deg[b.x]--;
        deg.insert({a_deg[a.x],a.x});
        deg.insert({a_deg[b.x],b.x});
        int c1=a.y,c2=b.y,c3;
        //cout<<"A: "<<a.x<<"  "<<b.x<<endl;
        //cout<<"C: "<<c1<<" "<<c2<<endl;
        auto edge_it = edge.find({a.x,b.x});
        //cout<<" IT: "<<it->y<<endl;
        if (edge_it==edge.end()){
            cout<<"neispravna triangulacija"<<endl;
            return ;
        }
        c3 = edge_it->y;
        if (c3==c1 || c1==c2 || c2==c3){
            cout<<"neispravno bojenje"<<endl;
            return ;
        }
        //update g
        g[a.x].erase(g[a.x].find({cur,c1}));
        g[b.x].erase(g[b.x].find({cur,c2}));
    }
    cout<<"tocno"<<endl;
}

int32_t main(){
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}


