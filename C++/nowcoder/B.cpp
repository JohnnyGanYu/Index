#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, min = 2e6, cnt = 0;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (min > b[i]) {
                min = b[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (min > a[i]) {
                cnt++;
            }
        }
        int qian, hou;
        qian = cnt;
        hou = n - cnt;
        int  ans = 1;
        while (qian != 0) {
            ans *= qian;
            qian--;
        } 
        while (hou != 0) {
            ans *= hou;
            hou--;
        } 
        cout << ans << endl;
        
    }
    return 0;
}