#include <iostream>
using namespace std;

bool check(int d, int m, int y)
{
    int time[10] = {0}, num = 0;
    while (y != 0)
    {
        time[y % 10]++;
        y /= 10;
    }
    while (d != 0)
    {
        time[d % 10]++;
        d /= 10;
    }
    while (m != 0)
    {
        time[m % 10]++;
        m /= 10;
    }
    for (int i = 0; i < 10; ++i)
    {
        if (time[i] == 0)
            continue;
        if (num != 0 && time[i] != num)
        {
            return false;
        }
        num = time[i];
    }
    return true;
}

int main()
{
    int d = 9, m = 9, y = 2239;
    int dd[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long cnt = 0;
    for (; y < 9876; d++)
    {
        if (d > dd[m])
        {
            d = 1;
            m++;
        }
        if (!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
        {
            if (m == 2 && d > 28)
            {
                d = 1;
                m++;
            }
        }
        if (m > 12)
        {
            m = 1;
            y++;
        }
        if (check(d, m, y))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}