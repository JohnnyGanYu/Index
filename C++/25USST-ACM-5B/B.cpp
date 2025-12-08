#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a = 1, cnt = 1;
        while (a < n) {
            a++;
            cnt++;
            a *= 2;
        }
        cout << cnt << "\n";
    }
    return 0;
}