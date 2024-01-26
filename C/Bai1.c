#include <stdio.h>
 
int main()
{
    int a;
    int count = 0;
    do{
        scanf("%d",&a);
        count+=a;
    } while(a != 0);
    printf("The sum of inputed number is: %d",count);
    return 0;
}