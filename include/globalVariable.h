#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#define MAX 100


extern int NODES, EDGES;
extern int U, V, WEIGHT;
extern int GRAPH[MAX][MAX];
extern int SOURCE;
extern int CHOOSE;

extern int x[MAX], y[MAX];
extern int prevNodeIndex[MAX];

//for Fixed Graph
extern int fixed_NODES, fixed_EDGES;
extern int fixed_U, fixed_V, fixed_WEIGHT;
extern int fixed_GRAPH[MAX][MAX];
extern int fixed_SOURCE;

//for Fixed Graph
extern int fixed_NODES_2, fixed_EDGES_2;
extern int fixed_GRAPH_2[MAX][MAX];
extern int fixed_SOURCE_2;

//for Directed Fixed Graph
extern int directedFixed_NODES, directedFixed_EDGES;
extern int directedFixed_U, directedFixed_V, directedFixed_WEIGHT;
extern int directedFixed_GRAPH[MAX][MAX];
extern int directedFixed_SOURCE;

extern int COUNT;


#endif // GLOBALVARIABLE_H
