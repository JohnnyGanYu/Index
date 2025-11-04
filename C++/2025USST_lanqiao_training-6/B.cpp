#include <iostream>
using namespace std;

int main(void)
{
    int a1;
    int a2;
    int n;

    cin >> a1 >> a2 >> n;
    cout << a1 + (a2-a1) * (n-1) <<endl;

    return 0;
}