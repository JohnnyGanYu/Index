#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void solve()
{
    long long n;
    int x;
    cin >> n >> x;
    string s = to_string(n);
    long long res = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        int d = s[i] - '0';
        int remain = len - i - 1;
        if (d > x)
        {
            res += (d - 1) * pow(9, remain);
        }
        else
        {
            res += d * pow(9, remain);
        }
    }
    res += 1;
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}