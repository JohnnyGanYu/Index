#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long m = 0;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                p[i] = m;
                m += a[i];
            } else {
                p[i] = m - a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}