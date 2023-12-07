#include <bits/stdc++.h>
using namespace std;
const int o = 0;
const int N = 1005;
#define X first
#define Y second
typedef pair <int, int> ii;
typedef vector <ii> Vii;

int n,m;
Vii a[N];
int d[N];
void dijkstra (int st) {
    priority_queue <ii , Vii , greater<ii>> q;
    for( int i = 1; i <= n; i++) d[i] = 0;
    d[st] = 0;
    q.push({0,st});
    while(q.size())
    {
        int u = q.top().Y;
        int du = q.top().X;
        q.pop();

        if (du != d[u]) continue;

        for (int i = 0; i < a[u].size();i++){
            int v = a[u][i].Y;
            int dv = a[u][i].X;
            if (d[v] > du + dv) {
                d[v] = du + dv;
                q.push({d[v],v});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u ,v , w;
        cin >> u >> v >> w;
        a[v].push_back({w,u});
        a[u].push_back({w,v});
    }
    return 0;
}