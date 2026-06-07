#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <climits>
#include <iomanip>
using namespace std;

void solve()
{
    int n, k;
    double total = 1.0;
    cin >> n >> k;

    double r0, c0, p, L, R;
    cin >> r0 >> c0 >> p >> L >> R;
    vector<double> val(n + 5, L);

    for (int i = 0; i < k; ++i)
    {
        int idx;
        cin >> idx;
        cin >> val[idx];
    }

    double sum = total * val[n];
    for (int i = n - 1; i >= 1; --i)
    {
        total *= p;
        sum += total * val[i];
    }
    total *= p;
    double ans = ((p * c0 * (1.0 - total)) / (1.0 - p) + r0 * (1.0 - total)) - sum;
    cout << fixed << setprecision(10) << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}