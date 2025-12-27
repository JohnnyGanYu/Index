#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    
    long long prefix = 0;
    int ways = 0;
    
    for (int i = 0; i < n - 1; i++) {
        prefix += arr[i];
        if (prefix == total - prefix) {
            ways++;
        }
    }
    
    cout << ways << endl;
    
    return 0;
}