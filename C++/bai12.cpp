#include <iostream>
#include <math.h>
using namespace std;
int n,c;
int main()
{
    cin >> n;
    for (int i = 2; i <= trunc(sqrt(n)); i++) {
        if (n % i == 0) cout << "false"; 
        else cout << "true";
    }
    return 0;
}