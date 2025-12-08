#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r, L, R, n = 1;
        cin >> l >> r >> L >> R;
        int x = max(l, L);
        int y = min(r, R);
        if (x > y) {
            n++;
        } else if (x == y) {
            n++;
        } else {
            
        }
        cout << n << endl;
    }
    return 0;
}