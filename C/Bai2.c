#include <stdio.h>

int main() {
    int num;
    char ch;

    printf("Enter a number: ");
    scanf("%d", &num);

    // The newline character from the previous input is still in the buffer
    printf("Enter a character: ");
    scanf("%c", &ch);  // Notice the space before %c, which skips leading whitespace

    printf("You entered: %d and %c\n", num, ch);

    return 0;
}
