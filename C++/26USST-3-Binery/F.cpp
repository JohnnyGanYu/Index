#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

int a[200010];
int b[200010];

signed main()
{
    int n, s, initial_sum = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        initial_sum += a[i];
    }
    if (initial_sum >= s)
    {
        cout << n << endl;
        return 0;
    }
    sort(a, a + n);
    b[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    int low = 0;
    int high = min((long long)2e9, s);
    while (low < high)
    {
        int mid = (low + high + 1) / 2;
        int idx = upper_bound(a, a + n, mid) - a;
        int sum = initial_sum + (1 + mid) * mid / 2 - (idx == 0 ? 0 : b[idx - 1]);
        if (sum >= s)
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }
    int idx = upper_bound(a, a + n, low) - a;
    cout << low + n - idx + 1 << endl;
    return 0;
}