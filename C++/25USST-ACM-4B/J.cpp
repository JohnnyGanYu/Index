#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (a[0] != a[1]) {
        cout << "YES" << "\n";
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] % a[0] != 0) {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
