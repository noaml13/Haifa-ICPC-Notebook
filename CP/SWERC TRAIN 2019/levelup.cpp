#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define INF 4e18
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
using namespace std;

struct PP
{
    int x, t, y, r;

    PP(int x=0, int t=0, int y=0, int r=0) : x(x), t(t), y(y), r(r)
    {}

    bool operator<(const PP &o){
        return x < o.x;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int s1, s2, n;
    cin >> n>> s1 >> s2;
    vvi dp(s1 + 1, vi(s2 + 1, INF));

    vector<PP> pp(n);

    for (auto &p: pp)
    {
        cin >> p.x >> p.t >> p.y >> p.r;
    }
    sort(pp.begin(), pp.end());
    /*sort(pp.begin(), pp.end(), [&](const PP& a, const PP& b) {
        return a.x < b.x;
    });*/
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        const PP& cur = pp[i];
        for (int j = s1; j >= 0; --j)
        {
            for (int k = s2; k >= 0; --k)
            {
                chkmin(dp[j][k], dp[j][k]);
                chkmin(dp[j][min(s2, k+cur.y)], dp[j][k] + cur.r);
                // dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j][max((int)0, k-cur.y)] + cur.r);
                if (j==s1) continue;
                int overflow = cur.x + j - s1;
                if(overflow>0) chkmin(dp[s1][min(s2, k+overflow)], dp[j][k] + cur.t);
                else chkmin(dp[j+cur.x][k], dp[j][k] + cur.t);
                    //dp[i][j][k] = min(dp[i][j][k], dp[i-1][0][max((int)0, k - overflow)] + cur.t);
            }
        }
    }
    if(dp[s1][s2] != INF) cout << dp[s1][s2]<<endl;
    else cout << -1 << endl;
    return 0;
}
