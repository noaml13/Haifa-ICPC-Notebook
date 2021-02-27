#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
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
const int INF=4e18;
const int M=4;
int n;
int id_cnt = 0;
struct Piece{
    int id;
    vi s;
    Piece(vi a=vi(M,0)): s(a), id(id_cnt++){};
    int& operator[](int i){
        return s[i];
    }
};
map<int, vector<Piece*>> g;
map<ii, pair<Piece*,int>> grid;
vb check;
vector<Piece> p;
const int dx[] ={0,-1,0,1}, dy[] = {1,0,-1,0};
bool legal = true;

void bfs(int cur, ii pos={0,0}, int ort = 0){
    if (check[cur]){
        if (grid.find(pos)==grid.end()) legal = false;
        else if (grid[pos].x!=&p[cur] || grid[pos].y != ort) legal = false;
        return;
    }
    check[cur] = 1;
    grid[pos] = {&p[cur], ort};
    loop(i,0,M){
        int bridge = p[cur][i];
        int dir = (ort + i) % M;
        ii next_pos = {pos.x + dx[dir}, pos.y + dy[dir]};
        if(bridge!=0){
            vector<Piece*> next = g[bridge];
            for(auto next_p: next){
                if (next_p!=&p[cur]){



                }

            }
        }
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    p.resize(n);
    int tmp;
    loop(i,0,n){
        loop(j,0,M){
            cin>>tmp;
            p[i][j] = tmp;
            if (tmp!=0) g[tmp].pb(&p[i]);
        }
    }
    check.resize(n,0);
    bfs(0);

    return 0;
}
