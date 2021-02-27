#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e9;

int n; 
int pos;
map<int, int> qur;
vb been;

int ask(int x){
    if (qur.find(x)!=qur.end()) return qur[x];
    int l =  (n-x+1)/2, r = l + x;
    if (been[l] || been[r]){
        loop(i,0,n-x+1){
            if (!been[i] && !been[i+x]) {
                l = i, r=i+x;
                break;
            }
        }
    }
    cout<<"? "<<l<<endl; 
    int res; cin>>res;
    if (pos!=-1) qur[abs(pos-l)]=res;
    cout<<"? "<<r<<endl; 
    cin>>res;
    qur[abs(r-l)]=res;
    pos = r;
    been[l] = been[r] = 1;
    return res;
}
//int ans;
int solvesmall(int n){ //<=64
    int a;
    int lastp = 0, l=1, r=n, turn=2;
    while(l<=r){
        if (turn){
            cout<<"? "<<l<<endl;
            cin>>a;
            if (turn!=2 && a==0) return cout<<"= "<<(r-l+2)<<endl,0;
            l++;
            
        }
        else{
            cout<<"? "<<r<<endl;
            cin>>a;
            if (a==0) return cout<<"= "<<(r-l+2)<<endl,0;
            r--;
        }
        turn = !turn;
    }
    cout<<"= "<<1<<endl; return 0;
}

int solvemedium(int n){ //<=64
    int x = n/4;
    int l = x, r = n-x+1;
    cout<<"? "<<l<<endl;
    int a; cin>>a;
    cout<<"? "<<r<<endl; 
    cin>>a;
    if (a){
        int turn = 1;
        while(r-l>1){
            if (turn){
                l++;
                cout<<"? "<<l<<endl;
                cin>>a;
                if (a==0) return cout<<"= "<<(r-l+1)<<endl,0;
            }
            else{
                r--;
                cout<<"? "<<r<<endl;
                cin>>a;
                if (a==0) return cout<<"= "<<(r-l+1)<<endl,0;
            }
            turn = !turn;
        }
        return cout<<"= "<<1<<endl,0;
    }
    else{
        int turn = 1;
        while(1){
            if (turn){
                l--;
                if (l<=0) break;
                cout<<"? "<<l<<endl;
                cin>>a;
                if (a==1) return cout<<"= "<<(r-l)<<endl,0;
            }
            else{
                r++;
                if (r>n) break;
                cout<<"? "<<r<<endl;
                cin>>a;
                if (a==1) return cout<<"= "<<(r-l)<<endl,0;
            }
            turn = !turn;
        }
        return cout<<"= "<<n<<endl,0;
    }
    return 0;
}
int solvelarge(int n){ //<=1000
    int mid = 0, jump = 31;
    mid = n/2;
    cout<<mid<<endl;
    int l=mid, r=mid+jump, turn=1;
    cout<<"? "<<l<<endl;
    int res; cin>>res;
    cout<<"? "<<r<<endl;
    cin>>res;
    while(!res){
        if (turn){
            if (l-jump<1) break;
            l-=jump;
            cout<<"? "<<l<<endl;
            cin>>res;
        }
        else{
            if (r+jump>n) break;
            r+=jump;
            cout<<"? "<<r<<endl;
            cin>>res;
        }
        turn = !turn;
    }
    if (res){
        int prel = l, prer = r;
        if (turn){
            prer-=jump;
        }
        else{
            prel-=jump;
        }
        while(!res){
            if (turn){
                l++;
                if (l==prel) break;
                cout<<"? "<<l<<endl;
                cin>>a;
                if (a==1) return cout<<"= "<<(r-l)<<endl,0;
            }
            else{
                r--;
                if (r==prer) break;
                cout<<"? "<<r<<endl;
                cin>>a;
                if (a==1) return cout<<"= "<<(r-l)<<endl,0;
            }
        }
    }
    else{
        int turn = 1;
        while(1){
            if (turn){
                l--;
                if (l<=0) break;
                cout<<"? "<<l<<endl;
                cin>>a;
                if (a==1) return cout<<"= "<<(r-l)<<endl,0;
            }
            else{
                r++;
                if (r>n) break;
                cout<<"? "<<r<<endl;
                cin>>a;
                if (a==1) return cout<<"= "<<(r-l)<<endl,0;
            }
            turn = !turn;
        }
        return cout<<"= "<<n<<endl,0;
    }
    return 0;
}
/*
int solve(int al,int ar, int bl, int br){ //<=64
    int x = (ar-al+1)/4;
    int l = al + x, r = br-x+1;
    cout<<"? "<<l<<endl;
    int a; cin>>a;
    cout<<"? "<<r<<endl; 
    cin>>a;
    if (a){
        return solve(al,l,bl,r);
    }
    else{
        
    }
    return ;
}*/
/*int ans = -1;
void solve(int l, int r, int la, int lb, int ra, int rb){
    int x = (l+r+1)/2;
    int ql = (la+lb)/2, qr = ql+x;
    if ()
    if (ask(x)){

    }
    else{

    } 
}*/
int32_t main(){
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        been.clear(); qur.clear(); pos = -1;
        been.resize(n+1,0);
        if (n<=64){
            solvesmall(n);
            continue;
        }
        if (n<=125){
            solvemedium(n);
            continue;
        }
        if (n<=1000){
            solvelarge(n);
            continue;
        }
        //ans = -1;
        //solve(1,n);
        int l=1, r=n, mid, ans=-1;
        while(0<r-l){
            mid = (l+r)/2;
            if (ask(mid)) ans=mid, r=mid;
            else l = mid + 1;
        }
        if (ans==-1) ans = n;
        cout<<"= "<<ans<<endl;
    }
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
1
1000
*/