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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "BFS");

                    Graph_FixedNodesAndEdges();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "BFS");

                    graphRandomConstruction();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "BFS");

                    graphConsUsingGraphicalWindow();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "DFS");

                    Graph_FixedNodesAndEdges();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "DFS");

                    graphRandomConstruction();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "DFS");

                    graphConsUsingGraphicalWindow();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Dijkstras");

                    Graph_FixedNodesAndEdges();

                    showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Dijkstras");

                    graphRandomConstruction();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Dijkstras");

                    graphConsUsingGraphicalWindow();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

                Dijkstras_algorithm();
                break;
            }

            else if (x > 50 && x < 270 && y > 230 && y < 250) {
                // button was clicked
                cleardevice();
                delay(100);

                settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                outtextxy(400, 30, "A* algorithm");

                graphOptions();
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "A* algorithm");

                    Graph_FixedNodesAndEdges();

                    showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "A* algorithm");

                    graphRandomConstruction();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "A* algorithm");

                    graphConsUsingGraphicalWindow();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Johnson's");

                    Graph_FixedNodesAndEdges();

                    showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Johnson's");

                    graphRandomConstruction();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Johnson's");

                    graphConsUsingGraphicalWindow();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Prims");

                    Graph_FixedNodesAndEdges();

                    showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Prims");

                    graphRandomConstruction();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Prims");

                    weightedGraphConsUsingGraphicalWindow();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Kruskals");

                    Graph_FixedNodesAndEdges();

                    showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Kruskals");

                    graphRandomConstruction();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Kruskals");

                    weightedGraphConsUsingGraphicalWindow();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                
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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Fleurys");

                    Graph_FixedNodesAndEdges();

                    showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Fleurys");

                    graphRandomConstruction();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Fleurys");

                    graphConsUsingGraphicalWindow();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

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
                
                if (CHOOSE == 1){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Tarjans");

                    Graph_FixedNodesAndEdges();

                    showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else if (CHOOSE == 2){
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Tarjans");

                    graphRandomConstruction();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }
                else{
                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
                    outtextxy(400, 30, "Tarjans");

                    graphConsUsingGraphicalWindow();

                    //showWeight();

                    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
                    outtextxy(240, 550, "Please press any key to continue");

                    getch(); // waits for user to press any key
                }

                //Tarjans();
                break;
            }
        }
     
        
    }

}

void Graphics_Graph() 
{
    
    drawButton(50, 50, 100, 50);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    outtextxy(350, 200, "Welcome");
    outtextxy(425, 250, "to");
    outtextxy(260, 300, "Graph Algorithms");

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
