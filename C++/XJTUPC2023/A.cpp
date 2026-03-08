#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n <= 6)
    {
        cout << "water" << endl;
        return 0;
    }
    cout << "dry" << endl;
    return 0;
}