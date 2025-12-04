#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, q;
        cin >> n >> m >> q; // m=2, q=1
        long long b1, b2;
        cin >> b1 >> b2;
        long long a;
        cin >> a;
        long long L = min(b1, b2);
        long long R = max(b1, b2);
        if (a > L && a < R) {
            cout << (R - L) / 2 << endl;
        } else if (a < L) {
            cout << L - 1 << endl;
        } else { // a > R
            cout << n - R << endl;
        }
    }
    return 0;
}