#include <header.h>
#include <globalVariable.h>

int g1[MAX][MAX];
int g2[MAX][MAX];

bool isIsomorphic() {
    int n1, m1;

    if (CHOOSE == 1){
        //for Fixed Graph
        n1 = fixed_NODES;
        m1 = fixed_EDGES;
        
        for (int i = 0; i < n1; i++){
            for (int j = 0; j < n1; j++){
                g1[i][j] = fixed_GRAPH[i][j];
            }
        }

    }

    int n2, m2;

    if (CHOOSE == 1){
        //for Fixed Graph
        n2 = fixed_NODES_2;
        m2 = fixed_EDGES_2;
        
        for (int i = 0; i < n2; i++){
            for (int j = 0; j < n2; j++){
                g2[i][j] = fixed_GRAPH_2[i][j];
            }
        }

    }

    if (n1 != n2)
        return false;

    unordered_map<int, int> degreeCount1, degreeCount2;

    for (int i = 0; i < n1; i++) {
        fixedNodeColor_1(i);
        delay(100);
        for (int j = 0; j < n1; j++) {
            degreeCount1[i] += g1[i][j];
            degreeCount2[i] += g2[i][j];
        }
    }

    if (degreeCount1 != degreeCount2)
        return false;

    unordered_map<int, unordered_map<int, int>> labelCount1, labelCount2;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            if (g1[i][j]) {
                labelCount1[i][degreeCount1[j]]++;
            }
            if (g2[i][j]) {
                labelCount2[i][degreeCount2[j]]++;
            }
        }
    }

    return labelCount1 == labelCount2;
}

 void VF2_graph_isomorphism() {

    setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text
    
    
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    outtextxy(400, 30, "VF2");

    if (isIsomorphic())
        cout << "The two graphs are ISOMORPHIC." << endl;
    else
        cout << "The two graphs are NOT Isomorphic." << endl;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");


    prevWindowArrow();

    int x = mousex();
    int y = mousey();
    if (ismouseclick(WM_LBUTTONDOWN)) {
        clearmouseclick(WM_LBUTTONDOWN); // clear the mouse click event
        if (x > 50 && x < 110 && y > 50 && y < 90) {
            // button was clicked
            cleardevice();
            delay(100);
            //getch();
            showList();
            //break;
        }
    } 
    
}

//Example 1
/*
8
12
0 1
0 3
0 4
1 2
1 5 
2 3
2 6
3 7
4 5
4 7
5 6
6 7
8
12
0 1
0 3
0 5
2 1
2 3
2 7
4 1
4 5
4 7
6 3
6 5
6 7

Isomorphic
*/

//Example 2
/*
6
6
0 1
0 3
1 2
2 5
3 4 
4 5
6
6
0 4
0 3
1 3
1 5
2 4
2 5

Isomorphic
*/

//Example 3
/*
6
6
0 1
0 2
1 2
2 5
3 4
4 5
6
6
0 2
0 4
1 3
1 5
2 4
3 5

NOT isomorphic
*/


