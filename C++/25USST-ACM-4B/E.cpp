#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int temp = 0;
        bool beautiful = true;
        for (int i = 1; i < n; i++){
            if (a[i] % a[0] != 0 && temp == 0){
                temp = a[i];
            }
            else {
                if (a[i] % a[0] != 0 && a[i] % temp != 0){
                    beautiful = false;
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if (beautiful){
            cout << "Yes" << endl;
        }
        
    }
    
    return 0;
}