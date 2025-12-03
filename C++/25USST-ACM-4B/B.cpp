#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                ans = s.substr(i, 2);
                break;
            }
        }
        if (ans.empty()) {
            for (int i = 0; i < n - 2; ++i) {
                char a = s[i], b = s[i + 1], c = s[i + 2];
                if (a != b && a != c && b != c) {
                    ans = s.substr(i, 3);
                    break;
                }
            }
        }
        if (ans.empty()) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }
    
    return 0;
}