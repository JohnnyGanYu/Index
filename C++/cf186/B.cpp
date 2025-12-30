#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    const int MAXN = 20;
    vector<long long> odd(MAXN + 1), even(MAXN + 1);

    for (int n = 1; n <= MAXN; n++) {
        int o = (n + 1) / 2;
        int e = n / 2;

        if (o > 0)
            odd[n] = ((1LL << (2 * o)) - 1) / 3; 
        if (e > 0)
            even[n] = 2 * ((1LL << (2 * e)) - 1) / 3;
    }
    
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = 1;
        
        for (int n = MAXN; n >= 1; n--) {
            if ((odd[n] <= a && even[n] <= b) || (even[n] <= a && odd[n] <= b)) {
                ans = n;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}