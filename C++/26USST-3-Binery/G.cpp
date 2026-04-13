#include <iostream>
using namespace std;

int a[1010];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long low = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > low)
                low = a[i];
        }

        long long high = low + k;
        long long ans = low;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            bool check = false;
            for (int i = 0; i < n - 1; i++)
            {
                long long need = mid;
                long long cost = 0;
                bool possible = false;
                for (int j = i; j < n; j++)
                {
                    if (a[j] >= need)
                    {
                        possible = true;
                        break;
                    }
                    cost += (need - a[j]);
                    need = need - 1;
                    if (cost > k)
                    {
                        break;
                    }
                }
                if (possible)
                {
                    check = true;
                    break;
                }
            }

            if (check)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}