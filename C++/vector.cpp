#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*int m,n,A[100][100];
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> A[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << A[i][j];
    }*/
    vector<int> A;int n,c;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> c;
        A.push_back(c);
    }
   for (int i = 0;i < A.size();i++) cout << A[i];
    return 0;
}