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


#endif // GLOBALVARIABLE_H
