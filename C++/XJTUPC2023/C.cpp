#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x, y, z;
    cin >> x >> y >> z;
    
    cout << fixed << setprecision(6) << z/x/y << endl;
    return 0;
}