#include <iostream>

using namespace std;

int main(void) {

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        
        char s[n];
        for (int i = 0; i < n ; i++) {
            cin >> s[i];
        }
        
        bool a = false, b = true;

        for (int i = 0; i < n-3 ; i++) {
            if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2') {
                if (s[i+3] == '5') {
                    b = false;
                } else if (s[i+3] == '6') {
                    a = true;
                }
            }
        }
        
        if (a || b) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}