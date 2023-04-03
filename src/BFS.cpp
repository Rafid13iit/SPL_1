#include <header.h>

#define MAX 6

int Graph[MAX][MAX];
char Color[MAX]; //to keep track of the Color of each node.
int Level[MAX]; //to keep track of the Level of each node.
int Parent[MAX]; //to keep track of the Parent node of each node.

void BFS()
{
    int edgeCount;
    cout << "Enter the number of edges: ";
    cin >> edgeCount;

    cout << "Enter the edges (u v) in the Graph: " << endl;
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;

        Graph[u][v] = 1;
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    //step-1
    for (int i = 0; i < MAX; ++i) {
        Color[i] = 'w';
        Level[i] = 99999999;
        Parent[i] = -1;
    }

    //step-2
    int queue[MAX];
    int start, end;

    start = 0;
    end = 0;
    queue[end] = sourceNode;
    end++;

    Color[sourceNode] = 'g';
    Level[sourceNode] = 0;
    Parent[sourceNode] = -1;


    while (end - start > 0) { //continues until the queue is empty.
        int u = queue[start];

        for (int i = 0; i < MAX; ++i) {
            int v = i;

            if (Graph[u][v] == 1 && Color[v] == 'w') {

                queue[end] = v;
                end++;
                Color[v] = 'g';
                Level[v] = Level[u] + 1;
                Parent[v] = u;
            }
        }

        start++;
        Color[u] = 'b';
    }

    cout << "Level, Parent and Color of each node:" << endl;
    for (int i = 0; i < MAX; ++i) {

        cout << "Level[" << i << "] = " << Level[i] << endl;
        cout << "Parent[" << i << "] = " << Parent[i] << endl;
        cout << "Color[" << i << "] = " << Color[i] << endl;
        cout << endl;
    }
    
}


/*
6
5 2
5 1
5 3
1 3
1 4
4 2
5
*/