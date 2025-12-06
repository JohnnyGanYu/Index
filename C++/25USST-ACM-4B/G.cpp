#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

long long pow_mod(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long max_subarray_sum(const vector<int>& a) {
    long long max_ending_here = 0;
    long long max_so_far = 0;
    for (int x : a) {
        max_ending_here = max(0LL, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        long long S = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S += a[i];
        }
        
        long long M = max_subarray_sum(a);
        
        if (M == 0) {
            long long ans = S % MOD;
            if (ans < 0) ans += MOD;
            cout << ans << '\n';
            continue;
        }
        
        long long p2k = pow_mod(2, k);
        long long p2k_1 = pow_mod(2, k - 1);

        long long S_mod = S % MOD;
        if (S_mod < 0) S_mod += MOD;
        long long M_mod = M % MOD;
        if (M_mod < 0) M_mod += MOD;

        long long ans_a = (S_mod * p2k) % MOD;

        long long term_b = ((p2k - 1 + MOD) % MOD * M_mod) % MOD;
        long long ans_b = (S_mod + term_b) % MOD;

        long long sum_sm = (S_mod + M_mod) % MOD;
        long long ans_c = (sum_sm * p2k_1) % MOD;
        
        long long ans = max({ans_a, ans_b, ans_c});
        cout << ans << '\n';
    }
    
    return 0;
}