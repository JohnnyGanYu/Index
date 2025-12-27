#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<string> groups;
    
    int i = 0;
    while (i < n) {
        if (n - i == 2) {
            groups.push_back(s.substr(i, 2));
            i += 2;
        } else if (n - i == 3) {
            groups.push_back(s.substr(i, 3));
            i += 3;
        } else if (n - i == 4) {
            groups.push_back(s.substr(i, 2));
            groups.push_back(s.substr(i + 2, 2));
            i += 4;
        } else {
            groups.push_back(s.substr(i, 3));
            i += 3;
        }
    }
    
    for (int i = 0; i < groups.size(); i++) {
        if (i > 0) cout << "-";
        cout << groups[i];
    }
    cout << endl;
    
    return 0;
}