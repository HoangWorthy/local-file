#include <iostream>
using namespace std;
int a,b;
int main()
{
    cin >> a >> b;
    do
    {
        if (a > b) a-=b;
        else if (a < b) b-=a;
        if (a == b) cout << a;
    } while (a != b);
    return 0;
}