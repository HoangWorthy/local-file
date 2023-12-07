#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main() 
{
    freopen("MAX.inp","r",stdin);
    freopen("MAX.out","w",stdout);
    int m,n,max;
    cin >> m >> n;
    int A[m][n];
    FOR(i,0,m)
    FOR(j,0,n)
    cin >> A[i][j];
    max = A[0][0];
    FOR(i,0,m) {
        FOR(j,0,n) if (max < A[i][j]) max = A[i][j];
    }
    cout << max;
    return 0;
}