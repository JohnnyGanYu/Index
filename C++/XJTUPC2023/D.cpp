#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, x, y, maxx = 0, maxy = 0, minx = 0, miny = 0;
    cin >> n;
    vector<vector<int>> b(201,vector<int>(201, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        b[x+100][y+100] = 1;
        if (x < minx) 
        {
            minx = x;
        }if (x > maxx) 
        {
            maxx = x;
        }if (y < miny) 
        {
            miny = y;
        }if (y > maxy) 
        {
            maxy = y;
        }
        
    }
    if (b[100][100] == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = minx; i <= maxx; i++)
    {
        for (int j = miny; j <= maxy; j++)
        {
            if (b[i+100][j+100] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
            
        }
    }
    cout << maxx+maxy-minx-miny << endl;
    return 0;
}