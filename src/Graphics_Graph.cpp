#include <graphics.h>
#include <conio.h>

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
}

int main() {
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
                showList();
                break;
            }
        }
    }
    getch();
    closegraph();
    return 0;
}
