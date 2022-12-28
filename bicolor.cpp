// C++ program to find out whether a
// given graph is Bipartite or not
#include <iostream>
#include <queue>
#define V 4

using namespace std;


bool isBipartite(vector<vector<int>> &G, int src)
{

	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	colorArr[src] = 1;

	// Create a queue (FIFO) of vertex

	queue <int> q;
	q.push(src);

	// Run while there are vertices
	// in queue (Similar to BFS)
	while (!q.empty())
	{
		// Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
		int u = q.front();
		q.pop();

		// Return false if there is a self-loop
		if (G[u][u] == 1)
		return false;

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v)
		{
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1)
			{
				// Assign alternate color to this adjacent v of u
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent
	// vertices can be colored with alternate color
	return true;
}

// Driver program to test above function
int main()
{
	vector<vector<int>> G;
	int v ,e;
	cin>>v>>e;
	G.assign(v+1,vector<int>(v+1,0));
    for(int i=0; i<e; i++){
            int a,b;
        cin>>a>>b;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    for(int i=0; i<v; i++){
        for(int j =0; j<v; j++){
            cout<< G[i][j]<<" ";
        }
        puts("");
    }
	isBipartite(G, 0) ? cout << "Yes" : cout << "No";
	return 0;
}
