#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"

#define MAX_NODES 100

typedef struct Graph {
    int adj_list[MAX_NODES][MAX_NODES];
    int edge_weights[MAX_NODES][MAX_NODES];
    int num_nodes;
    int dist[MAX_NODES];
    int pred[MAX_NODES];
} Graph;

Graph * create_graph();
void populate_graph(Graph * graph);
void update_dist(int u, int v, Graph * graph);
void print_inverted(int src, int dest, Graph * graph);
void ford_alg(int src, int dest, Graph * graph);
void bk_alg(int src, int dest, Graph * graph);

#endif // GRAPH_H

