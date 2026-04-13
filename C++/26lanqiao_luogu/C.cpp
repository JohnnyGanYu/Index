#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long num = 1;
        long long ans = 1;
        for (int i = 0; i < x - y - 1; ++i)
        {
            num <<= 1;
            num %= 998244353;
        }
        ans = (ans + y * num) % 998244353;
        cout << ans << endl;
    }
    return 0;
}