#include <iostream>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ )
    {
        int n;
        cin >> n;
        cin.ignore();
        do
        {
            char s;
            s = getchar();
            cout << s;
            while ( s != getchar());
        }
        while ( getchar() != '\n' );
        cout << endl;
    }
    return 0;
}