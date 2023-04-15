#ifndef HEADER_H
#define HEADER_H


#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

#include <cstdlib> //it's used for the srand(), rand() functions, which generates random numbers.
#include <ctime> //for time(0) function

typedef long long int ll;
typedef unsigned long long int llu;
#define MAX 1000


void openGraphicalWindow();
void Graphics_Graph();
void drawButton(int x, int y, int width, int height);
void showList();

void VF2_graph_isomorphism();
bool check(int u1, int u2);
bool dfs(int u1, int u2);
bool isIsomorphic();

void A_star_algorithm();
int Astar(int sx, int sy, int ex, int ey, int width, int height);

void BFS();

void DFS();
void DFS_algorithm(int node);

void graphConnection (int u, int v);
void Graph_FixedNodesAndEdges();

void graphConstruction();

void graphConsUsingGraphicalWindow();

void graphRandomConstruction();

void MST_Kruskals_Algorithm ();
void makeSet(int x);
ll findParent (ll x);
void makeUnion (ll u, ll v);
ll kruskal (ll nodes, ll edges);

void MST_Prims_Algorithm ();
int selectMinVertex (vector<int>& value, vector<bool>& setMST);
int findMST (int graph[MAX][MAX]);

void randomGraphConsUsingGraphicalWindow ();

void Dijkstras_algorithm();
int minDistance(int distance[], bool sptSet[]);
void printSolution(int src, int dst, int distance[]);
void dijkstra(int src, int dst);

#endif // HEADER_H
