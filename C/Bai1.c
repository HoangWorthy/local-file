#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char** argv) {
    int l,i,j;
    char a[10];
    int c = 1;
    int u = 1;
    char y = 'Y';
    do {
                char q;
                int k,d;
                while(l == 0){
                    l = 1;
                    printf("Type a binary number you want to convert to decimal: ");
                    scanf("%s",&a);
                    int b = atoi(a);
                    if (atoi(a) == 0) {printf("wrong value"); break;}
                    while (b != 0){
                            k = b % 10;
                            if (k != 1 && k != 0) {
                                printf("Unable! Binary numbers only have 1 and 0\n");
                                l = 0;
                                break;
                            }
                            b = b /10;
                        d += k*pow(2,c);
                        c++;
                    }
                }
                if (u == 1) printf("%d is decimal number after convertion\n",d);
                l = 0;
                d = 0;
                k = 0;
                c = 0;
                u = 1;
                printf("Do you want to continue this function? (Y to continue)\n");
                scanf("%s",&q);
                y = q;
            }while(y == 'Y' || y == 'y');
}