#include <bits/stdc++.h>
using namespace std;
// bool comp(string a, string b){   
//    return (a+b) > (b+a);
// }
int main() {
    freopen("bai2.inp","r",stdin);
    freopen("bai2.out","w",stdout);
    string A[100];int k;
    k = 0;
    while (getline(cin,A[k])) k++;
    //sort(A,A+k,comp);
    for (int i = 0;i < k;i++) {
        for (int j = i + 1;j < k-1;j++) {
            if (A[j] + A[i] < A[i] + A[j]) swap(A[j],A[i]);
        }
    }
    reverse(A,A+k);
    for (int i = 0;i < k;i++) cout << A[i];
    return 0;
}