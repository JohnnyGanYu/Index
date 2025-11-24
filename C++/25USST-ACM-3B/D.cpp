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
        char s;
        while ( (s = getchar()) != '\n' )
        {
            cout << s;
            while ( s != getchar());
        }
        
        cout << endl;
    }
    return 0;
}