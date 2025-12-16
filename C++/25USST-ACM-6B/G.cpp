#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int m, temp;
    cin >> m;
    vector<int> b(5001, 0);
    for (int i = 0; i < m; i++) {
        cin >> temp;
        b[temp]++;
    }

    for (int i = 1; i <= 5000; i++) {
        if (b[i]) {
            if ( b[i] > 2 ) {
                m -= b[i] - 2;
            }
            temp = i;
        }
    }
    if (b[temp] > 1) m--;
    cout << m << endl;

    for (int i = 1; i <= 5000; i++) {
        if (b[i]) {
            b[i]--;
            cout << i << ' ';
        }
    }

    for (int i = temp-1; i >= 1; i--) {
        if (b[i]) {
            //b[i]--;
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}