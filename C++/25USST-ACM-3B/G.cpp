#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    long long forecast;
    long long present;
    long long date;
}weathers;

bool cmp1(weathers x, weathers y)
{
    return x.forecast > y.forecast;
}

bool cmp2(long long x, long long y)
{
    return x > y;
}

bool cmp3(weathers x, weathers y)
{
    return x.date < y.date;
}

int main(void)
{
    long long t;
    cin >> t;
    for ( long long i = 0; i < t; i++ )
    {
        long long n;
        cin >> n;
        cin.ignore(5,'\n');
        weathers weather[n];
        long long b[n];
        for( long long j = 0; j < n; j++)
        {
            cin >> weather[j].forecast;
            weather[j].date = j + 1;
        }
        sort(weather, weather+n, cmp1);
        for( long long j = 0; j < n; j++)
        {
            cin >> b[j];
        }
        sort(b, b+n, cmp2);
        for( long long j = 0; j < n; j++)
        {
            weather[j].present = b[j];
        }
        sort(weather, weather+n, cmp3);
        for( long long j = 0; j < n; j++)
        {
            cout << weather[j].present;
            if ( j < n - 1 )
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
