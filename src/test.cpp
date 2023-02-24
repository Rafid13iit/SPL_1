#include <graphics.h>
#include <iostream>

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

  // Draw nodes as circles
  int radius = 20;
  int x[nodes], y[nodes];
  for (int i = 0; i < nodes; i++) {
    x[i] = (i+1) * (800 / (nodes+1));
    y[i] = 400;
    circle(x[i], y[i], radius);
  }

  // Draw edges as lines
  for (int i = 0; i < nodes; i++) {
    for (int j = i+1; j < nodes; j++) {
      if (adj_matrix[i][j] == 1) {
        line(x[i], y[i], x[j], y[j]);
      }
    }
  }

  // Wait for user to close the window
  getch();

  // Close the graphics window
  closegraph();

  return 0;
}
