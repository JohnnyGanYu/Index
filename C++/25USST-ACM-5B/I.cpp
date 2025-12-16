#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int ans = 0;
        int prev_val = -2, prev_cnt = 0;

        for (auto& [val, cnt] : freq) {
            if (val == prev_val + 1) {
                if (cnt > prev_cnt) {
                    ans += cnt - prev_cnt;
                }
            } else {
                ans += cnt;
            }
            prev_val = val;
            prev_cnt = cnt;
        }

        cout << ans << "\n";
    }
    return 0;
}