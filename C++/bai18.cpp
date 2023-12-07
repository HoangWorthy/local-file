#include <iostream>
using namespace std;
int a,b,c;
int main()
{
    cin >> a >> b >> c;
    for (int i = 1; i < 28; i++) 
    if (a == i && a != 28 && a != 29) {a++;break;}
    else if (a == 31 &&  (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10)) {a = 1;b++;}
    else if (a == 31 &&  b == 12) {a = 1;b = 1;c++;}
    else if (a == 30 &&  (b == 4 || b == 6 || b == 9 || b == 11)) {a = 1;b++;}
    else if (a == 29 && b == 2 && ((c % 4 == 0 && c % 100 != 0) || c % 400 == 0)) {a = 1;b++;}
    else if (a == 28 && b == 2) {a = 1;b++;}
    printf("%d/%d/%d",a,b,c);
    return 0;
}