#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        if (n == 1) {
            cout << k << '\n';
            continue;
        }
        int r = 0;
        while ((1LL << (r + 1)) - 1 <= k) {
            r++;
        }
        long long T = (1LL << r) - 1;
        long long rem = k - T;
        vector<long long> ans(n, 0);
        ans[0] = T;
        int idx = 1;
        for (int i = 0; i < r; i++) {
            if (rem >> i & 1) {
                ans[idx] += (1LL << i);
                idx = (idx == n - 1) ? 1 : idx + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}