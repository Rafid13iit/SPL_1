#include <header.h>
struct EdgesAndWeight{
    ll u, v, weight;
} edgesAndweight[MAX];

ll ParenT[MAX];
ll setRank[MAX] = {0};


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


ll kruskal (ll nodes, ll edges)
{
    for(ll i = 0; i < nodes; i++){
        makeSet(i);
    }

    ll answer = 0;

    for(ll i = 0; i < edges; i++)
    {
        ll u = edgesAndweight[i].u;
        ll v = edgesAndweight[i].v;
        ll w = edgesAndweight[i].weight;

        if(findParenT(u) != findParenT(v))
        {
            makeUnion(u, v);

            cout << "u -> v : " << u << "->" << v << ", weight = " << w << endl;

            answer += w;

            graphConnection(u, v);
            nodeColor_1(u);
            nodeColor_1(v);

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
    
    // Graph_FixedNodesAndEdges();

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

    freopen("graph_input.txt", "r", stdin);

    ll nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    ll adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph
    for (ll i = 0; i < nodes; i++) {
        for (ll j = 0; j < nodes; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    cout << "Enter edges (u v) and it's weight:\n";
    for (int i = 0; i < edges; i++) {
        cin >> edgesAndweight[i].u >> edgesAndweight[i].v >> edgesAndweight[i].weight;
        adj_matrix[edgesAndweight[i].u][edgesAndweight[i].v] = 1;
        adj_matrix[edgesAndweight[i].v][edgesAndweight[i].u] = 1; // Comment this line for directed graph
    }

    //sorting by weight
    struct EdgesAndWeight temp;

    for (ll i = 0; i < edges; i++){
        for (ll j = i + 1; j < edges; j++){
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
    
    cout << "MST cost is : " << kruskal(nodes, edges) << endl;

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