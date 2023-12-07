#include <bits/stdc++.h>

using namespace std;
const int o = 1e9+7;
const int N = 1005;
int n,m,g,h;
vector<int> d[N];
bool visit[N];
void bfs(int s,int x,int y){
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        int a = q.front();q.pop();
        for (auto i : d[a]){
            if (!visit[i] && i != x && i != y ) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}
int main()
{
    int k,c,l,f = 0;
    freopen("test.txt","r",stdin);
    freopen("test2.txt","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) visit[i] = false;
    for (int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        d[u].push_back(v);
        d[v].push_back(u);
    }
    for (int i = 1; i <= n;i++){
        if (!visit[i]) {
            bfs(i,0,0);
            k++;
        }
    }
    for (int i = 1;i <= n;i++){
        visit[i] = true;
        for (int j = 1; j <= n;j++){
            if (!visit[j]) {
                bfs(j,0,0);
                c++;
            }
        }
        for (int i = 1;i <= n;i++) visit[i] = false;
        if (c > k) l++;
        c = 0;
    }
    cout << l-1 << " ";
    l = 0;
    for (int i = 1;i <= n;i++){
        for (int j = 1; j <= n;j++){
            if (!visit[j]) {
                bfs(j,i,h);
                c++;
            }
        }
        for (int i = 1;i <= n;i++) visit[i] = false;
        if (c > k) l++;
        c = 0;
    }
    cout << l;
    return 0;
}
