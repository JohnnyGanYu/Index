#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        
        int result = 0;
        
        for (int i = 1; i <= n; i++) {
            int diff = abs(i - p[i]);
            if (diff != 0) {
                if (result == 0) {
                    result = diff;
                } else {
                    result = gcd(result, diff);
                }
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}