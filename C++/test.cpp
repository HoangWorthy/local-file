#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("bai1.inp","r",stdin);
    freopen("bai1.out","w",stdout);
    string st,c,s; int k,a;
    k = 0;
    cin >> st >> c;
    while (st.size() < c.size()) st = '0' + st;
    while (st.size() > c.size()) c = '0' + c;
    for (int i = st.size()-1;i >= 0;i--) {
        a = (st[i] - '0') + (c[i] - '0') + k;
        k = a/10;
        s.append(to_string(a%10));
    }
    reverse(s.begin(),s.end());
    cout << s;
    return 0;
}