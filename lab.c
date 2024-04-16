#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"
#include "Menu.h"

int main() {
  Graph * graph = (Graph *)malloc(sizeof(Graph));

  populate_graph(graph);
  if(-1 == open_menu(graph))
    printf("Exiting...\n");
  
  free(graph);
  return 0;
}