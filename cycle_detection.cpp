#include <iostream>
using namespace std;

int n,m,u,v,w,cycle = 0;
int edge[1005][1005],vis[1005];
void DFS(int u)
{
    if(vis[u] == 1)
        return;
    vis[u] = 1;
    for(int v=0; v<n; v++)
    {
        if(edge[u][v])
        {
            if(vis[v] == 0)
                DFS(v);
            else if(vis[v] == 1)
                cycle = 1;
        }
    }
    vis[u] = 2;
}
int main()
{
// int test;
// cin >> test;
    while(1)
    {
        cin >> n >> m;
        for(int i=0; i<m; i++)
        {
            w = 1;
            cin >> u >> v;
            edge[u][v] = w;
// edge[v][u] = w;
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
                DFS(i);
        }
        if(cycle)
            cout << "1" <<endl;
        else
            cout << "0" <<endl;

        cycle = 0;
        for(int i=0; i<1005; i++)
        {
            for(int j=0; j<1005; j++)
            {
                edge[i][j] = 0;
                vis[j] = 0;
            }
        }
        break;

    }
    return 0;
}

