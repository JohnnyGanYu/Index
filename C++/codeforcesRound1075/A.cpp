#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--)
    {
        int n, h, l;
        cin >> n >> h >> l;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        int cnt1 = 0, cnt2 = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= h) {
                cnt1++;
            }
            if (a[i] <= l) {
                cnt2++;
            }
            
        }
        if (cnt1>=2*cnt2||cnt2>=2*cnt1)
        {
            cout << min(cnt1,cnt2);
        }
        else cout << max(cnt1,cnt2)/2;
        cout << endl;
    }
    
}