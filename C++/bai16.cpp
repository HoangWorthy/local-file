#include <iostream>
#include <math.h>
using namespace std;
int a,b,c;
int main() 
{
    cin >> a >> b >> c;
    int delta = b*b - 4*a*c;
    double x1 = (-b + sqrt(delta)) / (2*a);
    double x2 = (-b - sqrt(delta)) / (2*a);
    double kep = -b/(2*a);
    if ( delta > 0) printf("Phuong trinh co 2 nghiem:\nx1 = %.2f\nx2 = %.2f",x1,x2);
    else if (delta == 0) printf("Phuong trinh co nghiem kep:\nx1 = x2 = %.2f",kep);
    else cout << "Phuong trinh vo nghiem";
}