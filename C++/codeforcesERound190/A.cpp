#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;

        ll cost1 = n * a;
        ll cost2 = (n / 3) * b + (n % 3) * a;
        ll cost3 = ((n + 2) / 3) * b;

        cout << min({cost1, cost2, cost3}) << '\n';
    }
    return 0;
}