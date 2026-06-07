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
    int n;
    cin >> n;
    int cnt = 0;
    long long a;
    char b;
    int val;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (b == 'A')
        {
            val = 10;
        }
        else
        {
            val = b - '0';
        }
        long long num = (a % 5) * (val % 5);
        cnt = (cnt + num) % 5;
    }
    cout << ((cnt == 0) ? "Yes" : "No") << '\n';
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