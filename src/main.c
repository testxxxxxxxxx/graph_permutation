#include <stdio.h>
#include <stdlib.h>
#include "../include/Graph.h"
#include <time.h>

int main(int argc, char *argv[])
{
    //Driver code:

    struct Graph g;

    struct Graph *ptr = &g;

    srand(time(NULL));

    printf("n: %d", (int)argv[1]);

    allocateGraph(ptr, 7);

    generateGNP(ptr, 7, 0.5, 7);

    printGraph(ptr);

    int* permutation = generatePermutation(7);
    int size = sizeof(permutation) / sizeof(permutation[0]);

    printf("permutation: %d", graphFindPermutation(ptr, permutation, size));

    freeGraph(ptr);
    free(permutation);

    return 0;
}