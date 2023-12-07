#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
const int o = 1e9+7;
#define X first
#define Y second
typedef pair<int,int> ii;
typedef vector<ii> Vii;
int m,n,s;
Vii adj[N];

void dijkstra(int s){
    priority_queue<ii ,Vii, greater<ii>> pq;
    vector<int> d(n+1,o);
    d[s] = 0;
    pq.push({s,0});
    while(!pq.empty()){
        int x = pq.top().X;
        int y = pq.top().Y;
        pq.pop();

        if (y > d[x]) continue;

        for(auto i : adj[x]){
            int v = i.X;
            int w = i.Y;
            if (d[v] > d[x] + w){
                d[v] = d[x] + w;
                pq.push({v,d[v]});
            }
        }
    }
    cout << d[5];
}

int main()
{
    freopen("test.txt","r",stdin);
    freopen("test2.txt","w",stdout);
    cin >> n >> m >> s;;
    for(int i = 0; i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(s);
    return 0;
}
