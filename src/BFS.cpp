#include <header.h>
#include <globalVariable.h>


int Graph[MAX][MAX];
char Color[MAX]; //to keep track of the Color of each node.
int Level[MAX]; //to keep track of the Level of each node.
int Parent[MAX]; //to keep track of the Parent node of each node.

void BFS()
{
    // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "BFS");

    //Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    int nodeCount, edgeCount;
    int sourceNode;

    if (CHOOSE == 1){
        //for Fixed Graph
        nodeCount = fixed_NODES;
        edgeCount = fixed_EDGES;
        
        for (int i = 0; i < nodeCount; i++){
            for (int j = 0; j < nodeCount; j++){
                Graph[i][j] = fixed_GRAPH[i][j];
            }
        }

        sourceNode = fixed_SOURCE;
    }

    else if (CHOOSE == 2){

        //Later...

    }

    else {
        //for User Input
        cout << "SHUT UP" << endl;
        nodeCount = NODES;
        edgeCount = EDGES;
        
        for (int i = 0; i < nodeCount; i++){
            for (int j = 0; j < nodeCount; j++){
                Graph[i][j] = GRAPH[i][j];
            }
        }

        sourceNode = SOURCE;
    }
    
    

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

    if (CHOOSE == 1) fixedNodeColor_1 (sourceNode); //for fixed graph
    else if (CHOOSE == 2) ;//LATER
    else nodeColor_1 (sourceNode); // for use input graph
    
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

                if (CHOOSE == 1) fixedGraphConnection(u, v); // for fixed graph
                else if (CHOOSE == 2) ;//LATER
                else graphConnection(u, v); // for user input graph

                if (CHOOSE == 1) fixedNodeColor_1 (v); // for fixed graph
                else if (CHOOSE == 2) ;//LATER
                else nodeColor_1 (v); // for user input graph
                
                delay(1500);

                Level[v] = Level[u] + 1;
                Parent[v] = u;
            }
        }

        start++;
        Color[u] = 'b';

        if (CHOOSE == 1) fixedNodeColor_2 (u); // for fixed graph
        else if (CHOOSE == 2) ;//LATER
        else nodeColor_2 (u); // for user input graph

        delay(1500);
    }

    cout << "Level, Parent and Color of each node:" << endl;
    for (int i = 0; i < nodeCount; ++i) {

        cout << "Level[" << i << "] = " << Level[i] << endl;
        cout << "Parent[" << i << "] = " << Parent[i] << endl;
        cout << "Color[" << i << "] = " << Color[i] << endl;
        cout << endl;
    }

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");
    
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