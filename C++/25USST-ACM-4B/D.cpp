#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        bool same = true;
        bool reverse = true;
        for (int i = 0; i < n; i++){
            if ((a[i] != b[i]) && same){
                same = false;
            }
            if ((a[i] != b[n-i-1]) && reverse){
                reverse = false;
            }
            if ((same||reverse) == false){
                break;
            }
        }
        if ((same||reverse) == false){
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }

    }
}