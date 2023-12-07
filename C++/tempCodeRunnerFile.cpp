#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int A[n],L[n];
    for (int i = 0;i < n;i++){
        cin >> A[i];
    }
    for (int i = 0;i < n;i++){
        L[i] = i+1;
    }
    for(int i = 1;i < n;i++){
        for (int j = 0; j < i; j++){
            if ((A[j] > A[i]) || (A[j] < A[j-1])) L[i]--;
        }
    }
    int max = L[0];
    for (int i = 1;i < n;i++){
        if (max < L[i]) max = L[i];
    }
    cout << max;
    return 0;
}