#include <header.h>


int Graph[MAX][MAX];
char Color[MAX]; //to keep track of the Color of each node.
int Level[MAX]; //to keep track of the Level of each node.
int Parent[MAX]; //to keep track of the Parent node of each node.

void BFS()
{
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    outtextxy(400, 30, "BFS");

    Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    freopen("graph_input_BFS_DFS.txt", "r", stdin);

    int nodeCount, edgeCount;

    cout << "Enter the number of nodes: ";
    cin >> nodeCount;
    cout << "Enter the number of edges: ";
    cin >> edgeCount;

    cout << "Enter the edges (u v) in the Graph: " << endl;
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;

        Graph[u][v] = 1;
        Graph[v][u] = 1;
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    //step-1
    for (int i = 0; i < nodeCount; ++i) {
        Color[i] = 'w';
        Level[i] = 99999999;
        Parent[i] = -1;
    }

    //step-2
    int queue[nodeCount];
    int start, end;

    start = 0;
    end = 0;
    queue[end] = sourceNode;
    end++;

    Color[sourceNode] = 'g';
    nodeColor_1 (sourceNode);
    delay(1500);
    Level[sourceNode] = 0;
    Parent[sourceNode] = -1;


    while (end - start > 0) { //continues until the queue is empty.
        int u = queue[start];

        for (int i = 0; i < nodeCount; ++i) {
            int v = i;

            if (Graph[u][v] == 1 && Color[v] == 'w') {

                queue[end] = v;
                end++;
                Color[v] = 'g';
                graphConnection(u, v);
                nodeColor_1 (v);
                delay(1500);
                Level[v] = Level[u] + 1;
                Parent[v] = u;
            }
        }

        start++;
        Color[u] = 'b';
        nodeColor_2 (u);
        delay(1500);
    }

    cout << "Level, Parent and Color of each node:" << endl;
    for (int i = 0; i < nodeCount; ++i) {

        cout << "Level[" << i << "] = " << Level[i] << endl;
        cout << "Parent[" << i << "] = " << Parent[i] << endl;
        cout << "Color[" << i << "] = " << Color[i] << endl;
        cout << endl;
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