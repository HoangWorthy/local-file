#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,max1,max2,a,b,c,e,f,max3;
    cin >> n;
    cin >> m;
    int A[n][m],do_lon[100];
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            cin >> A[i][j];
        }
    }
    max1 = 1;
    max2 = 1;
    c = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (A[i][j] == 1) {a = i;b = j+1;e=i+1;f=j;
                while (A[a][b] == 1) {max1++;b++;}
                while (A[e][f] == 1) {max2++;e++;}
                do_lon[c] = max1*max2;
                max1 = 1;
                max2 = 1;
                c++;
            }
        }
    }
    max3 = do_lon[0];
    for (int i = 0;i < c;i++){
        if (max3 < do_lon[i]) {max3 = do_lon[i];}
    }
    cout << max3;
    return 0;
}