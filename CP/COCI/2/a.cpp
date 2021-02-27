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

int getN(string& s, int i){
    return s[i]-'0';
}

ii calc_max_value(string& t){
    char state = t[0];
    if (state=='-') return {0,0};
    int n = getN(t,1);
    if (n==0) return {0,0};
    int time = getN(t,4)*60*60 +(getN(t,6)*10+getN(t,7))*60+(getN(t,9)*10+getN(t,10));
    return {1,time+20*60*(n-1)};
}

bool comp(const pair<ii,string>& a, const pair<ii,string>& b){
    if (a.x.x==b.x.x){
        if (a.x.y==b.x.y) {
            return a.y>b.y;
        }
        return a.x.y>b.x.y;
    }
    return a.x.x<b.x.x;
}

int32_t main(){
    int n, m; cin>>n>>m;
    string name,t;
    vector<pair<ii,string>> s;
    loop(i,0,n){
        cin>>name;
        ii score ={0,0};
        loop(j,0,m){
            cin>>t;
            ii v = calc_max_value(t);
            score.x += v.x;
            score.y += v.y;
        }
        if (name=="NijeZivotJedanACM"){
            continue;
        }
        //cout << score.x <<" "<<score.y<<endl;
        s.pb({score, name});
    }
    ii score ={0,0};
    cin>>name;
    loop(j,0,m){
        cin>>t;
        ii v = calc_max_value(t);
            score.x += v.x;
            score.y += v.y;
    }
    pair<ii,string> team = {score,name};
    int cnt=1;
    for(auto b:s){
        if (comp(team,b)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

