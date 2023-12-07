#include <bits/stdc++.h>
using namespace std;
bool tamgiac(int a, int b, int c) {
    if (a+b > c || a+c > b || b+c > a) return true;
    else return false;
}
bool tamgiaccan(int a, int b, int c) {
    if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a)) return true;
    else return false;
}
bool tamgiacvuongcan(int a, int b, int c) {
    if ((a == b || a == c || b == c) && ((pow(a,2) + pow(b,2) ==pow(c,2)) || (pow(a,2)+pow(c,2)==pow(b,2)) || (pow(b,2)+pow(c,2)==pow(a,2)))) return true;
    else return false;
}
bool tamgiacdeu(int a, int b, int c) {
    if (a==b && a==c) return true;
    else return false;
}
bool tamgiacvuong(int a, int b, int c) {
    if ((a*a +b*b ==c*c) || (a*a+c*c==b*b) || (b*b+c*c==a*a) && !(a == b || a == c || b == c)) return true;
    else return false;
}
int main()
{
    int a; int b; int c;
    cin >> a >> b >> c;
    if (tamgiac(a,b,c)) {
        cout << "3 canh nay tao nen mot tam giac\n";
        if (tamgiaccan(a,b,c)) cout << "tam giac nay la tam giac can";
        else if (tamgiacdeu(a,b,c)) cout << "tam giac nay la tam giac deu";
        else if (tamgiacvuongcan(a,b,c)) cout << "tam giac nay la tam giac vuong can";
        else if (tamgiacvuong(a,b,c)) cout << "tam giac nay la tam giac vuong";
    }
    else cout << "3 canh nay khong tao nen mot tam giac";
}