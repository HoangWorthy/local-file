#include <iostream>
using namespace std;
float a,b,c,x;
int main()
{
    cin >> a >> b >> c;
    if (a > b) {
        x = a;
        a = b;
        b = x;
    }
    if (a > c) {
        x = a;
        a = c;
        c = x;
    }
    if (b > c) {
        x = b;
        b = c;
        c = x;
    }
    printf("%.2f %.2f %.2f",a,b,c);
    return 0;
}