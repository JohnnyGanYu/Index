#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if ( s[i] == '4' ) {
            a++;
        }
        else if ( s[i] == '7' ) {
            b++;
        }
    }
    if ( a==0 && b==0) {
        cout << -1 << endl;
        return 0;
    }
    cout << ( (a<b) ? 7 : 4 ) << endl;
    return 0;
}