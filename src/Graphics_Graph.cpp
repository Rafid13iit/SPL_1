#include <graphics.h>
#include <conio.h>
#include <header.h>

void drawButton(int x, int y, int width, int height) {
    line(x, y, width, height);
    line(x, y+20, width, height+20);
    line(x, y+40, width, height+40);
}


void showList() {
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
            if (x > 50 && x < 150 && y > 50 && y < 80) {
                // button was clicked
                //delay(250);
                cleardevice();
                delay(100);
                BFS();
                break;
            }

            else if (x > 50 && x < 150 && y > 90 && y < 120) {
                // button was clicked
                cleardevice();
                delay(100);
                DFS();
                break;
            }

            else if (x > 50 && x < 150 && y > 130 && y < 160) {
                // button was clicked
                cleardevice();
                delay(100);
                //Dijkstra();
                break;
            }

            else if (x > 50 && x < 150 && y > 170 && y < 200) {
                // button was clicked
                cleardevice();
                delay(100);
                A_star_algorithm();
                break;
            }

            else if (x > 50 && x < 150 && y > 210 && y < 240) {
                // button was clicked
                cleardevice();
                delay(100);
                //Johnsons();
                break;
            }

            else if (x > 50 && x < 150 && y > 250 && y < 280) {
                // button was clicked
                cleardevice();
                delay(100);
                MST_Prims_Algorithm();
                break;
            }

            else if (x > 50 && x < 150 && y > 290 && y < 320) {
                // button was clicked
                cleardevice();
                delay(100);
                MST_Kruskals_Algorithm();
                break;
            }

            else if (x > 50 && x < 150 && y > 330 && y < 360) {
                // button was clicked
                cleardevice();
                delay(100);
                //Fleurys();
                break;
            }

            else if (x > 50 && x < 150 && y > 370 && y < 400) {
                // button was clicked
                cleardevice();
                delay(100);
                //Tarjans();
                break;
            }
        }

        
        
    }


}

void Graphics_Graph() {
    int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(900, 600);
    //initwindow() function is used instead of initgraph()

    drawButton(50, 50, 100, 50);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    outtextxy(350, 200, "Welcome");
    outtextxy(425, 250, "to");
    outtextxy(260, 300, "Graph Algorithms");

    while (1) {
        int x = mousex();
        int y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (x > 50 && x < 150 && y > 50 && y < 80) {
                // button was clicked
                cleardevice();
                delay(100);
                showList();
                break;
            }
        }
        
        
        
    }
    getch();
    closegraph();
 
}
