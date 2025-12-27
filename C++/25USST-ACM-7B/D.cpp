#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n;
    cin >> n;
    
    vector<string> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    vector<string> candidates;
    
    for (const string& page : pages) {
        if (page.find(s) == 0) {
            candidates.push_back(page);
        }
    }
    
    if (candidates.empty()) {
        cout << s << endl;
    } else {
        sort(candidates.begin(), candidates.end());
        cout << candidates[0] << endl;
    }
    
    return 0;
}