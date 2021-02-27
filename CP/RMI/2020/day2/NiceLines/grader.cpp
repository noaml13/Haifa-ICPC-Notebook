#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
namespace {
    using ld = long double;
    const int __MAX_N = 100;

    int __subtask_id;
    int __n, __qmax, __qmin;
    int __queries;
    int __a[__MAX_N];
    int __b[__MAX_N];

    // Print score to stdout and exit.
    void score_and_exit(const double pts, const char *verdict) {
        fprintf(stderr, "Verdict = %s\n", verdict);
        fprintf(stdout, "Score = %lf\n", pts);
        exit(0);
    }

    long double compute_query(long double x, long double y) {
        ld ans = 0;
        loop(i,0,__n){
            int a = __a[i], b = __b[i];
            ans += abs(a*x-y+b) / sqrt(a*a+1.0);
        }
        return ans; // You can compute the distance...
        // or read it from the input...
        printf("query(%Lf, %Lf) = \n", x, y);
        //cout<<"BO: "<<endl;
        fflush(stdout);
        long double answer;
        assert(scanf("%Lf", &answer) == 1);
        return answer;
    }
    
    double score(int q) {
        if (q > __qmax) {
            return 0;
        } else if (q <= __qmin) {
            return 1;
        } else {
            return 1.0 - 0.7 * double(q - __qmin) / double(__qmax - __qmin);
        }
    }

    void wrongQueryFormat() {
        score_and_exit(0, "Invalid parameters supplied as query!");
    }

    void accepted(double pts) {
        score_and_exit(pts, "Is it OK?");
    }

    void readTest() {
        assert(scanf("%d", &__subtask_id) == 1);
        assert(scanf("%d%d%d", &__n, &__qmax, &__qmin) == 3);
        for (int i = 0; i < __n; i++) {
            assert(scanf("%d%d", &__a[i], &__b[i]) == 2);
        }
    }
}

long double query(long double x, long double y) {
    __queries++;
    if (__queries > __qmax) {
        score_and_exit(0, "Too many queries!");
    }
    if (!isfinite(x) || !isfinite(y)
            || fabs(x) > 1e12 || fabs(y) > 1e12) {
        fprintf(stderr, "x = %Lf, y = %Lf, ", x, y);
        wrongQueryFormat();
    }
    return compute_query(x, y);
}

void the_lines_are(std::vector<int> a, std::vector<int> b) {
    assert(__n == (int)a.size() && a.size() == b.size());
    printf("Your answer is:\n");
    for (int i = 0; i < __n; i++) {
        printf("a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
    }
    printf("Number of queries is: %d\n", __queries);
    accepted(score(__queries));
}

int main() {
    readTest();
    solve(__subtask_id, __n);
    return 0;
}
