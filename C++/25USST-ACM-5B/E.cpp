#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool possible = true;
        
        for (int i = 0; i < n - 2; i++) {
            if (a[i] < 0) {
                possible = false;
                break;
            }
            
            long long ops = a[i];
            a[i] -= ops;
            a[i + 1] -= 2 * ops;
            a[i + 2] -= ops;
            
            if (a[i + 1] < 0) {
                possible = false;
                break;
            }
        }
        
        if (possible && a[n - 2] == 0 && a[n - 1] == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}