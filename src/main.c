#include <stdio.h>
#include "../include/Graph.h"

int main(int argc, char *argv[])
{
    //Driver code:

    struct Graph g;

    struct Graph *ptr = &g;

    allocateGraph(ptr, 7);

    generateGNP(ptr, 7, 0.85, 10);

    int permutation[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("permutation: %d", graphFindPermutation(ptr, permutation, 10));

    return 0;
}