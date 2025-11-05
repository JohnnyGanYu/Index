#include <iostream>
using namespace std;

int main(void)
{
    int fortune;
    int encouragement;

    cin >> fortune >> encouragement;
    if (fortune >= 10 || encouragement >= 20)
    {
        cout << 1 << endl; 
    }
    else
    {
        cout << 0 <<endl;
    }

    return 0;
}