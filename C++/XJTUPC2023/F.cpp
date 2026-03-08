#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int i = 0;
    while (++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if ((v == 2 && (a[u] == 1 || a[u] == 3)) || (a[u] == 2 && (v == 1 || v == 3)))
        {
            if (i % 2 == 0) {
                cout << "Sheauhaw" << endl;
            }
            else {
                cout << "Nocriz" << endl;
            }
            return 0;
        }
        a[u] = v;
    }
    return 0;
}