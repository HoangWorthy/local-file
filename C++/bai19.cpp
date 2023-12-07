#include <iostream>
using namespace std;
int a,b,c;
int main()
{
    cin >> a >> b >> c;
    for (int i = 2; i < 30; i++) {
        if (a == i) a--;
        else if (a == 1 && b == 1) {a = 31;b = 12;c--;break;}
        else if (a == 1 && b == 3 && ((c % 4 == 0 && c % 100 != 0) || c % 400 == 0)) {a = 29;b--;break;}
        else if (a == 1 && b == 3) {a = 28;b--;break;}
        else if (a == 1 && (b == 1 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)) {a = 30;b--;break;}
        else if (a == 1 && (b == 4 || b == 6 || b == 9 || b == 11)) {a = 31;b--;break;}
    }
    printf("%d/%d/%d",a,b,c);
    return 0;
}