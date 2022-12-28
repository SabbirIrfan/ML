// C++ program for solution of M
// Coloring problem using backtracking

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4


bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;

	return true;
}

bool issafee(int v, int c , bool graph[V][V], int color[]){
    for(int i =0; i<V; i++){
        if(graph[v][i] && c == color[i]){
            return false;
        }

    }
    return true;

}
/* A recursive utility function
to solve m coloring problem */

bool graphColoringUtil(bool graph[V][V], int m, int color[],
					int v)
{

	///* base case: If all vertices are colored */
	if (v == V)
		return true;

	///* Consider this vertex v and
	/// try different colors */ v can be a vertex or a node from a linked list
	for(int c = 1; c<=m; c++){
        if(issafee(v,c,graph,color)){
            color[v] = c;/// this coloring is not final
                        /// we have check if this color
                        /// with a recursion if other node are satified

            if(graphColoringUtil(graph,m,color,v+1) == true){
                return true;
            }
            else /// VIP ///
                color[v] = 0; /// backtreacking used here -->> color[v] =0
                            /// because this color assignment contradicting
                            /// with other node which we found after recuring the if above

        }

	}


	/* If no color can be assigned to
	this vertex then return false */
	return false;
}


bool graphColoring(bool graph[V][V], int m)
{

	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	// Print the solution
	///printSolution(color);
	return true;
}


// Driver code
int main()
{


	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};

	// Number of colors
	int m = 3;

	// Function call
	if(graphColoring(graph, m))
        cout<<"M Colorable"<<endl;
    else
        cout<<"NOT M Colorable"<<endl;
	return 0;
}


