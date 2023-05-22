#include <header.h>
#include <globalVariable.h>


int node_count, edge_count;
int source_node;

int graph[MAX][MAX];
char color[MAX];
int parent[MAX];

void DFS_algorithm(int node) { //'node' as an argument, which represents the node to be visited

    cout << "Visiting node " << node << endl;
    cout << "Parent array: [ ";

    for (int i = 0; i < node_count; ++i) {
        cout << parent[i] << " ";
    }

    cout << "]" << endl;
    cout << "Color array: [ ";

    for (int i = 0; i < node_count; ++i) {
        cout << color[i] << " ";
    }

    cout << "]" << endl;
    cout << "-----------------------------------------------" << endl;

    color[node] = 'g';

    if (CHOOSE == 1) fixedNodeColor_1 (node); // for fixed graph
    else if (CHOOSE == 2) nodeColor_1 (node); // for random graph
    else nodeColor_1 (node); // for user input graph

    delay(1500);

    //This loop iterates over all the nodes in the graph.
    for (int i = 0; i < node_count; ++i) {
        int adj = i;

        if (graph[node][adj] != 0 && color[adj] == 'w') {
            parent[adj] = node;

            if (CHOOSE == 1) fixedGraphConnection(i, node); // for fixed graph
            else if (CHOOSE == 2) graphConnection(i, node); // for random graph
            else graphConnection(i, node); // for user input graph

            DFS_algorithm(adj);
        }
    }

    color[node] = 'b';

    if (CHOOSE == 1) fixedNodeColor_2 (node); // for fixed graph
    else if (CHOOSE == 2) nodeColor_2 (node); //for random graph
    else nodeColor_2 (node); // for user input graph

    delay(1500);
}

void DFS()
    {
    // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "DFS");

    // Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    if (CHOOSE == 1){
        //for Fixed Graph
        node_count = fixed_NODES;
        edge_count = fixed_EDGES;
        
        for (int i = 0; i < node_count; i++){
            for (int j = 0; j < node_count; j++){
                graph[i][j] = fixed_GRAPH[i][j];
            }
        }

        source_node = fixed_SOURCE;
    }

    else if (CHOOSE == 2){
        //for Random
        node_count = NODES;
        edge_count = EDGES;
        
        for (int i = 0; i < node_count; i++){
            for (int j = 0; j < node_count; j++){
                graph[i][j] = GRAPH[i][j];
            }
        }

        source_node = SOURCE;

    }

    else {
        //for User Input
        node_count = NODES;
        edge_count = EDGES;
        
        for (int i = 0; i < node_count; i++){
            for (int j = 0; j < node_count; j++){
                graph[i][j] = GRAPH[i][j];
            }
        }

        source_node = SOURCE;
    }


    for (int i = 0; i < node_count; ++i) {
        color[i] = 'w';
        parent[i] = -1;
    }


    DFS_algorithm(source_node);
    parent[source_node] = -1;

    cout << "Final parent array: [ ";

    for (int i = 0; i < node_count; ++i) {
        cout << parent[i] << " ";
    }

    cout << "]" << endl;
    cout << "Final color array: [ ";

    for (int i = 0; i < node_count; ++i) {
        cout << color[i] << " ";
    }

    cout << "]" << endl;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");


    prevWindowArrow();

    int x = mousex();
    int y = mousey();
    if (ismouseclick(WM_LBUTTONDOWN)) {
        clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event
        if (x > 50 && x < 110 && y > 50 && y < 90) {
            // button was clicked
            cleardevice();
            delay(100);
            //getch();
            showList();
            //break;
        }
    } 

}

/*
7
10
0 1
1 2
2 3 
3 4
4 5
0 5
1 5
1 6
6 4
2 4
0
*/