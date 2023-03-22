#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
#define MX 100

typedef long long int ll;
typedef unsigned long long int llu;

struct EdgesAndWeight{
    ll u, v, weight;
} edgesAndweight[MX];

ll parent[MX];
ll setRank[MX] = {0};


//Disjoint Set starts
void makeSet(int x)
{
    parent[x] = x;
}

ll findParent (ll x)
{
    if (x != parent[x]){
        return parent[x] = findParent(parent[x]);
    }
    else{
        return x;
    }
}

void makeUnion (ll u, ll v)
{
    ll uP = findParent(u);
    ll vP = findParent(v);

    if (uP == vP) return ;

    if (setRank[uP] < setRank[vP]){
        parent[uP] = vP;
    }
    else if (setRank[uP] > setRank[vP]){
        parent[vP] = uP;
    }
    else {
        parent[vP] = uP;
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

        if(findParent(u) != findParent(v))
        {
            makeUnion(u, v);

            answer += w;
        }
        //else nothing to do, just skip the edge pair
    }

    return answer;
}

int main ()
{
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

  // Initialize graphics window
  initwindow(800, 600, "Graph");

  // Draw nodes as circles with numbers
  int radius = 20;
  int x[nodes], y[nodes];

  settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
  for (int i = 0; i < nodes; i++) {
    x[i] = (i+1) * (800 / (nodes+1));
    y[i] = rand() % 400 + 100;
    circle(x[i], y[i], radius);
    string label = to_string(i);
    outtextxy(x[i]-radius/2, y[i]-radius/2, const_cast<char*>(label.c_str()));
  }

  // Wait for a delay before proceeding to the next step
  delay(5000);

  // Draw edges as lines with weights
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
for (int i = 0; i < nodes; i++) {
  for (int j = i+1; j < nodes; j++) {
    if (adj_matrix[i][j] == 1) {
      line(x[i], y[i], x[j], y[j]);

      // Calculate position for the weight label
      int mid_x = (x[i] + x[j]) / 2 + 10;
      int mid_y = (y[i] + y[j]) / 2 + 20;

      // Draw the weight label
      string edgeWeight = to_string(edgesAndweight[j].weight); // Replace 1 with the actual weight of the edge
      outtextxy(mid_x-10, mid_y-20, const_cast<char*>(edgeWeight.c_str()));

      delay(2000);
    }
  }
}


  // Wait for user to close the window
  getch();

  // Close the graphics window
  closegraph();

    // for (int i = 0; i < edges; i++) {
    //     cout << edgesAndweight[i].weight << " " << edgesAndweight[i].u << " " << edgesAndweight[i].v << endl;
    // }
    
    cout << "MST cost is : " << kruskal(nodes, edges) << endl;

    return 0;
}

/*
9
14
0 1 4
1 2 8
2 3 7 
3 4 9
4 5 10
5 6 2
6 7 1
7 8 7
0 7 8
1 7 11
2 8 2
6 8 6
2 5 4
3 5 14
*/