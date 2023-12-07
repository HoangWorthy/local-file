#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
bool songuyento(int n) {
    if (n == 1) return false;
    for (int i = 2; i <= sqrt(n)+1; i++)
    if (n % i == 0) return false;
    return true;
}
using namespace std;
int main()
{
    freopen("SEARCH.inp","r",stdin);
    freopen("SEARCH.out","w",stdout);
    int m,n,c[100];int r = 0;
    string k;
    vector<int> A;
    cin >> m >> n;
    FOR(i,m,n+1) {
        k = to_string(i);
        reverse(k.begin(),k.end());
        c[r] = stoi(k);
        r++;
    }
    r = 0;
    FOR(i,m,n+1) {
        if (songuyento(c[r])) A.push_back(i);
        r++;
    }
    for (auto i = A.begin();i != A.end();i++) {
        if (i != A.begin()) cout << "\n";
        cout << *i;
    }
    return 0;
}
