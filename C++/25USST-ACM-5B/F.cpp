#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x, int y) {
    return (x>y);
}

int main(void) {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> b[j];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        
        int left_a = 0, right_a = n - 1;
        int left_b = 0, right_b = m - 1;
        long long diff = 0;
        
        while (left_a <= right_a) {
            long long diff_left = abs(a[left_a] - b[left_b]);
            long long diff_right = abs(a[right_a] - b[right_b]);
            
            if (diff_left > diff_right) {
                diff += diff_left;
                left_a++;
                left_b++;
            } else {
                diff += diff_right;
                right_a--;
                right_b--;
            }
        }
        
        cout << diff << "\n";
    }
    
    return 0;
}