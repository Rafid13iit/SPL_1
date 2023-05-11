#include <header.h>
#include <globalVariable.h>


int vertex, edge;
int graph_G[MAX][MAX];
int cost[MAX][MAX];
int prevNodeIndex = 0;

//finds the vertex with minimum distance value,
//from the set of vertices not yet included in shortest path tree
int minDistance(int distance[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX;
    int min_index = -1;

	for (int i = 0; i < vertex; i++){
		if (sptSet[i] == false && distance[i] <= min){
			min = distance[i];

            prevNodeIndex = min_index;
            min_index = i;
        }
    }

    if (prevNodeIndex == -1) prevNodeIndex = 0;

	return min_index;
}

void printSolution(int src, int distance[])
{
    for (int i = 1; i < vertex; i++){
        if (distance[i] == INT_MAX) {
            cout << "There is no path from vertex " << src << " to vertex " << i << endl;
        }

        else{
            cout << "SoureVertex \t DestinationVertex \t Distance from Source" << endl;
            cout << "     " << src << " \t\t\t" << i << " \t\t\t" << distance[i] << endl;
        }
    }
}


void dijkstra(int src)
{
	int distance[vertex];

	bool sptSet[vertex]; //shortest path tree set

	// Initializes all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < vertex; i++){
		distance[i] = INT_MAX;
        sptSet[i] = false;
    }

	// Distance of source vertex from itself is always 0
	distance[src] = 0;

    // it finds shortest path for all vertices
    for (int count = 0; count < vertex-1; count++) {

	    int u = minDistance(distance, sptSet);

        if (CHOOSE == 1) fixedGraphConnection_1(prevNodeIndex, u); // for fixed graph
        else if (CHOOSE == 2) graphConnection(prevNodeIndex, u); // for random graph
        else graphConnection(prevNodeIndex, u); // for user input graph

        delay(2000);

        if (CHOOSE == 1) fixedNodeColor_3 (u); // for fixed graph
        else if (CHOOSE == 2) nodeColor_1 (u); //for random graph
        else nodeColor_1 (u); // for user input graph

        delay(2000);

		// Marking the picked vertex as processed
		sptSet[u] = true;

		// Updating distance value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < vertex; v++){

			if (!sptSet[v] && (graph_G[u][v] != 0) && (distance[u] != INT_MAX) && (distance[u] + cost[u][v] < distance[v])){
				
                distance[v] = distance[u] + cost[u][v];

                if (CHOOSE == 1) fixedGraphConnection(u, v); // for fixed graph
                else if (CHOOSE == 2) graphConnection(u, v); // for random graph
                else graphConnection(u, v); // for user input graph

                delay(500);

                if (CHOOSE == 1) fixedNodeColor_1 (v); // for fixed graph
                else if (CHOOSE == 2) nodeColor_1 (v); //for random graph
                else nodeColor_1 (v); // for user input graph

                delay(500);
            }
        }

        if (CHOOSE == 1) fixedNodeColor_2 (u); // for fixed graph
        else if (CHOOSE == 2) nodeColor_2 (u); //for random graph
        else nodeColor_2 (u); // for user input graph

        delay(2000);
    }

	printSolution(src, distance);
}


void Dijkstras_algorithm()
{
    // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "Dijkstras");
    
    // Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    memset(cost, INT_MAX, sizeof(cost));
    memset(graph_G, 0, sizeof(graph_G));
    
    int src;

    if (CHOOSE == 1){
        //for Fixed Graph
        vertex = fixed_NODES;
        edge = fixed_EDGES;
        
        for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){
                graph_G[i][j] = fixed_GRAPH[i][j];
                if (graph_G[i][j] != 0) cost[i][j] = graph_G[i][j];
            }
        }

        src = SOURCE;

    }

    else if (CHOOSE == 2){
        //for Random Input
        vertex = NODES;
        edge = EDGES;
        
        for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){
                graph_G[i][j] = GRAPH[i][j];
                if (graph_G[i][j] != 0) cost[i][j] = graph_G[i][j];
            }
        }

        src = SOURCE;

    }

    else {
        //for User Input
        vertex = NODES;
        edge = EDGES;
        
        for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){
                graph_G[i][j] = GRAPH[i][j];
                if (graph_G[i][j] != 0) cost[i][j] = graph_G[i][j];
            }
        }
        
        src = SOURCE;

    }

	// Function call
	dijkstra(src);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");

}

/*
6
9
0 1 14
0 2 9
0 5 7
1 3 8
1 2 2
2 4 11
2 5 10
3 4 6
4 5 15
0 4

the answer will be 20 for this case
*/
