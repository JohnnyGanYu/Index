#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int start = 10000000 - n + 1;
    
    for (int i = 0; i < n; i++) {
        cout << start + i;
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}