#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>
#include <unistd.h>

void someFunction() {
    printf("Inside someFunction\n");
    return; // Exit the function
    printf("This line will not be executed\n");
}

int main() {
    printf("Start of main\n");
    someFunction();
    printf("End of main\n");
    return 0;
}