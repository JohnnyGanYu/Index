#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        vector<int> b2(2 * n), c2(2 * n);
        for (int i = 0; i < n; ++i) {
            b2[i] = b2[i + n] = b[i];
            c2[i] = c2[i + n] = c[i];
        }

        int cnt1 = 0;
        for (int d = 0; d < n; ++d) {
            bool ok = true;
            for (int t = 0; t < n; ++t) {
                if (a[t] >= b2[d + t]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt1++;
        }

        int cnt2 = 0;
        for (int g = 0; g < n; ++g) {
            bool ok = true;
            for (int s = 0; s < n; ++s) {
                if (b[s] >= c2[g + s]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt2++;
        }

        long long ans = 1LL * n * cnt1 * cnt2;
        cout << ans << '\n';
    }
    return 0;
}