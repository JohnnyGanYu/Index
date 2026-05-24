#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> d;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            d.push_back(i);
    }

    if (d.empty())
    {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i + 1 < (int)d.size(); i++)
    {
        if (d[i + 1] == d[i] + 1)
        {
            cout << "NO\n";
            return;
        }
    }

    int k = 0;
    for (int p : d)
        k = max(k, a[p] - a[p + 1]);

    for (int i = 0; i + 1 < (int)d.size(); i++)
    {
        int p = d[i], q = d[i + 1];
        int mx = -2000000000;
        for (int m = p + 1; m < q; m++)
            mx = max(mx, a[m + 1] - a[m]);
        if (k > mx)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}