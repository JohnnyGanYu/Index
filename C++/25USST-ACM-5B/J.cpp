#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (n <= 2) {
            cout << "YES\n";
            continue;
        }
        
        bool ok = true;
        for (int i = 0; i < n-2; i++) {
            int g = gcd(a[i], a[i+2]);
            if (a[i+1] % g != 0) {
                ok = false;
                break;
            }
        }
        
        cout << (ok ? "YES\n" : "NO\n");
    }
    
    return 0;
}