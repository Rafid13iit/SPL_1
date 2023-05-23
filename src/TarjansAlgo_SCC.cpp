#include <header.h>
#include <globalVariable.h>

void tarjanDFS(int u, vector<vector<int>>& graph, vector<int>& discoveryTime, vector<int>& lowLink, vector<bool>& onStack, stack<int>& nodeStack, vector<vector<int>>& SCCs, int& time) {
    discoveryTime[u] = lowLink[u] = ++time;
    nodeStack.push(u);
    onStack[u] = true;

    for (int v : graph[u]) {
        if (discoveryTime[v] == -1) {
            tarjanDFS(v, graph, discoveryTime, lowLink, onStack, nodeStack, SCCs, time);
            lowLink[u] = min(lowLink[u], lowLink[v]);
        } 
        
        else if (onStack[v]) {
            lowLink[u] = min(lowLink[u], discoveryTime[v]);
        }
    }

    if (discoveryTime[u] == lowLink[u]) {
        vector<int> scc;
        while (true) {

            int v = nodeStack.top();
            nodeStack.pop();
            onStack[v] = false;
            scc.push_back(v);

            if (v == u) {
                break;
            }
        }

        SCCs.push_back(scc);

        cout << "HELLO";
    }
}

vector<vector<int>> tarjanSCC(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> discoveryTime(n, -1);
    /*the discovery time of each vertex during the Tarjan's algorithm. */

    vector<int> lowLink(n, -1);
    /*the Lowg-link value of a node is the smallest/lowest
    node id reachable from that node when doing a DFS (including itself)*/

    vector<bool> onStack(n, false);
    /*keeps track of whether a vertex is currently on the stack 
    during the Tarjan's algorithm*/

    stack<int> nodeStack;
    /*stores the vertices during the depth-first search traversal.*/

    vector<vector<int>> SCCs;
    /*vector of vectors that will store the strongly connected components found.*/

    int time = 0;
    /* keeps track of the discovery time during the algorithm.*/

    for (int i = 0; i < n; ++i) {
        if (discoveryTime[i] == -1) {
            tarjanDFS(i, graph, discoveryTime, lowLink, onStack, nodeStack, SCCs, time);
        }
    }
    cout << "HELLo";
    return SCCs;
}

void TarjansAlgo_SCC() {

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    int n, m;

    vector<vector<int>> graphForTarjans;

    cout << "HELLO";

    if (CHOOSE == 1){
        //for Fixed graphForTarjans
        n = directedFixed_NODES;
        m = directedFixed_EDGES;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (GRAPH[i][j] != 0){
                    graphForTarjans[i].push_back(j);
                }
            }
        }

    }

    else if (CHOOSE == 2){
        //for Random Input
        n = directedFixed_NODES;
        m = directedFixed_EDGES;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (GRAPH[i][j] != 0){
                    graphForTarjans[i].push_back(j);
                }
            }
        }

    }

    else {
        //for User Input
        n = directedFixed_NODES;
        m = directedFixed_EDGES;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (GRAPH[i][j] != 0){
                    graphForTarjans[i].push_back(j);
                }
            }
        }
    }

    vector<vector<int>> SCCs = tarjanSCC(graphForTarjans);

    cout << "Strongly Connected Components:" << endl;
    
    for (const auto& scc : SCCs) {
        for (int vertex : scc) {
            cout << vertex << " ";
        }
        cout << endl;
    }

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
Example - 01:

8
14
0 1
7 0
1 7
1 6
7 6
1 2
6 5 
5 6
2 5
2 3
3 2
3 4
5 4
4 4

Output:
4 
5 6 
3 2 
7 1 0

*/