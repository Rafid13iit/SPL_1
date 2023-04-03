#include <graphics.h>
#include <header.h>

void Graph_FixedNodesAndEdges() {
  int nodes = 6, edges = 9;


  int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      adj_matrix[i][j] = 0;
    }
  }

//edge -> connection with vertices
  adj_matrix[0][1] = 1;
  adj_matrix[1][0] = 1;  // we have to Comment this line for directed graph

  adj_matrix[1][2] = 1;
  adj_matrix[2][1] = 1;  // we have to Comment this line for directed graph

  adj_matrix[2][3] = 1;
  adj_matrix[3][2] = 1;  // we have to Comment this line for directed graph

  adj_matrix[3][4] = 1;
  adj_matrix[4][3] = 1;  // we have to Comment this line for directed graph

  adj_matrix[4][5] = 1;
  adj_matrix[5][4] = 1;  // we have to Comment this line for directed graph

  adj_matrix[0][5] = 1;
  adj_matrix[5][0] = 1;  // we have to Comment this line for directed graph

  adj_matrix[1][5] = 1;
  adj_matrix[5][1] = 1;  // we have to Comment this line for directed graph

  adj_matrix[1][4] = 1;
  adj_matrix[4][1] = 1;  // we have to Comment this line for directed graph

  adj_matrix[2][4] = 1;
  adj_matrix[4][2] = 1;  // we have to Comment this line for directed graph


  // Initialize graphics window
  initwindow(800, 600, "Graph");

  // Draw fixed nodes as circles with numbers
  int radius = 20;
  int x[nodes], y[nodes];

  settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
  string label;

  //1st node
  x[0] = 70;
  y[0] = 300;
  circle(x[0], y[0], radius);
  label = to_string(0);
  outtextxy(x[0]-radius/2, y[0]-radius/2, const_cast<char*>(label.c_str()));

  //2nd node
  x[1] = 250;
  y[1] = 150;
  circle(x[1], y[1], radius);
  label = to_string(1);
  outtextxy(x[1]-radius/2, y[1]-radius/2, const_cast<char*>(label.c_str()));

  //3rd node
  x[2] = 250 + 220;
  y[2] = 150;
  circle(x[2], y[2], radius);
  label = to_string(2);
  outtextxy(x[2]-radius/2, y[2]-radius/2, const_cast<char*>(label.c_str()));

  //4th node
  x[3] = 250 + 220 + 180;
  y[3] = 300;
  circle(x[3], y[3], radius);
  label = to_string(3);
  outtextxy(x[3]-radius/2, y[3]-radius/2, const_cast<char*>(label.c_str()));

  //5th node
  x[4] = 250 + 220;
  y[4] = 450;
  circle(x[4], y[4], radius);
  label = to_string(4);
  outtextxy(x[4]-radius/2, y[4]-radius/2, const_cast<char*>(label.c_str()));

  //6th node
  x[5] = 250;
  y[5] = 450;
  circle(x[5], y[5], radius);
  label = to_string(5);
  outtextxy(x[5]-radius/2, y[5]-radius/2, const_cast<char*>(label.c_str()));

  // Wait for a delay before proceeding to the next step
  delay(2000);

  // Draw edges as lines
  for (int i = 0; i < nodes; i++) {
    for (int j = i+1; j < nodes; j++) {
      if (adj_matrix[i][j] == 1) {
        line(x[i], y[i], x[j], y[j]);
        delay(1000);
      }
    }
  }

  // Wait for user to close the window
  getch();

  // Close the graphics window
  closegraph();

}

