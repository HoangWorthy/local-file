#include <iostream>
using namespace std;
int n,a;
int main()
{
    do {
        n++;
        a += n;
    } while (a <= 10000);
    cout << n;
    return 0;
}