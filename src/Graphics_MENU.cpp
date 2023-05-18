#include <header.h>
#include <globalVariable.h>


void graphOptions ()
{
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(100, 150, "1. Implement algorithm in a Fixed graph");
    outtextxy(100, 300, "2. Implement algorithm in a Random graph");
    outtextxy(100, 450, "3. Implement algorithm in a User Input graph");

    while (1) {

        int x = mousex();
        int y = mousey();

        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event

            if (x > 100 && x < 620 && y > 150 && y < 170) {
    
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

void openGraphicalWindow()
{
    int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(900, 600, "Graph Algorithm Implementation & Visualization");
    //initwindow() function is used instead of initgraph()
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
    y += 60;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);

    outtextxy(50, y, "BFS");
    y += 40;
    outtextxy(50, y, "DFS");
    y += 40;
    outtextxy(50, y, "Shortest path (Dijkstra's)");
    y += 40;
    outtextxy(50, y, "Shortest path (A*)");
    y += 40;
    outtextxy(50, y, "Shortest path (Johnson's)");
    y += 40;
    outtextxy(50, y, "Minimum spanning tree (Prim's)");
    y += 40;
    outtextxy(50, y, "Minimum spanning tree (Kruskal's)");
    y += 40;
    outtextxy(50, y, "Connectivity Eulerian Path finding (Fleury's)");
    y += 40;
    outtextxy(50, y, "Strongly Connected Components (Tarjan's)");
    y += 40;
    outtextxy(50, y, "Isomorphishm (VF2)");


    while (1) {

        int x = mousex();
        int y = mousey();

        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event

            if (x > 50 && x < 120 && y > 110 && y < 130) {
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

            else if (x > 50 && x < 120 && y > 150 && y < 170) {
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

            else if (x > 50 && x < 370 && y > 190 && y < 210) {
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

            else if (x > 50 && x < 280 && y > 230 && y < 250) {
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

            else if (x > 50 && x < 370 && y > 270 && y < 290) {
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

            else if (x > 50 && x < 430 && y > 310 && y < 330) {
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

            else if (x > 50 && x < 470 && y > 350 && y < 370) {
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

            else if (x > 50 && x < 570 && y > 390 && y < 410) {
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

                //Fleurys();
                break;
            }

            else if (x > 50 && x < 570 && y > 430 && y < 450) {
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

            else if (x > 50 && x < 290 && y > 470 && y < 490) {
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

void Graphics_MENU() 
{
    
    drawButton(50, 50, 100, 50);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);

    outtextxy(200, 140, "***************************");

    outtextxy(350, 200, "Welcome");
    outtextxy(425, 250, "to");
    outtextxy(260, 300, "Graph Algorithms");

    outtextxy(200, 380, "***************************");

    while (1) {
        int x = mousex();
        int y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN)) {
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
    closegraph();
 
}
