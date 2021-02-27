#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define loop(i,s,e) for(int i=(s); i<(e); i++)
#define loopr(i,s,e) for(int i=(e)-1; i>=(s); i--)
#define ii pair<int, int>
#define x first
#define y second
#define vii vector<ii>
#define vvii vector<vii>
#define all(a) a.begin(),a.end()
#define chkmin(a,b) a = min(a,b)
#define chkmax(a,b) a = max(a,b)
using namespace std;

const int LOGN = 7, LOGG = 12, LOGG2 = 6;
//const int LOGN = 2, LOGG = 2, LOGG2 = 1;
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; scanf("%d", &n);
    vi back[LOGN]; // zero is trap, one is empty segment
    {
        vi a(n); 
        loop(i,0,n) scanf("%d", &a[i]);
        back[0].resize(n+2,0);
        map<int, int> last; last[0] = 1;
        int sum = 0;
        loop(i,0,n){
            sum += a[i];
            back[0][i+2] = last[sum];
            last[sum] = i+2;
        }
        a.clear();
        last.clear();
    }
    loop(i,0,n+1) chkmax(back[0][i+1], back[0][i]);
    loop(i,1,LOGN) back[i].resize(n+2, 0);
    loop(k,1,LOGN){
        loop(i,0,n+2){
            back[k][i] = back[k-1][back[k-1][i]]; // power of 2
        }
        if (k==1) loop(b,0,LOGG) loopr(i,0,n+2){
            back[k][i] = back[k][back[k][i]]; // power of 2
        }
    }
    scanf("%d", &q);
    vi a(q),b(q),ans(q);
    loop(qq,0,q){
        scanf("%d %d", &a[qq], &b[qq]); b[qq]++;
        ans[qq] = 0;
        loopr(i,1,LOGN){
            if(back[i][b[qq]]>=a[qq]){
                ans[qq] += 1<<(LOGG+i);
                b[qq] = back[i][b[qq]];
            }
        }
    }
    //loop(i,2,n+2) cout<<back[0][i]<<" "; cout<<endl;
    loop(k,1,LOGN){
        loop(i,0,n+2){
            back[k][i] = back[k-1][back[k-1][i]]; // power of 2
        }
        if (k==1) loop(b,0,LOGG2) loopr(i,0,n+2){
            back[k][i] = back[k][back[k][i]]; // power of 2
        }
    }
    loop(qq,0,q){
        loopr(i,1,LOGN){
            if(back[i][b[qq]]>=a[qq]){
                ans[qq] += 1<<(i+LOGG2);
                b[qq] = back[i][b[qq]];
            }
        }
    }
    loop(k,1,LOGG2+1){
        loop(i,0,n+2){
            back[k][i] = back[k-1][back[k-1][i]]; // power of 2
        }
    }
    loop(qq,0,q){
        loopr(i,0,LOGG2+1){
            if(back[i][b[qq]]>=a[qq]){
                ans[qq] += 1<<(i);
                b[qq] = back[i][b[qq]];
            }
        }
        printf("%d\n", ans[qq]);
    }
    return 0;
}
/*
color 
cls
g++ SumZero.cpp -o a & a
10
1 2 -3 0 1 -4 3 2 -1 1
3
1 10
1 5
2 9
*/