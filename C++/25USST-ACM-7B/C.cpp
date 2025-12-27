#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        
        int j = i - 1;
        while (j >= 0 && h[j] <= h[j + 1]) {
            cnt++;
            j--;
        }
        
        j = i + 1;
        while (j < n && h[j] <= h[j - 1]) {
            cnt++;
            j++;
        }
        
        ans = max(ans, cnt);
    }
    
    cout << ans << endl;
    
    return 0;
}