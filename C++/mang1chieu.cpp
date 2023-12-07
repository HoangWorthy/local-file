#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sort.inp","r",stdin); //r = read
    freopen("sort.out","w",stdout); //w = write
    int n;
    cin >> n;
    int A[n]; //A[5] = [5,4,3,7,8]
    for (int i = 0;i < n;i++) cin >> A[i]; //Nhập vào mảng
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) 
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]); //Đổi chỗ phần tử
    }
    for (int i = 0;i < n;i++) cout << A[i]; 
    return 0;
}