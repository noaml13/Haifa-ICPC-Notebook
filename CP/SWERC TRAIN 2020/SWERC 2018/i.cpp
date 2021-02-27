#include <bits/stdc++.h>
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
const int INF = 1e9, MOD = 1e9 + 7;

int n,m;
vvb mat;
bool in(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}
//vii vec;
void dfs(int i, int j){
    // cout<<"IJ: "<<i<<" "<<j<<" "<<endl;
    if (!in(i,j)) return ;
    if (!mat[i][j]) return ;
    mat[i][j] = 0;
    //vec.pb({i,j});
    loop(dx,-1,2) loop(dy,-1,2) dfs(i+dx, j+dy);
}
int cnta=0, cntb=0, cntc=0;
void solveDigit(int i, int j){
    int w=0,h=0;
    while(j+w<m && mat[i][j+w]) w++;
    while(i+h<n && mat[i+h][j]) h++;
    w--, h--;
    if (!mat[i+h/2][j+w]) cntc++;
    else if(mat[i+h][j+w/2]) cntb++;
    else cnta++;
    dfs(i,j);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m; swap(n,m);
    mat.resize(n, vb(m));
    loop(i,0,n){
        string s; cin>>s;
        loop(j,0,m) mat[i][j] = (s[j]=='#');
    }
    // cout<<"HI: "<<endl;
    // reduce noise
    loop(i,1,n-1) loop(j,1,m-1) if(mat[i][j]){
        int cnt = 0;
        loop(dx,-1,2) loop(dy,-1,2){
            cnt += mat[i+dx][j+dy];
        }
        if (cnt==1) mat[i][j] = 0;
    }
    // delete edges
    dfs(0,0);
    loop(i,0,n) loop(j,0,m) if(mat[i][j]){ // digit
        solveDigit(i,j);
    }
    cout<<cnta<<" "<<cntb<<" "<<cntc<<endl;
    return 0;
}
/*
color a
cls
g++ i.cpp -o a & a
26 15
##########################
##........######......#..#
#...###....#####..#......#
#...#.#....####.........##
#...###.....##....#####..#
#...#.#.....#.....#####..#
#...###.....#.....##.##..#
#........#..#.#...#####..#
#..###......#.....#####..#
#..#........#...#.##.##..#
#..#........#.....##.##..#
#..#...#.#..#...#.##.##..#
#..###......#............#
###....#....##....##.....#
##########################


*/