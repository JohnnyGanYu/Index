#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int m;
        cin >> m;
        
        while (m--) {
            string s;
            cin >> s;
            
            if (s.length() != n) {
                cout << "NO\n";
                continue;
            }
            
            unordered_map<long long, char> num_to_char;
            unordered_map<char, long long> char_to_num;
            bool ok = true;
            
            for (int i = 0; i < n; i++) {
                auto it_num = num_to_char.find(a[i]);
                auto it_char = char_to_num.find(s[i]);
                
                if (it_num != num_to_char.end()) {
                    if (it_num->second != s[i]) {
                        ok = false;
                        break;
                    }
                }
                else if (it_char != char_to_num.end()) {
                    if (it_char->second != a[i]) {
                        ok = false;
                        break;
                    }
                }
                else {
                    num_to_char[a[i]] = s[i];
                    char_to_num[s[i]] = a[i];
                }
            }
            
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    
    return 0;
}