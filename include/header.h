#ifndef HEADER_H
#define HEADER_H


#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

#include <cstdlib> //it's used for the srand(), rand() functions, which generates random numbers.
#include <ctime> //for time(0) function

typedef long long int ll;
typedef unsigned long long int llu;
#define MAX 100


//Function Calls
void openGraphicalWindow();
void prevWindowArrow ();
void drawButton(int x, int y, int width, int height);
void showList();
void graphOptions();
void Graphics_MENU();

void VF2_graph_isomorphism();

void A_star_algorithm();

void BFS();

void DFS();

void fixedNodeColor (int u);
void fixedNodeColor_1 (int u);
void fixedNodeColor_2 (int u);
void fixedNodeColor_3 (int u);
void fixedGraphConnection (int u, int v);
void fixedGraphConnection_1 (int u, int v);
void showWeight ();
void showFixedNodeDistance(int node, int distance);
void Graph_FixedNodesAndEdges();

void graphConstruction();

void nodeColor (int u);
void nodeColor_1 (int u);
void nodeColor_2 (int u);
void nodeColor_3 (int u);
void graphConnection (int u, int v);
void graphConnection_1 (int u, int v);
void showNodeDistance(int node, int distance);
void UserInput_GraphConstruction();

void showWeight_2 (int weight, int i, int j);
void Weighted_GraphConstruction();

void Random_GraphConstruction();

void WeightedRandom_GraphConstruction();

void MST_Kruskals_Algorithm ();

void MST_Prims_Algorithm ();

void Dijkstras_algorithm();

void EulerianPathFind_Fleurys();


#endif // HEADER_H
