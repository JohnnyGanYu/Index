#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int t;
    char temp;
    cin >> t;
    vector<vector<bool>> a(t, vector<bool>(t, 0));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            cin >> temp;
            if (temp == '#') {
                a[i][j] = 1;
            }
        }
    }
    if ( a[0][0] || a[0][t-1] || a[t-1][0] || a[t-1][t-1] ) {
        cout << "NO" << '\n';
        return 0;
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (a[i][j]) {
                if (i+2 < t && j-1 >= 0 && j+1 < t) {
                    if (a[i+1][j-1] && a[i+1][j] && a[i+1][j+1] && a[i+2][j]) {
                        a[i][j] = 0;
                        a[i+1][j-1] = 0;
                        a[i+1][j] = 0;
                        a[i+1][j+1] = 0;
                        a[i+2][j] = 0;
                    } else {
                        cout << "NO" << endl;
                        return 0;
                    }
                } else {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}