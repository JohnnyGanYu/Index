#include <iostream>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << -1 << endl;
    }
    else {
        for (int i = 2; i <= n-k; i++) {
            cout << i << ' ';
        }
        cout << 1 << ' ';
        for (int i = n-k+1; i <= n ; i++) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}