#include <iostream>
using namespace std;

int main(void)
{
    float distance;
    float bikeTime;
    float walkTime;

    cin >> distance;

    bikeTime = 27 + distance/3.0 + 23;
    walkTime = distance / 1.2;

    if (bikeTime - walkTime > 1e-6)
    {
        cout << "Walk" << endl;
    }
    else if (bikeTime - walkTime < -1e-6)
    {
        cout << "Bike" << endl;
    }
    else
    {
        cout << "All" << endl;
    }

    return 0;
}