#include <header.h>
#include <globalVariable.h>

bool isIsomorphic(const vector<vector<int>>& g1, const vector<vector<int>>& g2) {
    int n1 = g1.size();
    int n2 = g2.size();

    if (n1 != n2)
        return false;

    unordered_map<int, int> degreeCount1, degreeCount2;

    for (int i = 0; i < n1; i++) {
        degreeCount1[g1[i].size()]++;
        degreeCount2[g2[i].size()]++;
    }

    if (degreeCount1 != degreeCount2)
        return false;

    unordered_map<int, unordered_map<int, int>> labelCount1, labelCount2;

    for (int i = 0; i < n1; i++) {
        for (int j : g1[i])
            labelCount1[i][g1[j].size()]++;

        for (int j : g2[i])
            labelCount2[i][g2[j].size()]++;
    }

    return labelCount1 == labelCount2;
}

void VF2_graph_isomorphism() {

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    outtextxy(400, 30, "VF2");
    
    int n1, m1;
    cin >> n1 >> m1;

    vector<vector<int>> g1(n1);

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }

    int n2, m2;
    cin >> n2 >> m2;

    vector<vector<int>> g2(n2);

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    if (isIsomorphic(g1, g2))
        cout << "The two graphs are ISOMORPHIC." << endl;
    else
        cout << "The two graphs are NOT Isomorphic." << endl;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");
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

