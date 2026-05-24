#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <climits>
#include <iomanip>
using namespace std;

bool maps[105][105] = {false};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        maps[x][y] = 1;
    }
    int cnt = 0;
    int adj = 0;
    for (int x = 1; x <= 99; ++x)
    {
        for (int y = 1; y <= 99; ++y)
        {
            if (maps[x][y])
            {
                cnt++;
                if (x + 1 <= 99 && maps[x + 1][y])
                {
                    adj++;
                }
                if (y + 1 <= 99 && maps[x][y + 1])
                {
                    adj++;
                }
            }
        }
    }
    double area = cnt * 2.0 - adj * 0.5;
    cout << area << endl;
    return 0;
}