#include<bits/stdc++.h>
#define int int64_t
#define vi  vector<int>
#define vvi  vector<vi>
#define vvvi  vector<vvi>
#define pb  push_back
#define ii  pair<int,int>
#define vii  vector<ii>
#define x  first
#define y  second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
using namespace std;
struct Op{
    int t = -1, pos = -1;
    int val = -1;
    Op(int t, int pos, int val = -1) : t(t), pos(pos), val(val){}
    bool operator==(const Op& o){
        return t==o.t && pos==o.pos && val==o.val;
    }
    void print(){
        cout<<(t?"I":"D")<<" "<<pos<<" "<<val<<endl;
    }
};

vector<Op> mySort(vector<Op> arr){
    bool ch = true;
    vector<Op> next;
    while(ch && arr.size()>1){
        ch = 0;
        next.clear();
        int last=-1;
        loop(i,0,arr.size()-1){
            Op &l = arr[i], &r = arr[i+1];
            if(l.t == 0 && r.t == 0){
                if(l.pos <= r.pos) {
                    arr[i+1].pos++;
                    swap(arr[i], arr[i+1]);
                    ch = 1;
                }
            }
            else if (l.t==1 && r.t==0){
                ch = 1;
                if (l.pos == r.pos){
                    i++;
                    last = i;
                    continue;
                }
                else if (l.pos>r.pos){
                    arr[i].pos--;
                    swap(arr[i],arr[i+1]);
                }
                else{
                    arr[i+1].pos--;
                    swap(arr[i],arr[i+1]);
                }
            }
            else if (l.t==1 && r.t==1){
                if (l.pos>=r.pos){
                    arr[i].pos++;
                    swap(arr[i],arr[i+1]);
                    ch = 1;
                }
            }
            next.pb(arr[i]);
        }
        if (last!=arr.size()-1) next.pb(arr.back());
        arr.clear();
        for(auto& a:next) arr.pb(a);
        //cout<<"NEXT: "<<next.size()<<endl;
    }
    return arr;
}

int32_t main(){
    string c;
    char val;
    vector<Op> a, b;
    for(int pos;true;){
        cin >> c;
        if(c == "E") break;
        cin >> pos;
        if(c == "I") cin >> val;
        else val = -1;
        a.pb(Op(c == "I", pos, val));
    }

    for(int pos;true;){
        cin >> c;
        if(c == "E") break;
        cin >> pos;
        if(c == "I") cin >> val;
        else val = -1;
        b.pb(Op(c == "I", pos, val));
    }
    a = mySort(a);
    b = mySort(b);
    /*cout<<a.size()<<endl;
    for(auto x:a) x.print();*/
    if(a.size() != b.size()) return cout << 1 << endl, 0;
    for(int i=0;i<a.size();i++){
        if(a[i].t != b[i].t || a[i].pos != b[i].pos) return cout << 1 << endl, 0;
        if(a[i].t == 1 && a[i].val != b[i].val) return cout << 1 << endl, 0;
    }
    cout << 0 << endl;
    return 0;
}
