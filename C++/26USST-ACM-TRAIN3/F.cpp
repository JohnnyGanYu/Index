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

int main()
{
    int n, k;
    cin >> n >> k;
    string ans;

    for (int i = 0; i < k; ++i)
    {
        ans += '1';
    }
    for (int i = 0; i < n - k; ++i)
    {
        ans += '4';
    }
    cout << ans << '\n';
    return 0;
}