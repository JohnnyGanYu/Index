#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    vector<int> b(k);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i%k] += a[i];
    }

    auto minIt = min_element(b.begin(), b.end());
    int minIndex = distance(b.begin(), minIt);

    cout << minIndex + 1 <<endl;
    return 0;

}