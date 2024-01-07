#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void thaya(int a[]){
    a[1] = 10;
}

int main(int argc, char** argv) {
	int a[5] = {1,2,3,4,5};
    thaya(a);
    printf("%d",a[1]);
	return 0;
}