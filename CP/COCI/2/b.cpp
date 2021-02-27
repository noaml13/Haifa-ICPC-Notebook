#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define a first
#define x second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;



int32_t main(){
    int n; cin>>n;
    ii s, e;
    vii c_in, c_out, left, right;
    loop(i,0,n){
        int x,a;
        cin >> x >> a;
        if (x==5 || x==6){
            s={a,x};
        }
        else if (x==7 || x==8){
            e={a,x};
        }
        else if (x==1){
            c_out.pb({a,x});
        }
        else if (x==4){
            c_in.pb({a,x});
        }
        else if (x==2){
            left.pb({a,x});
        }
        else if (x==3){
            right.pb({a,x});
        }
    }
    sort(all(c_in)); //a
    sort(all(c_out)); //b
    sort(all(left)); //c
    sort(all(right)); //d
    int a=0,b=0,c=0,d=0;
    bool dir = (s.x==5);
    vi ans;
    ans.pb(s.a);
    bool can = true;
    loop(i,0,n-2){
        if (dir){
            if(a==c_in.size() && d==right.size()){
                can =false;
                break;
            }
            else if(d==right.size()){
                ans.pb(c_in[a++].a);
                dir = !dir;
            }
            else if (b==c_out.size() || a==c_in.size() || right[d]<c_in[a]){
                ans.pb(right[d++].a);
            }
            else{
                ans.pb(c_in[a++].a);
                dir = !dir;
            }
        }
        else{
            if(b==c_out.size() && c==left.size()){
                can =false;
                break;
            }
            else if(c==left.size()){
                ans.pb(c_out[b++].a);
                dir = !dir;
            }
            else if (a==c_in.size() || b==c_out.size() || left[c]<c_out[b]){
                ans.pb(left[c++].a);
            }
            else{
                ans.pb(c_out[b++].a);
                dir = !dir;
            }
        }
    }
    ans.pb(e.a);
    if (can){
        can = (dir==(e.x==8));
    }
    if (can){
        for(auto g:ans) cout<<g<<" ";
        cout<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    return 0;
}


