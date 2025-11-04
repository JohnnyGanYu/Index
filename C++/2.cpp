#include <iostream>
using namespace std;

int count(int lastNum,const int leftNum,const int n)
{
    int cnt = 0;
    if (leftNum == 0)
    {
        return 1;
    }
    int i = (leftNum + n - 1) / n;
    while (i <= lastNum && i <= leftNum)
    {
        int left = leftNum - i;
        cnt += count(i, left, n-1);
        i++;
    }

    return cnt;
}

int main(void)
{
    int m, n, r;
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> m;
        cin >> n;
        cout << count(m, m, n) << endl;
    }

    return 0;
}