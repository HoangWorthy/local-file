#include <iostream>
using namespace std;
int main() 
{
    int m,n;
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) cout << "* ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0;i < n;i++) cout << "*" ;
    cout << endl;
    for (int i = 0;i < m-2;i++) {
        for (int j = 0;j < n;j++) {
            if (j == 0 || j == n-1) cout << "*";
            else cout << ' ';
        }
        cout << endl;
    }
    for (int i = 0;i < n;i++) cout << "*";
    return 0; 
}