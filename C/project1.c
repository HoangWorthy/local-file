#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void bitode(){
    int a,k,d;
    int c = 0;
    bool bol = true;
    printf("Type a binary number you want to convert to decimal: ");
    scanf("%d",&a);
    while (a != 0){
        k = a % 10;
        if (k != 1 || k != 0) {
            bol = false;
            break;
        }
        a = a / 10;
        d += k*pow(2,c);
        c++;
    }
    if (bol) printf("%d is decimal number after convertion\n",d);
    else printf("Unable! Binary numbers only have 1 and 0\n");
}
void detobi(){
    int a,b[100],i;
    int c = 0;
    printf("Type a decimal number you want to convert to binary: ");
    scanf("%d",&a);
    while(a != 0){
        b[c] = a % 2;
        a /= 2;
        c++;
    }
    printf("The binary number is: ");
    for(i = c-1; i >= 0; i--){
        printf("%d",b[i]);
    }
}

void Mtable(){
    int i,j;
    printf("This is your multiplication table in matrix form: ");
    for(i = 1;i < 10;i++){
        printf("\n");
        for(j = 1; j < 10; j++){
            printf("%d\t",i*j);
        }
    }
    printf("\n");
}

void countdigit(){
    int a;
    int c = 0;
    printf("Type the number you want to count the number of digits: ");
    scanf("%d",&a);
    while(a!=0){
        a /= 10;
        c++;
    }
    printf("This number has %d digits\n",c);
}

void reverseint(){
    int a;
    printf("Type the number you want to reverse: ");
    scanf("%d",&a);
    printf("The reversion of it is: ");
    while(a!=0){
        printf("%d",a%10);
        a/=10;
    }
    printf("\n");
}

int main() {
	char o = 'Y';
    while(o == 'Y'|| o == 'y'){
        printf("##############################################################\n");
        printf("#                                                            #\n");
        printf("#                                                            #\n");
        printf("#                       Hoang's program                      #\n");
        printf("#                                                            #\n");
        printf("#                                                            #\n");
        printf("##############################################################\n");
        printf("What my program will do:\n");
        printf("1. Convert binary numbers to decimal\n2. Convert decimal numbers to binary\n3. Create a Multiplication Table from 1 to 9\n4. Count the Number of Digits in an Integer\n5. Reverse an Integer.\n");
        printf("Choose one of above options: ");
        scanf("%d",&o);
        system("cls");
        switch(o){
            case 1:
                bitode();
                break;
            case 2:
                detobi();
                break;
            case 3:
                Mtable();
                break;
            case 4:
                countdigit();
                break;
            case 5:
                reverseint();
                break;
            default:
                printf("There's no option %d on the list\n",o);
        }
        printf("Do you want to choose other options? (Y or N)\n");
        scanf("%s",&o);
        system("cls");
    }
    return 0;
}