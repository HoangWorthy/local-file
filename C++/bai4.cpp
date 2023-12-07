#include <bits/stdc++.h>
using namespace std;

void input(int &n) {
    cin >> n;
}

long long dequy(int n) {
    return (n == 0)? 1 : dequy(n-1) * pow(n,n);
}

void output(long long a) {
    cout << a;
}

int main () {
    freopen("bai4.inp","r",stdin);
    freopen("bai4.out","w",stdout); 
    int n;
    input(n);
    output(dequy(n));
    return 0;
}