#include <header.h>
#include <globalVariable.h>
struct EdgesAndWeight{
    ll u, v, weight;
} edgesAndweight[MAX];

ll ParenT[MAX];
ll setRank[MAX] = {0};

ll nodes_K, edges_K;
ll adj_matrix[MAX][MAX]; // Adjacency matrix to store the graph


//Disjoint Set starts
void makeSet(int x)
{
    ParenT[x] = x;
}

ll findParenT (ll x)
{
    if (x != ParenT[x]){
        return ParenT[x] = findParenT(ParenT[x]);
    }
    else{
        return x;
    }
}

void makeUnion (ll u, ll v)
{
    ll uP = findParenT(u);
    ll vP = findParenT(v);

    if (uP == vP) return ;

    if (setRank[uP] < setRank[vP]){
        ParenT[uP] = vP;
    }
    else if (setRank[uP] > setRank[vP]){
        ParenT[vP] = uP;
    }
    else {
        ParenT[vP] = uP;
        setRank[uP]++;
    }

}
//Disjoint Set ends


ll kruskal (ll nodes_K, ll edges_K)
{
    for(ll i = 0; i < nodes_K; i++){
        makeSet(i);
    }

    ll answer = 0;

    for(ll i = 0; i < edges_K; i++)
    {
        ll u = edgesAndweight[i].u;
        ll v = edgesAndweight[i].v;
        ll w = edgesAndweight[i].weight;

        if(findParenT(u) != findParenT(v))
        {
            makeUnion(u, v);

            cout << "u -> v : " << u << "->" << v << ", weight = " << w << endl;

            answer += w;

            if (CHOOSE == 1) fixedGraphConnection(u, v); // for fixed graph
            else if (CHOOSE == 2) graphConnection(u, v); //for random graph
            else graphConnection(u, v); // for user input graph
            
            if (CHOOSE == 1) fixedNodeColor_1 (u); // for fixed graph
            else if (CHOOSE == 2) nodeColor_1 (u); //for random graph
            else nodeColor_1 (u); // for user input graph

            if (CHOOSE == 1) fixedNodeColor_1 (v); // for fixed graph
            else if (CHOOSE == 2) nodeColor_1 (v); // for random graph
            else nodeColor_1 (v); // for user input graph

            delay(1000);
        }
        //else nothing to do, just skip the edge pair
    }

    return answer;
}

void MST_Kruskals_Algorithm ()
{
    // settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "Kruskals");
    
    // Graph_Fixednodes_K_KAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    if (CHOOSE == 1){
        //for Fixed Graph
        nodes_K = fixed_NODES;
        edges_K = fixed_EDGES;
        
        for (int i = 0; i < nodes_K; i++){
            for (int j = 0; j < nodes_K; j++){
                adj_matrix[i][j] = fixed_GRAPH[i][j];
            }
        }
        

        int k = 0;
        for (int i = 1; i < nodes_K; i++){
            for (int j = 0; j < i; j++){

                if (adj_matrix[i][j] != 0){
                    edgesAndweight[k].u = i;
                    edgesAndweight[k].v = j;
                    edgesAndweight[k].weight = adj_matrix[i][j];

                    k++;
                }
            }
        }

    }

    else if (CHOOSE == 2){
        //for Random Input
        nodes_K = NODES;
        edges_K = EDGES;
        
        for (int i = 0; i < nodes_K; i++){
            for (int j = 0; j < nodes_K; j++){
                adj_matrix[i][j] = GRAPH[i][j];
            }
        }
        

        int k = 0;
        for (int i = 1; i < nodes_K; i++){
            for (int j = 0; j < i; j++){

                if (adj_matrix[i][j] != 0){
                    edgesAndweight[k].u = i;
                    edgesAndweight[k].v = j;
                    edgesAndweight[k].weight = adj_matrix[i][j];

                    k++;
                }
            }
        }

    }

    else {
        //for User Input
        nodes_K = NODES;
        edges_K = EDGES;
        
        for (int i = 0; i < nodes_K; i++){
            for (int j = 0; j < nodes_K; j++){
                adj_matrix[i][j] = GRAPH[i][j];
            }
        }
        

        int k = 0;
        for (int i = 1; i < nodes_K; i++){
            for (int j = 0; j < i; j++){

                if (adj_matrix[i][j] != 0){
                    edgesAndweight[k].u = i;
                    edgesAndweight[k].v = j;
                    edgesAndweight[k].weight = adj_matrix[i][j];

                    k++;
                }
            }
        }

    }

    //sorting by weight
    struct EdgesAndWeight temp;

    for (ll i = 0; i < edges_K; i++){
        for (ll j = i + 1; j < edges_K; j++){
            if (edgesAndweight[i].weight > edgesAndweight[j].weight){

                temp = edgesAndweight[i];
                edgesAndweight[i] = edgesAndweight[j];
                edgesAndweight[j] = temp;
            }
        }
    }

    // for (int i = 0; i < edges; i++) {
    //     cout << edgesAndweight[i].weight << " " << edgesAndweight[i].u << " " << edgesAndweight[i].v << endl;
    // }
    
    cout << "MST cost is : " << kruskal(nodes_K, edges_K) << endl;

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
0 1 5
1 2 4
2 3 3 
3 4 2
4 5 3
0 5 1
1 5 2
1 6 6
6 4 5
2 4 4
*/