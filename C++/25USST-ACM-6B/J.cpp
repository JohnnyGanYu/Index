#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if ((a + b + c) % 2 != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    
    int x = (a + b - c) / 2;
    int y = (b + c - a) / 2;
    int z = (a + c - b) / 2;
    
    if (x >= 0 && y >= 0 && z >= 0) {
        cout << x << " " << y << " " << z << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}