#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), in(n + 1, 0), dp(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] <= n)
        {
            in[a[i]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (a[x] <= n)
        {
            dp[a[x]] = max(dp[a[x]], dp[x] + 1);
            in[a[x]]--;
            if (in[a[x]] == 0)
            {
                q.push(a[x]);
            }
        }
    }

    vector<int> maxn(2 * n + 2, 0);
    long long ans = 0;
    vector<bool> vis(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        if (in[i] && !vis[i])
        {
            int cur = i, cycle = 0, maxdp = 0;
            while (!vis[cur])
            {
                vis[cur] = true;
                cycle++;
                maxdp = max(maxdp, dp[cur]);
                cur = a[cur];
            }
            ans += max(cycle, maxdp);
        }
        else if (a[i] > n)
        {
            maxn[a[i]] = max(maxn[a[i]], dp[i]);
        }
    }

    for (int s = n + 1; s <= 2 * n; ++s)
    {
        ans += maxn[s];
    }
    cout << ans << endl;
    return 0;
}