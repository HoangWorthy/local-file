#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    string a[] = {"","mot","hai","ba","bon","nam","sau","bay","tam","chin"};
    for (int i = 1; i < 10; i++) {
        if (n / 10 == i && i == 1) {cout << "muoi ";break;}
        else if (n / 10 == i) {printf("%s muoi ",a[i].c_str());break;}
    }
    for (int i = 1; i < 10; i++) {
        if (n % 10 == i && i != 5) {printf("%s",a[i].c_str());break;}
        else if (n % 10 == i) {cout << "lam";break;}
    }
    return 0;
}