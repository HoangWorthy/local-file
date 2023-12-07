#include <iostream>
using namespace std;
int a,b,c,x;
int main()
{
    cin >> a >> b >> c;
        for (int i = 1; i <= 12; i++) {
            if (i == 2 || i == 4 || i == 6 || i == 8 || i == 9 || i == 11) x+=31;
            else if (i == 5 || i == 7 || i == 10 || i == 12) x+=30;
            else if (((c % 4 == 0 && c % 100 != 0) || c % 400 == 0) && i == 3) x+=29;
            else if (!((c % 4 == 0 && c % 100 != 0) || c % 400 == 0) && i == 3) x+=28;
            if (b == i) {x+=a;break;}
        }
    printf("Ngay thu %d trong nam",x);
    return 0;
}