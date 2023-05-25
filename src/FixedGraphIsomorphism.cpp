#include <header.h>
#include <globalVariable.h>

int fixed_isomorphism_x1[MAX], fixed_isomorphism_y1[MAX];
int radiusFor_isomorphicGraph_1;
int fixed_isomorphism_x2[MAX], fixed_isomorphism_y2[MAX];
int radiusFor_isomorphicGraph_2;
int prevColor_isomorphism;

void FixedGraphIsomorphism() {
  
    int nodes = 4, edges = 5;

    fixed_NODES = nodes;
    fixed_EDGES = edges;

    int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        adj_matrix[i][j] = 0;

        fixed_GRAPH[i][j] = 0;
      }
    }

  //edge -> connection with vertices
    adj_matrix[0][1] = 5;
    adj_matrix[1][0] = 5;  // we have to Comment this line for directed graph
    fixed_GRAPH[0][1] = fixed_GRAPH[1][0] = 5;

    
    adj_matrix[1][2] = 3;
    adj_matrix[2][1] = 3;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[1][2] = fixed_GRAPH[2][1] = 3;

    adj_matrix[2][0] = 2;
    adj_matrix[0][2] = 2;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[2][0] = fixed_GRAPH[0][2] = 2;

    adj_matrix[0][5] = 1;
    adj_matrix[5][0] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[0][5] = fixed_GRAPH[5][0] = 1;

    adj_matrix[2][3] = 2;
    adj_matrix[3][2] = 2;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[2][3] = fixed_GRAPH[3][2] = 2;

    adj_matrix[0][3] = 6;
    adj_matrix[3][0] = 6;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[0][3] = fixed_GRAPH[3][0] = 6;

    setcolor(WHITE);
    prevColor_isomorphism = getcolor();

    setlinestyle(0, 0, 1);

    // Draw fixed nodes as circles with numbers
    radiusFor_isomorphicGraph_1 = 20;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    string label;

    //1st node
    fixed_isomorphism_x1[0] = 130;
    fixed_isomorphism_y1[0] = 150;
    circle(fixed_isomorphism_x1[0], fixed_isomorphism_y1[0], radiusFor_isomorphicGraph_1);
    label = to_string(0);
    outtextxy(fixed_isomorphism_x1[0]-radiusFor_isomorphicGraph_1/2, fixed_isomorphism_y1[0]-radiusFor_isomorphicGraph_1/2, const_cast<char*>(label.c_str()));
    delay(300);

    //2nd node
    fixed_isomorphism_x1[1] = 130 + 220;
    fixed_isomorphism_y1[1] = 150;
    circle(fixed_isomorphism_x1[1], fixed_isomorphism_y1[1], radiusFor_isomorphicGraph_1);
    label = to_string(1);
    outtextxy(fixed_isomorphism_x1[1]-radiusFor_isomorphicGraph_1/2, fixed_isomorphism_y1[1]-radiusFor_isomorphicGraph_1/2, const_cast<char*>(label.c_str()));
    delay(300);

    //3rd node
    fixed_isomorphism_x1[2] = 130 + 220;
    fixed_isomorphism_y1[2] = 450;
    circle(fixed_isomorphism_x1[2], fixed_isomorphism_y1[2], radiusFor_isomorphicGraph_1);
    label = to_string(2);
    outtextxy(fixed_isomorphism_x1[2]-radiusFor_isomorphicGraph_1/2, fixed_isomorphism_y1[2]-radiusFor_isomorphicGraph_1/2, const_cast<char*>(label.c_str()));
    delay(300);

    //4th node
    fixed_isomorphism_x1[3] = 130;
    fixed_isomorphism_y1[3] = 450;
    circle(fixed_isomorphism_x1[3], fixed_isomorphism_y1[3], radiusFor_isomorphicGraph_1);
    label = to_string(3);
    outtextxy(fixed_isomorphism_x1[3]-radiusFor_isomorphicGraph_1/2, fixed_isomorphism_y1[3]-radiusFor_isomorphicGraph_1/2, const_cast<char*>(label.c_str()));
    delay(300);


    // Wait for a delay before proceeding to the next step
    delay(1000);

    // Draw edges as lines
    for (int i = 0; i < nodes; i++) {
      for (int j = i+1; j < nodes; j++) {
        if (adj_matrix[i][j] != 0) {
          line(fixed_isomorphism_x1[i], fixed_isomorphism_y1[i], fixed_isomorphism_x1[j], fixed_isomorphism_y1[j]);
          delay(300);
        }
      }
    }





    nodes = 4;
    edges = 5;

    fixed_NODES_2 = nodes;
    fixed_EDGES_2 = edges;

    adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        adj_matrix[i][j] = 0;

        fixed_GRAPH_2[i][j] = 0;
      }
    }

  //edge -> connection with vertices
    adj_matrix[0][1] = 5;
    adj_matrix[1][0] = 5;  // we have to Comment this line for directed graph
    fixed_GRAPH_2[0][1] = fixed_GRAPH_2[1][0] = 5;

    
    adj_matrix[0][2] = 3;
    adj_matrix[2][0] = 3;  // we have to Comment this line for directed fixed_GRAPH_2
    fixed_GRAPH_2[0][2] = fixed_GRAPH_2[2][0] = 3;

    adj_matrix[3][0] = 2;
    adj_matrix[0][3] = 2;  // we have to Comment this line for directed fixed_GRAPH_2
    fixed_GRAPH_2[3][0] = fixed_GRAPH_2[0][3] = 2;

    adj_matrix[1][2] = 1;
    adj_matrix[2][1] = 1;  // we have to Comment this line for directed fixed_GRAPH_2
    fixed_GRAPH_2[1][2] = fixed_GRAPH_2[2][1] = 1;

    adj_matrix[1][3] = 2;
    adj_matrix[3][1] = 2;  // we have to Comment this line for directed fixed_GRAPH_2
    fixed_GRAPH_2[1][3] = fixed_GRAPH_2[3][1] = 2;


    setcolor(WHITE);
    prevColor_isomorphism = getcolor();

    setlinestyle(0, 0, 1);

    // Draw fixed nodes as circles with numbers
    radiusFor_isomorphicGraph_2 = 20;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    //1st node
    fixed_isomorphism_x2[0] = 530;
    fixed_isomorphism_y2[0] = 150;
    circle(fixed_isomorphism_x2[0], fixed_isomorphism_y2[0], radiusFor_isomorphicGraph_2);
    label = to_string(0);
    outtextxy(fixed_isomorphism_x2[0]-radiusFor_isomorphicGraph_2/2, fixed_isomorphism_y2[0]-radiusFor_isomorphicGraph_2/2, const_cast<char*>(label.c_str()));
    delay(300);

    //2nd node
    fixed_isomorphism_x2[1] = 530 + 220;
    fixed_isomorphism_y2[1] = 150;
    circle(fixed_isomorphism_x2[1], fixed_isomorphism_y2[1], radiusFor_isomorphicGraph_2);
    label = to_string(2);
    outtextxy(fixed_isomorphism_x2[1]-radiusFor_isomorphicGraph_2/2, fixed_isomorphism_y2[1]-radiusFor_isomorphicGraph_2/2, const_cast<char*>(label.c_str()));
    delay(300);

    //3rd node
    fixed_isomorphism_x2[2] = 530 + 220;
    fixed_isomorphism_y2[2] = 450;
    circle(fixed_isomorphism_x2[2], fixed_isomorphism_y2[2], radiusFor_isomorphicGraph_2);
    label = to_string(1);
    outtextxy(fixed_isomorphism_x2[2]-radiusFor_isomorphicGraph_2/2, fixed_isomorphism_y2[2]-radiusFor_isomorphicGraph_2/2, const_cast<char*>(label.c_str()));
    delay(300);

    //4th node
    fixed_isomorphism_x2[3] = 530;
    fixed_isomorphism_y2[3] = 450;
    circle(fixed_isomorphism_x2[3], fixed_isomorphism_y2[3], radiusFor_isomorphicGraph_2);
    label = to_string(3);
    outtextxy(fixed_isomorphism_x2[3]-radiusFor_isomorphicGraph_2/2, fixed_isomorphism_y2[3]-radiusFor_isomorphicGraph_2/2, const_cast<char*>(label.c_str()));
    delay(300);


    // Wait for a delay before proceeding to the next step
    delay(1000);

    // Draw edges as lines
    for (int i = 0; i < nodes; i++) {
      for (int j = i+1; j < nodes; j++) {
        if (adj_matrix[i][j] != 0) {
          line(fixed_isomorphism_x2[i], fixed_isomorphism_y2[i], fixed_isomorphism_x2[j], fixed_isomorphism_y2[j]);
          delay(300);
        }
      }
    }
    

}

