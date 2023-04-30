#include <header.h>
#include <globalVariable.h>

//for User Iput & Randomly created graphs
int NODES, EDGES;
int U, V, WEIGHT;
int GRAPH[MAX][MAX];
int SOURCE = 0;
int CHOOSE = 0;

//for Fixed Graph
int fixed_NODES, fixed_EDGES;
int fixed_U, fixed_V, fixed_WEIGHT;
int fixed_GRAPH[MAX][MAX];
int fixed_SOURCE = 0;

int main ()
{
    openGraphicalWindow();

    Graphics_Graph(); 

    //Graph_FixedNodesAndEdges();
    //MST_Kruskals_Algorithm ();
    //MST_Prims_Algorithm ();
    //Dijkstras_algorithm();
    // BFS();
    // DFS();
    //VF2_graph_isomorphism();
    //A_star_algorithm();
    //graphConstruction();
    //graphConsUsingGraphicalWindow();
    //graphRandomConstruction();
    //randomGraphConsUsingGraphicalWindow ();
 

    return 0;
}
