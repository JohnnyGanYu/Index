#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    ll n, P, l, t;
    cin >> n >> P >> l >> t;

    ll m = (n + 6) / 7;

    ll left = 0, right = n, ans = n;
    while (left <= right) {
        ll mid = (left + right) / 2; 
        
        ll tasks_done = min(m, 2 * mid);
        ll score = mid * l + tasks_done * t;
        
        if (score >= P) {
            ans = mid;         
            right = mid - 1;
        } else {
            left = mid + 1;    
        }
    }

    cout << n - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    
    return 0;
}