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
// 按需增删
using namespace std;

void solve()
{
    long long x;
    cin >> x;
    long long k = 2;
    while (x % k == 0)
    {
        k++;
    }
    cout << k << endl;
    return;
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