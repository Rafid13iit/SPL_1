#include <header.h>
#include <globalVariable.h>


void prevWindowArrow ()
{
    //this part is for to go back to the previous window
    int x2 = 50;
    int y2 = 70;
    // Draw the arrow line
    line(x2, y2, x2 + 60, y2);
    // Draw the arrowhead
    line(x2, y2, x2 + 30, y2 - 20);
    line(x2, y2, x2 + 30, y2 + 20);
}

void graphOptions ()
{
    prevWindowArrow();

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(100, 150, "1. Implement algorithm in a Fixed graph");
    outtextxy(100, 300, "2. Implement algorithm in a Random graph");
    outtextxy(100, 450, "3. Implement algorithm in a User Input graph");

    while (1) {

        int x = mousex();
        int y = mousey();

        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event

            ////this part is for to go back to the previous window
            if (x > 50 && x < 110 && y > 50 && y < 90) {
                // button was clicked
                cleardevice();
                delay(100);
                //getch();
                showList();
                //break;
            }

            else if (x > 100 && x < 620 && y > 150 && y < 170) {
    
                cleardevice();
                delay(100);

                CHOOSE = 1;

                return ;
            }

            else if (x > 100 && x < 620 && y > 300 && y < 320) {
                
                cleardevice();
                delay(100);

                CHOOSE = 2;

                return ;
            }

            else if (x > 100 && x < 620 && y > 450 && y < 470) {
                
                cleardevice();
                delay(100);

                CHOOSE = 3;

                return ;
            }
        }
    }
}

void drawButton(int x, int y, int width, int height) 
{
    line(x, y, width, height);
    line(x, y+20, width, height+20);
    line(x, y+40, width, height+40);
}


void showList()
{
    int y = 50;
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);

    outtextxy(400, y, "MENU");
    y += 90;


    prevWindowArrow ();
    

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);

    outtextxy(100, y, "BFS");
    y += 40;
    outtextxy(100, y, "DFS");
    y += 40;
    outtextxy(100, y, "Shortest path (Dijkstra's)");
    y += 40;
    outtextxy(100, y, "Shortest path (A*)");
    y += 40;
    outtextxy(100, y, "Shortest path (Johnson's)");
    y += 40;
    outtextxy(100, y, "Minimum spanning tree (Prim's)");
    y += 40;
    outtextxy(100, y, "Minimum spanning tree (Kruskal's)");
    y += 40;
    outtextxy(100, y, "Connectivity Eulerian Path finding (Fleury's)");
    y += 40;
    outtextxy(100, y, "Strongly Connected Components (Tarjan's)");
    y += 40;
    outtextxy(100, y, "Isomorphishm (VF2)");



    while (1) {

        int x = mousex();
        int y = mousey();

        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event

            ////this part is for to go back to the previous window
            if (x > 50 && x < 110 && y > 50 && y < 90) {
                // button was clicked
                cleardevice();
                delay(100);
                //getch();
                Graphics_MENU();
                //break;
            }

            else if (x > 100 && x < 170 && y > 140 && y < 160) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "BFS");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "BFS");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                }
                else if (CHOOSE == 2){
                    Random_GraphConstruction();
                }
                else{
                    UserInput_GraphConstruction();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                BFS();
                break;
            }

            else if (x > 100 && x < 170 && y > 180 && y < 200) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "DFS");

                graphOptions();
                    
                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "DFS");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                }
                else if (CHOOSE == 2){
                    Random_GraphConstruction();
                }
                else{
                    UserInput_GraphConstruction();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                DFS();
                break;
            }

            else if (x > 100 && x < 420 && y > 210 && y < 240) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Dijkstras");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Dijkstras");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                Dijkstras_algorithm();
                break;
            }

            else if (x > 100 && x < 330 && y > 260 && y < 280) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "A* algorithm");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "A* algorithm");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                A_star_algorithm();
                break;
            }

            else if (x > 100 && x < 420 && y > 300 && y < 320) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Johnson's");

                graphOptions();
                
                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Johnson's");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                //Johnsons();
                break;
            }

            else if (x > 100 && x < 480 && y > 340 && y < 360) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Prims");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Prims");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                MST_Prims_Algorithm();
                break;
            }

            else if (x > 100 && x < 520 && y > 380 && y < 400) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Kruskals");

                graphOptions();
                
                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Kruskals");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    WeightedRandom_GraphConstruction();
                    //showWeight();
                }
                else{
                    Weighted_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key
                
                MST_Kruskals_Algorithm();
                break;
            }

            else if (x > 100 && x < 620 && y > 420 && y < 440) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Fleurys");

                graphOptions();
                
                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Fleurys");

                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    //showWeight();
                }
                else if (CHOOSE == 2){
                    Random_GraphConstruction();
                    //showWeight();
                }
                else{
                    UserInput_GraphConstruction();
                    //showWeight();
                }
                
                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                EulerianPathFind_Fleurys();
                break;
            }

            else if (x > 100 && x < 620 && y > 460 && y < 480) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Tarjans");

                graphOptions();

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "Tarjans");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    Random_GraphConstruction();
                    //showWeight();
                }
                else{
                    UserInput_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                //Tarjans();
                break;
            }

            else if (x > 100 && x < 340 && y > 500 && y < 520) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "VF2");

                graphOptions();
                
                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "VF2");
                
                if (CHOOSE == 1){
                    Graph_FixedNodesAndEdges();
                    showWeight();
                }
                else if (CHOOSE == 2){
                    Random_GraphConstruction();
                    //showWeight();
                }
                else{
                    UserInput_GraphConstruction();
                    //showWeight();
                }

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                outtextxy(240, 550, "Please press any key to continue");

                getch(); // waits for user to press any key

                VF2_graph_isomorphism();
                break;
            }
        }
     
        
    }

}


void openGraphicalWindow()
{
    int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(900, 680, "Graph Algorithm Implementation & Visualization");
    //initwindow() function is used instead of initgraph()
}

void Graphics_MENU() 
{
    
    drawButton(50, 50, 100, 50);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    outtextxy(200, 190, "***************************");

    outtextxy(350, 260, "Welcome");
    outtextxy(425, 310, "to");
    outtextxy(260, 360, "Graph Algorithms");

    outtextxy(200, 440, "***************************");

    while (1) {
        int x = mousex();
        int y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event
            if (x > 50 && x < 100 && y > 50 && y < 90) {
                // button was clicked
                cleardevice();
                delay(100);
                //getch();
                showList();
                //break;
            }
        }    
    }

    getch();
    //closegraph();
 
}
