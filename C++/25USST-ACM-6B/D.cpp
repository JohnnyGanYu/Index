#include <iostream>
using namespace std;

inline int removeZeros(int n) {
    int res = 0, p = 1;
    while (n > 0) {
        int d = n % 10;
        if (d != 0) {
            res += d * p;
            p *= 10;
        }
        n /= 10;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    int c = a + b;
    
    int a1 = removeZeros(a);
    int b1 = removeZeros(b);
    int c1 = removeZeros(c);
    
    cout << (a1 + b1 == c1 ? "YES" : "NO") << endl;
    
    return 0;
}