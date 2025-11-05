#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int x;
    int y;

    cin >> n >> x >> y;
    cout << n - (y-1)/x - 1;
    return 0;
}