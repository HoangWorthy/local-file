#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    int a,d;
    int k;
    int c = 0 ;
    int p = 0;
	 printf("Type a binary number you want to convert to decimal: ");
   				 scanf("%d",&a);
    			while (a != 0){
        				k = a % 10;
                        printf("%d\n",k);
        				if (k != 1 && k != 0) {
            			    p = 1;
           			         break;
      					  }
        				a = a / 10;
       				 d += k*pow(2,c);
        			c++;
    }
    if (p == 0) printf("%d is decimal number after convertion\n",d);
    else printf("asda");
}