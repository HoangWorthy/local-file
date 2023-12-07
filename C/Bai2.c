#include <stdio.h>
#include <math.h>

int checkperfect(int n){
    int a=1;
    int i;
    for ( i = 2;i < n;i++){
        if (n%i==0) a=a+i;
    }
    return a;
}

int main(int argc, char** argv) {
    int i;
	for (i = 6;i < 1000;i++){
        if (checkperfect(i) == i) printf("%d\n",i);
    }
	return 0;
}