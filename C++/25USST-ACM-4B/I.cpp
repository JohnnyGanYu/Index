#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_REM = 200;
int dp[MAX_REM + 1];

void init() {
    int coins[] = {1, 3, 6, 10, 15};
    
    for (int i = 0; i <= MAX_REM; ++i) dp[i] = 1e9;
    
    dp[0] = 0;

    for (int i = 1; i <= MAX_REM; ++i) {
        for (int c : coins) {
            if (i >= c) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
}

void solve() {
    long long n;
    cin >> n;

    long long ans = 2e18;
    for (int rem = n % 15; rem <= MAX_REM; rem += 15) {
        if (rem > n) break;

        long long current_coins = (n - rem) / 15 + dp[rem];
        
        ans = min(ans, current_coins);
    }

    cout << ans << endl;
}

int main() {

    init();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
