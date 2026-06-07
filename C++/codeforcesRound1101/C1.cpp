#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, s;
        cin >> n >> x >> s;
        string u;
        cin >> u;
        int m = n + 1, mc = min(n, x);
        vector<vector<bool>> f(mc + 1, vector<bool>(m, false));
        f[0][0] = true;
        vector<vector<bool>> ok(mc + 1, vector<bool>(m, false));
        for (int c = 0; c <= mc; ++c)
        {
            long long lim = 1LL * c * (s - 1);
            if (lim > n)
                lim = n;
            for (int d = 0; d <= lim; ++d)
                ok[c][d] = true;
        }
        for (char ch : u)
        {
            auto g = f;
            for (int c = 0; c <= mc; ++c)
            {
                for (int d = 0; d < m; ++d)
                {
                    if (!f[c][d])
                        continue;
                    if (ch == 'I' || ch == 'A')
                    {
                        if (c + 1 <= mc && ok[c + 1][d])
                            g[c + 1][d] = true;
                    }
                    if (ch == 'E' || ch == 'A')
                    {
                        if (d + 1 < m && ok[c][d + 1])
                            g[c][d + 1] = true;
                    }
                }
            }
            f = move(g);
        }
        int ans = 0;
        for (int c = 0; c <= mc; ++c)
            for (int d = 0; d < m; ++d)
                if (f[c][d])
                    ans = max(ans, c + d);
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}