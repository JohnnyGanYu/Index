#include <iostream>
using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a-b)*c-1)/b+1 << endl;
    return 0;
}