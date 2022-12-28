#include <iostream>
using namespace std;
#define inf 1e9
int find_min(int dist[],int visited[],int n){
    int node=-1;
    int val=inf;
    for(int i=0;i<2*n+2;i++){
        if(dist[i]!=inf && !visited[i] && dist[i]<val){
            node = i;
            val =dist[i];
        }
    }
    return node;
}
int dijkstra(int graph[][101],int n){
    int visited[2*n+2];
    int dist[2*n+2];
    for(int i=0;i<2*n+2;i++){
        dist[i]=inf;
        visited[i]=0;
    }
    dist[0]=0;
    for(int i=0;i<2*n+1;i++){
        int u = find_min(dist,visited,n);
        visited[u]=1;
        for(int v=0;v<2*n+2;v++){
            if(!visited[v] && dist[u]!=inf && graph[u][v]!=-1 && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    return dist[1];
}
int main() {
    int t;cin>>t;
    while(t--){
        int graph[101][101];
        int n;cin>>n;
        int x[2*n+2],y[2*n+2];
        for(int i=0;i<2*n+2;i++){
            for(int j=0;j<2*n+2;j++){
                graph[i][j]=-1;
            }
        }
        for(int i=0;i<2;i++){
            cin>>x[i]>>y[i];
        }
        for(int i=2;i<2*n+2;i+=2){
            int cost;
            cin>>x[i]>>y[i]>>x[i+1]>>y[i+1]>>cost;
            graph[i][i+1]=cost;
            graph[i+1][i]=cost;
        }
        for(int i=0;i<2*n+2;i++){
            for(int j=i+1;j<2*n+2;j++){
                if(i%2==0 && i>=2){
                    if(j==i+1) continue;
                }
                graph[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
                graph[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            }
        }
        cout<<dijkstra(graph,n)<<endl;
    }
    return 0;
}
