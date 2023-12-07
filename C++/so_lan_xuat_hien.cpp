#include <iostream>
using namespace std;
int main()
{
    freopen("so_lan_xuat_hien.inp","r",stdin);
    freopen("so_lan_xuat_hien.out","w",stdout);
    int n; int x; int dem;
    cin >> n >> x;
    if (n <= 100000) {
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= 1000000000) exit;
        if (a[i] == x ) dem++;
    }
    cout << dem;
    return 0;
    }
}