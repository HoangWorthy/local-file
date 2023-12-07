#include <bits/stdc++.h>
using namespace std;
string n,dem;
int count;
bool kt;
int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);

    while (getline(cin,n))
    {
        n=n+" ";
        kt=0;
        dem="";
        for (int i = 0; i < n.length(); i++)
        {
            kt=0;
            dem = dem + n[i];
            if (n[i+1] == ' ')
            {   
                i++;
                kt=1;
                int s = stoi(dem);
                dem = "";
                if (s == 1) continue;
                for (int j = 2; j <= sqrt(s); j++) 
                    if (s % j == 0) {kt=0;break;}
            }
            if (kt==1) {break;}
        }
        if (kt==1) {cout<<1<<"\n";}
        else cout<<0<<"\n";

    }
    return 0;
}