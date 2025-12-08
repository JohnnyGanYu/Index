#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(m);
        vector<int> q(k);
        vector<bool> f(n+1, 0);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> q[i];
            f[q[i]] = 1;
        }
        if ( n == k ) {
            while (m--) {
                cout << 1;
            }
        }
        else if ( n > k + 1 ) {
            while (m--) {
                cout << 0;
            }
        }
        else {
            for (int i = 0; i < m; i++)
            {
                if (f[a[i]]) {
                    cout << 0;
                }
                else {
                    cout << 1;
                }
            }
            
        }
        cout << "\n";
    }   
}