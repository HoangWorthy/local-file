#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int i,j;
	char o;
    do {
        printf("##############################################################\n");
        printf("#                                                            #\n");
        printf("#                                                            #\n");
        printf("#                       Hoang's program                      #\n");
        printf("#                                                            #\n");
        printf("#                                                            #\n");
        printf("##############################################################\n");
        printf("What my program will do:\n");
        printf("1. Convert binary numbers to decimal\n2. Convert decimal numbers to binary\n3. Create a Multiplication Table from 1 to 9\n4. Count the Number of Digits in an Integer\n5. Reverse an Integer.\n6. Exit...\n");
        printf("Choose one of above options: ");
        scanf("%s",&o);
        system("cls");
        switch(o){
            case '1':{
                char y = 'y';
                int l = 0;
                int k,d = 0;
                int c = 0;
                char q;
            do {
                char a[20];
                while(l == 0){
                    l = 1;
                    printf("Type a binary number you want to convert to decimal: ");
                    scanf("%s",&a);
                    while(atoi(a) == 0) {
                        printf("Wrong input!\n");
                        printf("Type a binary number you want to convert to decimal: ");
                        scanf("%s",&a);
                    }
                    int b = atoi(a);
                    while (b != 0){
                            k = b % 10;
                            if (k != 1 && k != 0) {
                                printf("Unable! Binary numbers only have 1 and 0\n");
                                l = 0;
                                break;
                            }
                            b = b / 10;
                        d += k*pow(2,c);
                        c++;
                    }
                }
                printf("%d is decimal number after convertion\n",d);
                l = 0;
                d = 0;
                k = 0;
                c = 0;
                printf("Do you want to continue this function? (Type Y to continue or random word to exit)\n");
                scanf("%s",&q);
                y = q;
            }while(y == 'Y' || y == 'y');
            break;
            }
            case '2':{
                int k = 0;
                int c = 0;
                int g = 1;
                    char a[20];
                   char y = 'y';
                y = 'Y';
                while (y == 'y' || y == 'Y'){
             		printf("Type a decimal number you want to convert to binary: ");
                    scanf("%s",&a);
                    while(atoi(a) == 0) {
                        printf("Wrong input!\n");
                        printf("Type a decimal number you want to convert to binary: ");
                        scanf("%s",&a);
                    }
                    int b = atoi(a);
                     while(b != 0){
                        k = b % 2;
                        c = c + ( k * g);
                        g = g * 10;
                        b /= 2;
    }
    printf("The binary number is: %d",c);
    printf("\n");
    c = 0;
    g = 1;
    printf("Do you want to continue this function? (Type Y to continue or random word to exit)\n");
                scanf("%s",&y);
                }
    break;
        }  
            case '3':{
                char y = 'y';
                while(y == 'Y' || y == 'y'){
                 int i,j;
    				printf("This is your multiplication table in matrix form: ");
   				 for(i = 1;i < 10;i++){
   			     printf("\n");
       			 for(j = 1; j < 10; j++){
           			 printf("%d\t",i*j);
       			 }
   					 }
   				 printf("\n");
                 printf("Do you want to continue this function? (Type Y to continue or random word to exit)\n");
                scanf("%s",&y);
                }
                break;
			}
            case '4':{
                char a[20];
                int c = 0;
                   char y = 'y';
                while(y == 'Y' || y == 'y'){
                printf("Type the number you want to count the number of digits: ");
                    scanf("%s",&a);
                    while(atoi(a) == 0) {
                        printf("Wrong input!\n");
                        printf("Type the number you want to count the number of digits: ");
                        scanf("%s",&a);
                    }
                    int b = atoi(a);
                while(b!=0){
                b /= 10;
                c++;
                }
                printf("This number has %d digits\n",c);
                printf("Do you want to continue this function? (Type Y to continue or random word to exit)\n");
                scanf("%s",&y);
                c = 0;
                }
                break;
            }
            case '5':{
                char a[20];
                   char y = 'y';
                while(y == 'Y' || y == 'y'){
   				 printf("Type the number you want to reverse: ");
  				  scanf("%s",&a);
                  while(atoi(a) == 0) {
                        printf("Wrong input!\n");
                        printf("Type the number you want to reverse: ");
                        scanf("%s",&a);
                    }
                    int b = atoi(a);
   				 printf("The reversion of it is: ");
   				 while(b!=0){
       			 printf("%d",b%10);
        		b/=10;
   				 }
  				  printf("\n");
                  printf("Do you want to continue this function? (Type Y to continue or random word to exit)\n");
                scanf("%s",&y);
                }
                break;
            }
            case '6':{
                exit(1);
                break;
            }
            default:
                printf("Invalid option\n");
        }
        system("cls");
    } while(true);
    return 0;
}
