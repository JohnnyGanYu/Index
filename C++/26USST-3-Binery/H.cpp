#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int mid, int m, int n, const vector<vector<int>> &p)
{
    vector<bool> friend_satisfied(n, false);
    bool pair_found = false;

    for (int i = 0; i < m; ++i)
    {
        int count_in_this_shop = 0;
        for (int j = 0; j < n; ++j)
        {
            if (p[i][j] >= mid)
            {
                friend_satisfied[j] = true;
                count_in_this_shop++;
            }
        }
        if (count_in_this_shop >= 2)
        {
            pair_found = true;
        }
    }

    for (int j = 0; j < n; ++j)
    {
        if (!friend_satisfied[j])
            return false;
    }

    return pair_found;
}

void solve()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> p(m, vector<int>(n));
    int max_val = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> p[i][j];
            max_val = max(max_val, p[i][j]);
        }
    }

    int left = 1, right = max_val, ans = 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, m, n, p))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        getchar();
        solve();
    }
    return 0;
}