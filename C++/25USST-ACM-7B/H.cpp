#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> left, right;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'l') {
            right.push_back(i + 1);
        } else {
            left.push_back(i + 1);
        }
    }
    
    for (int x : left) {
        cout << x << endl;
    }
    
    for (int i = right.size() - 1; i >= 0; i--) {
        cout << right[i] << endl;
    }
    
    return 0;
}