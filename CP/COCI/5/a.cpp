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

vvb board;
int n,m;
void dfs(int x, int y){
    if (x<0 || x>=n || y<0 || y>=m) return;
    if (!board[x][y]) return ;
    board[x][y]=0;
    loop(i,-1,2) loop(j,-1,2){
        dfs(x+i,y+j);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
     cin>>n>>m;
    board.resize(n,vb(m));
    loop(i,0,n) loop(j,0,m) {
        char c; cin>>c;
        board[i][j]= (c=='*');
    }
    int ans=0;
    loop(i,0,n) loop(j,0,m) if (board[i][j]) ans++,dfs(i,j);
    cout<<ans<<endl;
    return 0;
}


