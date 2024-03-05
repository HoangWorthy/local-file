#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>
#include <unistd.h>


int main() {
    char a[] = {"1"};
    char b[5],c[5];
    sscanf(a,"%[0-9]-%[0-9]",b,c);
    printf("%s-%s",b,c);
}