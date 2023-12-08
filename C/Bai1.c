#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	float a,b,c,d,x1,x2;
    scanf("%f\n%f\n%f",&a,&b,&c);
    if (a == 0) {
        printf("x = %f",-c/b);
        exit(0);
    }
    int delta = (b*b)- 4*a*c;
    if (delta > 0) {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("x1 = %f\nx2 =%f",x1,x2);
    }
    else if (delta == 0) {
        x1 = -b /(2*a);
        printf("x1 = x2 = %f",x1);
    }
    else printf("Phuong trinh vo nghiem");
	return 0;
}