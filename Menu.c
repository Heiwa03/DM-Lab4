#include "Menu.h"

void _print_menu_options () {
  printf("Choose an algorithm:\n");
  printf("1. Ford\n");
  printf("2. Bellman-Kalaba\n");
  printf("0. Exit\n");
}

int open_menu(Graph * graph) {
  int option = -1;
  while (option != 0) {
    int choice;
    _print_menu_options();
    scanf("%d", &choice);
    getchar();
    int dest;
    if (choice != 0) {
        printf("Enter destination: ");
        scanf("%d", &dest);
    }

    switch (choice) {
      case 1:
        ford_alg(1, dest, graph);
        break;
      case 2:
        bk_alg(1, dest, graph);
        break;
      case 0:
        return -1;
        break;
      default:
        printf("Invalid option\n");
        break;
    }

    printf("Choose another algorithm? (1=yes, 0=no): ");
    scanf("%d", &option);
  }
}