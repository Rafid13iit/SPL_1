#include <header.h>
#include <globalVariable.h>

//for User Iput & Randomly created graphs
int NODES, EDGES;
int U, V, WEIGHT;
int GRAPH[MAX][MAX];
int SOURCE = 0;
int CHOOSE = 0;

int x[MAX], y[MAX];
int prevNodeIndex[MAX];

//for Fixed Graph
int fixed_NODES, fixed_EDGES;
int fixed_U, fixed_V, fixed_WEIGHT;
int fixed_GRAPH[MAX][MAX];
int fixed_SOURCE = 0;

int fixed_NODES_2, fixed_EDGES_2;
int fixed_GRAPH_2[MAX][MAX];
int fixed_SOURCE_2 = 0;

//for Directed Fixed Graph
int directedFixed_NODES, directedFixed_EDGES;
int directedFixed_U, directedFixed_V, directedFixed_WEIGHT;
int directedFixed_GRAPH[MAX][MAX];
int directedFixed_SOURCE = 0;

int COUNT = 0;


int main ()
{
    openGraphicalWindow();

    Graphics_MENU(); 

    //Graph_FixedNodesAndEdges();
    //MST_Kruskals_Algorithm ();
    //MST_Prims_Algorithm ();
    //Dijkstras_algorithm();
    // BFS();
    // DFS();
    //VF2_graph_isomorphism();
    //A_star_algorithm();
    //Weighted_GraphConstruction();
    //UserInput_GraphConstruction();
    //Random_GraphConstruction();

    return 0;
}
