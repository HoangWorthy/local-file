#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main() 
{
    freopen("SORT.inp","r",stdin);
    freopen("SORT.out","w",stdout);
    int m,n;
    cin >> m >> n;
    int A[m][n];
    FOR(i,0,m)
    FOR(j,0,n)
    cin >> A[i][j];
    sort(A[0],A[m]);
    FOR(i,0,m) {
        FOR(j,0,n)  {
                cout << A[i][j];
                if (j != n-1) cout << " ";
            }
        if (i != m-1) cout << "\n";
    }
    return 0;
}