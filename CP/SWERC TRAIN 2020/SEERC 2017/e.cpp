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

int m[255];
inline int cnv(char *k) {
    // Do,Do#,Re,Re#,Mi,Fa,Fa#,Sol,Sol#,La,La#,Si
    if(k[0] != 'S') return m[k[0]]+(k[2]!=0);
    return k[1]=='o'?(7+(k[3]!=0)):11;
}
int inKey[] = {0,2,4,5,7,9,11}; int inKeyNum = 7;
int outKey[] = {1,3,6,8,10}; int outKeyNum = 5;
bool bInKey[12] = {0};
#define add(a,b) (a+b>11?a+b-12:a+b)
#define sub(a,b) (a-b<0?a-b+12:a-b)
#define isInKey(a, k) bInKey[sub(a, k)]

const int MAX = 1e7 + 10;
int dp[MAX];
vi inds[12];
int pt[12];
int tmp[12];
int n;
int a[MAX];
int ans = INF;
void solve(int firstKey){
    if (!isInKey(a[1], firstKey) && !isInKey(a[n-1], firstKey)){
        return ;
    }
    int end = n-1;
    while(end>=0 && isInKey(a[end], firstKey)) end--;
    end++;
    if (end==0){
        ans = 1;
        return ;
    }
    fill(dp, dp+n+1, INF);
    fill(pt, pt+12, 0);
    dp[0] = 0;
    loop(i,0,n){
        pt[a[i]]++;
        if (dp[i]==INF) continue;
        int far = -1;
        loop(j,0,12){
            tmp[j] = inds[j][pt[j]];
        }
        loop(ind,0,inKeyNum){
            int k = sub(a[i], inKey[ind]);
            if (i==0 && k!=firstKey) continue;
            int close = n;
            loop(ind2,0,outKeyNum){
                chkmin(close, tmp[add(k, outKey[ind2])]);
            }
            chkmax(far, close);
        }
        chkmin(dp[far], dp[i] + 1);
        if (far-1>i+1) chkmin(dp[far-1], dp[i] + 1);
    }
    int res = INF;
    loop(i,end,n+1) chkmin(res, dp[i]);
    chkmin(ans, res);
}
int32_t main(){
    // ios_base::sync_with_stdio(false);
    m['D'] = 0, m['R'] = 2, m['M'] = 4, m['F'] = 5, m['L'] = 9;
    loop(i,0,inKeyNum) bInKey[inKey[i]] = 1;
    scanf("%d",&n);
    char s[10]; int ind; getchar();
    loop(i,0,n){
        ind = 0;
        do{
            s[ind] = getchar();
        }while(s[ind++]!='\n');
        s[ind-1] = 0;
        // printf("%s\n", s);
        a[i] = cnv(s);
        inds[a[i]].pb(i);
    }
    // loop(i,0,n) cout<<a[i]<<" "; cout<<endl;
    loop(i,0,12) inds[i].pb(n);
    loop(i,0,inKeyNum){
        solve(sub(a[0], inKey[i]));
    }
    printf("%d", ans); 
    return 0;
}
/*
color a
cls
g++ e.cpp -o b & b
8
Do
Re
Mi
Fa
Sol
La
Do#
Si



g++ e.cpp -o b & b
8
La
Si
Do
Si
La
Sol
Fa
Mi



*/