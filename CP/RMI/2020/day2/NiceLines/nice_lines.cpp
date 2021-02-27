#include <stdio.h>
#include "nice_lines.h"
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
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
const int MOD = 1e9 + 7;
using ld = long double;
const int MAX = 1e4+10;
const ld eps = 1e-8;
ld getDist(ld a, ld b, ld x, ld y){
    return abs(a*x-y+b) / sqrt(a*a+1.0);
}
pair<ld, ld> inter(int a0, int b0, int a1, int b1){
    ld x = ld(b1-b0) / ld(a0-a1);
    return {x, a0*x+b0};
}
pair<ld, ld> calc(int aa, int aaa, ld qy, int sign=1){
    ld down = qy - 1.0 / sqrt(aa*aa+1.0) - 1.0 / sqrt(aaa*aaa+1.0);
    ld tmp = 1/(down*down) - 1;
    if (tmp<0) return {0,1e30};
    tmp = sign * sqrt(tmp);
    ld val = tmp / sqrt(tmp * tmp +1.0) + aa / sqrt(aa * aa +1.0) + aaa / sqrt(aaa * aaa +1.0);
    return {tmp, val};
}
void solve(int subtask_id, int N) {
    cout<<setprecision(10);
    int y = 1e5;
    if (N==1){
        ld q1 = query(0,-y), q2 = query(0,-(y+1)), q3 = query(1, -y);
        ld q = q2 - q1;
        q = sqrt(1/(q*q) - 1);
        int a = round(q),b;
        q = q3 - q1;
        if (q<0) a = -a;
        q = q1 * sqrt(a*a+1.0) - y;
        //cout<<"LD: "<<q<<endl;
        b = round(q);
        the_lines_are(vi({a}), vi({b}));
    }
    else if (N==2){
        ld q1 = query(0,-y), q2 = query(0,-(y+1)), q3 = query(1, -y);
        ld qy = q2 - q1, qx = q3 - q1;
        int a0,b0=0,a1,b1=0;
        ld mini = 1e20;
        loop(aa,-MAX, MAX){
            ld down = qy - 1.0 / sqrt(aa*aa+1.0);
            ld tmp = 1/(down*down) - 1;
            if (tmp<0) continue;
            tmp = sqrt(tmp);
            ld val = tmp * down + aa * 1.0 / sqrt(aa * aa +1.0);
            if (abs(val - qx)<mini){
                a0 = round(aa);
                a1 = round(tmp);
                mini = abs(val - qx);
            }
            tmp = -tmp;
            val = val = tmp * down + aa * 1.0 / sqrt(aa * aa +1.0);
            if (abs(val - qx)<mini){
                a0 = round(aa);
                a1 = round(tmp);
                mini = abs(val - qx);
            }
        }
        if (a0 > a1) swap(a0, a1);
        int l = -MAX, r = MAX, mid, bb=-MAX;
        while(l<r){
            mid = floor((l+r)/2.0);
            ld qa = query(0, mid), qb = query(0, mid+1);
            if (abs((qb-qa)-(q1-q2))<eps) bb = l = mid + 1;
            else r = mid;
        }
        b0 = bb;
        l = b0, r = MAX, mid, bb=b0;
        while(l<r){
            mid = floor((l+r)/2.0);
            ld qa = query(0, mid), qb = query(0, mid+1);
            if (abs((qa-qb)-(q1-q2))<eps) bb = mid, r = mid;
            else l = mid + 1;
        }
        b1 = bb;
        pair<ld, ld> p1 = inter(a0,b0,a1,b1);
        pair<ld, ld> p2 = inter(a0,b1,a1,b0);
        if (abs(query(p1.x, p1.y))>abs(query(p2.x, p2.y))) {
            swap(b0,b1);
        }
        the_lines_are(vi({a0, a1}), vi({b0, b1}));
    }
    else if (N==3){
        ld q1 = query(0,-y), q2 = query(0,-(y+1)), q3 = query(1, -y);
        ld qy = q2 - q1, qx = q3 - q1;
        int a0,b0=0,a1,b1=0, a2, b2=0;
        ld mini = 1e20;
        loop(aa,-MAX, MAX){
            int l=aa,r=MAX, aaa;
            while(l+2<r){
                aaa = floor((l+r)/2.0);
                auto v1 = calc(aa,aaa,qy), v2 = calc(aa,aaa+1,qy);
                if (v2.y>v1.y) r = aaa+1;
                else l = aaa;
            }
            loop(b,0,4){
                aaa = l;
                auto v = calc(aa,aaa,qy);
                if (abs(v.y - qx)<mini){
                    a0 = aa;
                    a1 = aaa;
                    a2 = round(v.x);
                    mini = abs(v.y - qx);
                }
                l++;
            }
            l=aa,r=MAX, aaa;
            while(l+2<r){
                aaa = floor((l+r)/2.0);
                auto v1 = calc(aa,aaa,qy,-1), v2 = calc(aa,aaa+1,qy,-1);
                if (v2.y>v1.y) r = aaa+1;
                else l = aaa;
            }
            loop(b,0,4){
                aaa = l;
                auto v = calc(aa,aaa,qy,-1);
                if (abs(v.y - qx)<mini){
                    a0 = aa;
                    a1 = aaa;
                    a2 = round(v.x);
                    mini = abs(v.y - qx);
                }
                l++;
            }
        }
        /*int aa = 1000, aaa = 9998;
        auto v = calc(aa,aaa,qy,1);
        if (abs(v.y - qx)<mini){
            a0 = aa;
            a1 = aaa;
            a2 = round(v.x);
            mini = abs(v.y - qx);
        }
        cout<<"MINI: "<<mini<<" "<<abs(v.y - qx)<<endl;*/
        int l = -MAX, r = MAX, mid, bb=-MAX;
        while(l<r){
            mid = floor((l+r)/2.0);
            ld qa = query(0, mid), qb = query(0, mid+1);
            if (abs((qb-qa)-(q1-q2))<eps) bb = l = mid + 1;
            else r = mid;
        }
        b0 = bb;
        l = b0, r = MAX, mid, bb=b0;
        while(l<r){
            mid = floor((l+r)/2.0);
            ld qa = query(0, mid), qb = query(0, mid+1);
            if (abs((qa-qb)-(q1-q2))<eps) bb = mid, r = mid;
            else l = mid + 1;
        }
        b1 = bb;
        mini = 1e20;
        vi as{a0,a1,a2};
        vi besta, bestb;
        ld dd = query(y,y);
        do{
            a0 = as[0], a1 = as[1], a2 = as[2];
            ld q = y * (a0 / sqrt(a0*a0+1) + a1 / sqrt(a1*a1+1) +  a2 / sqrt(a2*a2+1));
            q = q1 - q - b0 / sqrt(a0*a0+1) - b1 / sqrt(a1*a1+1);
            q = q * sqrt(a2*a2+1);
            b2 = round(q);
            ld val = getDist(a0, b0, y, y) + getDist(a1, a1,y,y) + getDist(a2,a2,y,y);
            val = abs(val - dd);
            if (val<mini){
                mini = val;
                besta = as; 
                bestb = {b0,b1,b2};
                cout<<"HI: "<<a0<<" "<<a1<<" "<<a2<<" "<<b0<<" "<<b1<<" "<<b2<<endl;
            }
        }while(next_permutation(all(as)));
        the_lines_are(besta, bestb);
    }
}
/*
color 
cls
g++ nice_lines.cpp nice_lines.h grader.cpp -o a & a
2
3 10000 10000
9999 9998
9998 9997
1000 -456

2
2 10000 10000
9999 -9999
-9999 9999
*/
