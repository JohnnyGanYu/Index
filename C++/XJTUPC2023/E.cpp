#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--)
    {
        int n, mode = 1;
        double b;
        cin >> n >> b;
        if (n == 1) {
            cout << "kono jinsei, imi ga nai!" << endl;
            cin >> b;
            continue;
        }
        vector<vector<double>> a(n,vector<double>(n));
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            double max = -4.0;
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] > max && i != j)
                {
                    c[i] = j;
                    max = a[i][j];
                }
                
            }
            if (a[i][c[i]] < b || i == c[i]) {
                mode = 2;
            }
            //sort(a[i].begin(), a[i].end());
        }
        
        if (mode == 2) {
            cout << "hbxql" << endl;
            continue;
        }
    
        sort(c.begin(), c.end());
        for (int i = 0; i < n; i++)
        {

            if (c[i] != i) {
                mode = 2;
                break;
            }
            
        }
        
        if (mode == 2) {
            cout << "hbxql" << endl;
        }
        else {
            cout << "wish you the best in your search" << endl;
        }

    }
    
    return 0;
}