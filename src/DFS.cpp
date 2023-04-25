#include <header.h>


int node_count, edge_count;

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
    nodeColor_1 (node);
    delay(1500);

    //This loop iterates over all the nodes in the graph.
    for (int i = 0; i < node_count; ++i) {
        int adj = i;

        if (graph[node][adj] == 1 && color[adj] == 'w') {
            parent[adj] = node;
            graphConnection(i, node);
            DFS_algorithm(adj);
        }
    }

    color[node] = 'b';
    nodeColor_2 (node);
    delay(1500);
}

void DFS()
{
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    outtextxy(400, 30, "DFS");

    Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    freopen("graph_input_BFS_DFS.txt", "r", stdin);

    cout << "Enter the number of nodes in the graph: ";
    cin >> node_count;
    cout << "Enter the number of edges in the graph: ";
    cin >> edge_count;

    cout << "Enter the edges in the format 'u v': " << endl;
    for (int i = 0; i < edge_count; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < node_count; ++i) {
        color[i] = 'w';
        parent[i] = -1;
    }

    int source_node;
    cout << "Enter the source node: ";
    cin >> source_node;

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