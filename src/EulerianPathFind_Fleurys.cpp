#include <header.h>
#include <globalVariable.h>

// Function to find the starting vertex
int findStartVertex(vector<vector<int>>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) //graph[i][j] == 1
                deg++;
        }
        if (deg % 2 != 0)
            return i;
    }
    return 0;
}

// Depth-first search
int dfs(vector<vector<int>>& graph, int prev, int start, vector<bool>& visited) {
    int count = 1;
    visited[start] = true;
    int n = graph.size();
    for (int u = 0; u < n; u++) {
        if (prev != u && !visited[u] && graph[start][u] != 0) {
            count += dfs(graph, start, u, visited);
        }
    }
    return count;
}

// Check if an edge is a bridge
bool isBridge(vector<vector<int>>& graph, int u, int v) {
    int deg = 0;
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        if (graph[v][i] != 0)
            deg++;
    }
    if (deg > 1)
        return false;
    return true;
}

// Fleury's algorithm
void fleuryAlgorithm(vector<vector<int>>& graph, int start) {
    int edge = 0;
    int v_count = graph.size();
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0)
                edge++;
        }
    }
    vector<bool> visited(n, false);
    for (int v = 0; v < n; v++) {
        if (graph[start][v] != 0) {
            vector<bool> visited(n, false);
            if (isBridge(graph, start, v))
                v_count--;
            int cnt = dfs(graph, start, v, visited);
            if (cnt - v_count <= 2) {
                cout << "Edge: " << start << " -> " << v << endl;

                if (CHOOSE == 1) fixedNodeColor_1 (start); // for fixed graph
                else if (CHOOSE == 2) nodeColor_1 (start); //for random graph
                else nodeColor_1 (start); // for user input graph
                delay(500);

                if (CHOOSE == 1) fixedGraphConnection(start, v); // for fixed graph
                else if (CHOOSE == 2) graphConnection(start, v); // for random graph
                else graphConnection(start, v); // for user input graph
                delay(500);

                if (CHOOSE == 1) fixedNodeColor_1 (v); // for fixed graph
                else if (CHOOSE == 2) nodeColor_1 (v); //for random graph
                else nodeColor_1 (v); // for user input graph
                delay(500);

                if (isBridge(graph, v, start))
                    v_count--;
                graph[start][v] = graph[v][start] = 0;
                edge--;
                fleuryAlgorithm(graph, v);
            }
        }
    }
}

void EulerianPathFind_Fleurys() {

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    int n, m;
    vector<vector<int>> graphForEulerPathFind(MAX, vector<int>(MAX, 0));
    
    if (CHOOSE == 1){
        //for Fixed Graph
        n = fixed_NODES;
        m = fixed_EDGES;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                graphForEulerPathFind[i][j] = graphForEulerPathFind[j][i] = fixed_GRAPH[i][j];
            }
        }

    }

    else if (CHOOSE == 2){
        //for Random Input
        n = NODES;
        m = EDGES;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                graphForEulerPathFind[i][j] = graphForEulerPathFind[j][i] = GRAPH[i][j];
            }
        }

    }

    else {
        //for User Input
        n = NODES;
        m = EDGES;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                graphForEulerPathFind[i][j] = graphForEulerPathFind[j][i] = GRAPH[i][j];
            }
        }

    }

    


    int startVertex = findStartVertex(graphForEulerPathFind);

    cout << "Euler Path:" << endl;
    fleuryAlgorithm(graphForEulerPathFind, startVertex);


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
