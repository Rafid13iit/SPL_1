#include <header.h>
#include <globalVariable.h>

#include <cstdlib> //it's used for the srand(), rand() functions, which generates random numbers.
#include <ctime> //for time(0) function

void randomGraphConsUsingGraphicalWindow () 
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

  srand(time(0));

  /* time(0) is a function from the ctime header file
   that returns the current calendar time as the number of seconds
   elapsed since the epoch (00:00:00 UTC, January 1, 1970).
   This ensures that a different set of random numbers is generated every time the code is run.*/

  /* When used as an argument for srand, 
  time(0) serves as a seed for the random number generator rand()
  to ensure that a different set of random numbers is generated 
  every time the code is run.*/

  int u, v;
  int count = 0;

  while (count < edges) {
    u = rand() % nodes;
    v = rand() % nodes;

    if (u != v && adj_matrix[u][v] != 1) {
      adj_matrix[u][v] = 1;
      adj_matrix[v][u] = 1; // Comment this line for directed graph
      count++; //keeping track of the number of edges added to the graph.
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

  // Draw edges as lines
  for (int i = 0; i < nodes; i++) {
    for (int j = i+1; j < nodes; j++) {
      if (adj_matrix[i][j] == 1) {
        line(x[i], y[i], x[j], y[j]);
        delay(2000);
      }
    }
  }

  // Wait for user to close the window
  getch();

  // Close the graphics window
  closegraph();

}