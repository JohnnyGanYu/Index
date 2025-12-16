#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    int minute = (s[3] - '0') * 10 + (s[4] - '0');
    
    while (true) {
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) hour = 0;
        }

        int h1 = hour / 10, h2 = hour % 10;
        int m1 = minute / 10, m2 = minute % 10;
        
        if (h1 == m2 && h2 == m1) {
            if (hour < 10) cout << "0";
            cout << hour << ":";
            if (minute < 10) cout << "0";
            cout << minute << endl;
            break;
        }
    }
    
    return 0;
}