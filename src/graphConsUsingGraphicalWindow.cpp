#include <header.h>
#include <globalVariable.h>


void graphConsUsingGraphicalWindow()
{
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

//Graphical Works

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
  delay(1500);

  // Draw edges as lines
  for (int i = 0; i < nodes; i++) {
    for (int j = i+1; j < nodes; j++) {
      if (adj_matrix[i][j] == 1) {
        line(x[i], y[i], x[j], y[j]);
        delay(1500);
      }
    }
  }

  settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
  outtextxy(240, 550, "Please press any key to continue");

  // Wait for user to close the window
  getch();

  //closegraph();

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
