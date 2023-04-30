#include <header.h>
#include <globalVariable.h>

int fixed_x[MAX], fixed_y[MAX];

void fixedGraphConnection (int u, int v)
{
    setcolor(YELLOW);
    //setlinestyle(0, 0, 2);
    line(fixed_x[u], fixed_y[u], fixed_x[v], fixed_y[v]);
    delay(1600);
}

void fixedNodeColor (int u)
{
    setcolor(YELLOW);

    int radius = 20;
    circle(fixed_x[u], fixed_y[u], radius);
    string label = to_string(u);
    outtextxy(fixed_x[u]-radius/2, fixed_y[u]-radius/2, const_cast<char*>(label.c_str()));
    delay(1000);
}

void fixedNodeColor_1 (int u)
{
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(fixed_x[u], fixed_y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(fixed_x[u]-textWidth/2, fixed_y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}

void fixedNodeColor_2 (int u)
{
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(fixed_x[u], fixed_y[u], 20, 20);

    string label = to_string(u);
    int textWidth = textwidth(const_cast<char*>(label.c_str()));
    int textHeight = textheight(const_cast<char*>(label.c_str()));

    setcolor(WHITE);
    outtextxy(fixed_x[u]-textWidth/2, fixed_y[u]-textHeight/2, const_cast<char*>(label.c_str()));
    //delay(1000);
}
 
void Graph_FixedNodesAndEdges() {
  
    int nodes = 7, edges = 10;

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
    adj_matrix[0][1] = 1;
    adj_matrix[1][0] = 1;  // we have to Comment this line for directed graph
    fixed_GRAPH[0][1] = fixed_GRAPH[1][0] = 1;

    adj_matrix[1][2] = 1;
    adj_matrix[2][1] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[1][2] = fixed_GRAPH[2][1] = 1;
    
    adj_matrix[2][3] = 1;
    adj_matrix[3][2] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[2][3] = fixed_GRAPH[3][2] = 1;

    adj_matrix[3][4] = 1;
    adj_matrix[4][3] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[3][4] = fixed_GRAPH[4][3] = 1;

    adj_matrix[4][5] = 1;
    adj_matrix[5][4] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[4][5] = fixed_GRAPH[5][4] = 1;

    adj_matrix[0][5] = 1;
    adj_matrix[5][0] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[0][5] = fixed_GRAPH[5][0] = 1;

    adj_matrix[1][5] = 1;
    adj_matrix[5][1] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[1][5] = fixed_GRAPH[5][1] = 1;

    adj_matrix[1][6] = 1;
    adj_matrix[6][1] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[1][6] = fixed_GRAPH[6][1] = 1;

    adj_matrix[6][4] = 1;
    adj_matrix[4][6] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[6][4] = fixed_GRAPH[4][6] = 1;

    adj_matrix[2][4] = 1;
    adj_matrix[4][2] = 1;  // we have to Comment this line for directed fixed_GRAPH
    fixed_GRAPH[2][4] = fixed_GRAPH[4][2] = 1;

    setcolor(WHITE);


    // Draw fixed nodes as circles with numbers
    int radius = 20;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    string label;

    //1st node
    fixed_x[0] = 150;
    fixed_y[0] = 300;
    circle(fixed_x[0], fixed_y[0], radius);
    label = to_string(0);
    outtextxy(fixed_x[0]-radius/2, fixed_y[0]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //2nd node
    fixed_x[1] = 330;
    fixed_y[1] = 150;
    circle(fixed_x[1], fixed_y[1], radius);
    label = to_string(1);
    outtextxy(fixed_x[1]-radius/2, fixed_y[1]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //3rd node
    fixed_x[2] = 330 + 220;
    fixed_y[2] = 150;
    circle(fixed_x[2], fixed_y[2], radius);
    label = to_string(2);
    outtextxy(fixed_x[2]-radius/2, fixed_y[2]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //4th node
    fixed_x[3] = 330 + 220 + 180;
    fixed_y[3] = 300;
    circle(fixed_x[3], fixed_y[3], radius);
    label = to_string(3);
    outtextxy(fixed_x[3]-radius/2, fixed_y[3]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //5th node
    fixed_x[4] = 330 + 220;
    fixed_y[4] = 450;
    circle(fixed_x[4], fixed_y[4], radius);
    label = to_string(4);
    outtextxy(fixed_x[4]-radius/2, fixed_y[4]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //6th node
    fixed_x[5] = 330;
    fixed_y[5] = 450;
    circle(fixed_x[5], fixed_y[5], radius);
    label = to_string(5);
    outtextxy(fixed_x[5]-radius/2, fixed_y[5]-radius/2, const_cast<char*>(label.c_str()));
    delay(300);

    //7th node
    fixed_x[6] = 440;
    fixed_y[6] = 300;
    circle(fixed_x[6], fixed_y[6], radius);
    label = to_string(6);
    outtextxy(fixed_x[6]-radius/2, fixed_y[6]-radius/2, const_cast<char*>(label.c_str()));

    // Wait for a delay before proceeding to the next step
    delay(1000);

    // Draw edges as lines
    for (int i = 0; i < nodes; i++) {
      for (int j = i+1; j < nodes; j++) {
        if (adj_matrix[i][j] == 1) {
          line(fixed_x[i], fixed_y[i], fixed_x[j], fixed_y[j]);
          delay(300);
        }
      }
    }
    
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(240, 550, "Please press any key to continue");
    
    getch(); // waits for user to press any key

}

