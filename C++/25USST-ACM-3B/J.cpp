#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    long long n, m;
    double p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=sqrtl (n);
        if (m*m==n)m--;
        cout << m << endl;
    }

    return 0;
}