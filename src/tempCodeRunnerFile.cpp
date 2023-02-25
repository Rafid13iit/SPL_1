#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int nodes, edges;

  cout << "Enter the number of nodes: ";
  cin >> nodes;

  cout << "Enter the number of edges: ";
  cin >> edges;

  int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      adj_matrix[i][j] = 0;
    }
  }

  int u, v;
  cout << "Enter edges (u v):\n";

  for (int i = 0; i < edges; i++) {
    cin >> u >> v;

    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // we have to Comment this line for directed graph
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

  setfillstyle(SOLID_FILL, YELLOW); // set the fill color to yellow
  circle(x[i], y[i], radius);

  string label = to_string(i);
  outtextxy(x[i]-radius/2, y[i]-radius/2, const_cast<char*>(label.c_str()));
} 

// Wait for a delay before proceeding to the next step
delay(5000);

// Draw edges as curved lines
for (int i = 0; i < nodes; i++) {
  for (int j = i+1; j < nodes; j++) {
    if (adj_matrix[i][j] == 1) {
      int midx = (x[i] + x[j])/2;
      int midy = (y[i] + y[j])/2;
      int diffx = abs(x[i] - x[j])/2;
      int diffy = abs(y[i] - y[j])/2;
      int radius = sqrt(diffx*diffx + diffy*diffy);
      double angle1 = atan2(y[j] - y[i], x[j] - x[i]) + M_PI/2;
      double angle2 = atan2(y[i] - y[j], x[i] - x[j]) + M_PI/2;
      arc(midx, midy, angle1, angle2, radius);
      delay(2000);
    }
  }
}

// Wait for user to close the window
getch();

// Close the graphics window
closegraph();


return 0;
}

/*
9
14
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
0 7
1 7
2 8
6 8
2 5
3 5
*/
