#include <header.h>
#include <globalVariable.h>

//for User Iput & Randomly created graphs
int NODES, EDGES;
int U, V, WEIGHT;
int GRAPH[MAX][MAX];
int SOURCE = 0;
int CHOOSE = 0;

int x[MAX], y[MAX];

//for Fixed Graph
int fixed_NODES, fixed_EDGES;
int fixed_U, fixed_V, fixed_WEIGHT;
int fixed_GRAPH[MAX][MAX];
int fixed_SOURCE = 0;


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
