#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 99 && i != 5 && i!= 7 && i != 93; i+=2) if (i != 5|| i != 7 || i != 93) cout << i;
    return 0;
}