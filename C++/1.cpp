#include <iostream>
using namespace std;

template<class T>
void swap2(T &a, T &b) 
{
   T temp = a;
   a = b;
   b = temp;
}
int main() 
{
   int a = 1, b = 2;
   swap2(a, b);
   cout << a << " " << b << endl; 
   return 0;
}


