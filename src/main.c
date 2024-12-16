#include <stdio.h>
#include "../include/Graph.h"

int main(int argc, char *argv[])
{
    //Driver code:

    struct Graph g;

    struct Graph *ptr = &g;

    allocateGraph(ptr, 7);

    generateGNP(ptr, 7, 0.5, 7);

    printGraph(ptr);

    int permutation[] = {1, 2, 3, 4, 5, 6};

    printf("permutation: %d", graphFindPermutation(ptr, permutation, 7));

    return 0;
}