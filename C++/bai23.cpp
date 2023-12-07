#include <iostream>
#include <math.h>
int x,y;
using namespace std;
int luythua(int x, int y) {return pow(x,y);}
int main()
{
    cin >> x >> y;
    cout << "S = " << luythua(x,y);
    return 0;
}