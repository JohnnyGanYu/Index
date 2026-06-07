#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int sixseven = n;
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && a[j] == a[i])
            {
                ++j;
            }
            int left = i;
            int right = n - j;
            int cur = max(left, right);
            if (cur < sixseven)
            {
                sixseven = cur;
            }
            i = j;
        }
        cout << sixseven << '\n';
    }
    return 0;
}