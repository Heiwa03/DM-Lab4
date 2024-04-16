#include "Graph.h"

Graph * create_graph() {
    Graph * graph = (Graph *)malloc(sizeof(Graph));
    graph->num_nodes = 0;
    return graph;
}

void update_dist(int u, int v, Graph * graph) {
  if (graph->dist[v] > graph->dist[u] + graph->edge_weights[u][v]) {
    graph->dist[v] = graph->dist[u] + graph->edge_weights[u][v];
    graph->pred[v] = u;
  }
}

void print_inverted(int src, int dest, Graph * graph) {
  if (dest == src) {
    printf("%d ", src);
  } else if (graph->pred[dest] == -1) {
    printf("Path from %d to %d does not exist.\n", src, dest);
  } else {
    print_inverted(src, graph->pred[dest], graph);
    printf("%d ", dest);
  }
}

void ford_alg(int src, int dest, Graph * graph) {
  for (int i = 1; i <= graph->num_nodes; i++) {
    graph->dist[i] = INT_MAX;
    graph->pred[i] = -1;
  }
  graph->dist[src] = 0;

  for (int i = 1; i <= graph->num_nodes - 1; i++) {
    for (int u = 1; u <= graph->num_nodes; u++) {
      for (int j = 1; j <= graph->adj_list[u][0]; j++) {
        int v = graph->adj_list[u][j];
        update_dist(u, v, graph);
      }
    }
  }

  for (int u = 1; u <= graph->num_nodes; u++) {
    for (int j = 1; j <= graph->adj_list[u][0]; j++) {
      int v = graph->adj_list[u][j];
      if (graph->dist[v] > graph->dist[u] + graph->edge_weights[u][v]) {
        printf("Negative weight cycle detected\n");
        return;
      }
    }
  }

  // Afisare drum minim sau maxim
  printf("Shortest path from %d to %d. Total weight = %d:\n", src, dest, graph->dist[dest]);
  print_inverted(src, dest, graph);
  printf("\n");
}

void bk_alg(int src, int dest, Graph * graph) {
  for (int i = 1; i <= graph->num_nodes; i++) {
    graph->dist[i] = INT_MAX;
    graph->pred[i] = -1;
  }
  graph->dist[src] = 0;

  // Relaxare repetată a tuturor muchiilor
  for (int i = 1; i <= graph->num_nodes - 1; i++) {
    for (int u = 1; u <= graph->num_nodes; u++) {
      for (int j = 1; j <= graph->adj_list[u][0]; j++) {
        int v = graph->adj_list[u][j];
        if (graph->dist[v] > graph->dist[u] + graph->edge_weights[u][v]) {
          graph->dist[v] = graph->dist[u] + graph->edge_weights[u][v];
          graph->pred[v] = u;
        }
      }
    }
  }

  // Verificare ciclu negativ
  for (int u = 1; u <= graph->num_nodes; u++) {
    for (int j = 1; j <= graph->adj_list[u][0]; j++) {
      int v = graph->adj_list[u][j];
      if (graph->dist[v] > graph->dist[u] + graph->edge_weights[u][v]) {
        printf("Negative cycle detected!\n");
        return;
      }
    }
  }

  // Afisare drum minim
  printf("Shortest path from %d to %d. Total weight = %d:\n", src, dest, graph->dist[dest]);
  int current_node = dest;
  while (current_node != src) {
    printf("%d ", current_node);
    current_node = graph->pred[current_node];
  }
  printf("%d\n", src);
}

void populate_graph(Graph * graph) {
  // Introducere număr de noduri
  printf("Enter the number of nodes: ");
  scanf("%d", &(graph->num_nodes));

  // Introducere lista de adiacență
  printf("\nPopulating adjacency list:\n");
  for (int i = 1; i <= graph->num_nodes; i++) {
    printf("Enter the number of leaves of node %d: ", i);
    int nr_leaves;
    scanf("%d", &nr_leaves);
    graph->adj_list[i][0] = nr_leaves;

    if (nr_leaves > 0) {
      printf("Enter the leaves of node %d(space separated)) ", i);
      for (int j = 1; j <= nr_leaves; j++) {
        scanf("%d", &(graph->adj_list[i][j]));
      }
    }
  }

  // Introducere ponderi muchii
  for (int i = 1; i <= graph->num_nodes; i++) {
    for (int j = 1; j <= graph->adj_list[i][0]; j++) {
      printf("Weight of edge (%d, %d)?: ", i,
             graph->adj_list[i][j]);
      scanf("%d", &(graph->edge_weights[i][graph->adj_list[i][j]]));
    }
  }
}