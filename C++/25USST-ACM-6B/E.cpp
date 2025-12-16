#include <iostream>
using namespace std;

int main(void) {
    int n;
    string s;
    cin >> n >> s;
    
    int result = 0;
    int temp = 0;
    bool p = 1;
    
    for (int i = 0; i < n; i++) {
        if ( s[i] == '.' ) {
            temp++;
        }
        else if ( s[i] == 'R' ) {
            result += temp;
            temp = 0;
            p = 0;
        }
        else {
            if ( temp % 2 && i != temp ) {
                result++;
            }
            temp = 0;
            p = 1;
        }
    }
    if (p) {
        result += temp;
    }
    cout << result << endl;
    return 0;
}