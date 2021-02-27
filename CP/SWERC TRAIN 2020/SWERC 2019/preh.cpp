#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 4e18;
const int mask = (int(1)<<40) - 1;

int get_next(int c){
    return (c + (c>>20) + 12345) & mask;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int s0 = 0x600DCAFE;
    int a = s0, b = s0, c = s0;
    int s = 0, r = 0;
    do{
        a = get_next(a);
        b = get_next(get_next(b));
    }while(a!=b);
    int c0 = 0, c1 = 0;
    do{
        c0 += (c%2==0);
        a = get_next(a);
        c = get_next(c);
        s++;
    }while(a!=c);
    b = a;
    do{
        c1 += (c%2==0);
        c = get_next(c);
        r++;
    }while(b!=c);
    /*cout<<s<<" "<<r<<endl;
    cout<<a<<endl;
    cout<<c0<<" "<<c1<<endl;*/
    int block = 200000;
    if (f){
        b = s0;
        cout<<"{";
        int cnt = 0;
        loop(i,0,s){
            cnt += (b%2==0);
            b = get_next(b);
            if (i%block == block-1) cout<<"{"<<cnt<<","<<b<<"},";
        }
        cout<<"{0,0}};"<<endl;
    }
    else{
        b = a;
        cout<<"{";
        int cnt = 0;
        loop(i,0,r){
            cnt += (b%2==0);
            b = get_next(b);
            if (i%block == block-1) cout<<"{"<<cnt<<","<<b<<"},";
        }
        cout<<"{0,0}};"<<endl;
    }
    return 0;
}
/*
color a
cls
g++ preh.cpp -o a & a > temp.txt




*/