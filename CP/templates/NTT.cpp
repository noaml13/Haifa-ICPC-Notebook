#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

template <int maxn> struct NTT {
    typedef int32_t rint;
    typedef int64_t lint;
    constexpr static rint lg2(rint n) { return 32 - __builtin_clz(n - 1); }
    // can be used with MOD = 9223372036737335297 for big numbers (and root = 3)
    // but need to change int->int64_t and long long -> __int128_t (in add/sub/mult/exp)
    const static lint MAXN = 1 << lg2(maxn), MOD = 998244353, root = 3;
    rint rev[MAXN], rt[MAXN];

    rint mul(rint a, rint b) { return (lint)a * b % MOD; }
    rint sub(rint a, rint b) { return b > a ? a - b + MOD : a - b; }
    rint add(rint a, rint b) { return (lint)a + b >= MOD ? a + b - MOD : a + b; }

    rint binExp(rint base, lint exp) {
        if (exp == 0)
            return 1;
        return mul(binExp(mul(base, base), exp / 2), exp & 1 ? base : 1);
    }
    NTT() {
        rt[1] = 1;
        for (rint k = 1; k < lg2(MAXN); k++) {
            rint z[] = {1, binExp(root, (MOD - 1) >> (k + 1))};
            for (rint i = (1 << k); i < 2 << k; i++)
                rt[i] = mul(rt[i / 2], z[i & 1]);
        }
    }
    void ntt(rint *a, rint n) {
        for (rint i = 0; i < n; i++)
            rev[i] = (rev[i / 2] | (i & 1) << lg2(n)) / 2;
        for (rint i = 0; i < n; i++)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        for (rint k = 1; k < n; k *= 2)
            for (rint i = 0; i < n; i += 2 * k)
                for (rint j = 0; j < k; j++) {
                    rint z = mul(rt[j + k], a[i + j + k]);
                    a[i + j + k] = sub(a[i + j], z);
                    a[i + j] = add(a[i + j], z);
                }
    }
    rint in[2][MAXN];
    template<class T>
    vector<T> multiply(const vector<T> &a, const vector<T> &b) {
        if (a.empty() || b.empty()) return {};
        rint sz = a.size() + b.size() - 1, n = 1 << lg2(sz);
        fill(in[0], in[0]+n, 0), fill(in[1], in[1]+n, 0);
        copy(all(a), in[0]), copy(all(b), in[1]);
        ntt(in[0], n), ntt(in[1], n);
        rint invN = binExp(n, MOD - 2);
        for (rint i = 0; i < n; i++)
            in[0][i] = mul(mul(in[0][i], in[1][i]), invN);
        reverse(in[0] + 1, in[0] + n);
        ntt(in[0], n);
        return vector<T>(in[0], in[0] + sz);
    }
};