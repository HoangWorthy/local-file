#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
void ucaseName(char a[])
{
    int i;
    toupper(a[0]);
    printf("%s",a);
}
int main()
{
    char a[] = {"xin chao"};
    ucaseName(a);
    return 0;
}