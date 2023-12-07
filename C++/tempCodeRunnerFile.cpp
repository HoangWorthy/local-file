#include <bits/stdc++.h>
using namespace std;
void xoamang (string n, int k) {
    for(int i = k; i < n.length()-1;i++) {
        n[i] = n[i+1];
    }
    n.pop_back();
}
int main() {
    string n;
    int k,c,min,cc;
    cin >> n >> k;
    c,min,cc = 0;
    do {
        for (int i = 0;i < n.length();i++) {
            if (min > stoi(&n[i])) {min = stoi(&n[i]);cc=i;};
        }
        xoamang(n,cc);
        c++;

    } while(c < k);
    cout << n;
}