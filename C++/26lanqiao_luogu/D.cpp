#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int c[(int)1e5 + 100] = {0};
int a[(int)1e5 + 100] = {0};
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}

int main()
{
    int n, m, k;
    long long ans = 0;

    vector<pair<int, int>> s;
    cin >> n >> m >> k;
    for (int i = 1; i < n; ++i)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int i = 0;
    for (; i < k; ++i)
    {
        m -= c[i];
        if (m <= 0)
        {
            break;
        }
        if (m <= a[i])
        {
            ans += m;
            break;
        }
        m -= a[i];
    }
    int fi = 0;
    for (; i < n && i >= k; ++i)
    {
        sort(s.begin(), s.end(), cmp);
        m += a[fi++];
        m -= c[i];
        if (m <= 0)
        {
            break;
        }
        if (m <= a[i])
        {
            ans += m;
            break;
        }
        m -= a[i];
        s.push_back({a[i], i});
    }

    for (; fi <= i; ++fi)
    {
        cout << fi << ' ' << a[fi] << endl;
        ans += a[fi];
    }
    cout << ans << endl;
    return 0;
}