#include <iostream>
#include <math.h>
#define speed (50.0)
#define timepp (1+0.5)
using namespace std;


int main(void)
{
    int n;
    cin >> n;
    float x, y;
    int people;
    float distance;
    float totalTime = 0;
    int time;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> people;
        distance = sqrt(x*x + y*y);
        totalTime += (people * timepp + 2 * (distance / speed));
        
    }

    time = ceil(totalTime);
    cout << time << endl;

    return 0;
}