#include <iostream>
using namespace std;

int main()
{
    long long ans = 0;
    int i = 1;
    int t = 901234;
    while (i++, t--)
    {
        int date = 789456 + (i - 1) * 567890;
        int past = (date - 654321) / 876543 + 1;
        if (past >= 500001 || i > 901234)
            ans += 500001 - past;
    }
    cout << ans << endl;
    return 0;
}