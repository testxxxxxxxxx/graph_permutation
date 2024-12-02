#include <stdio.h>
#include "../include/Graph.h"

int main(int argc, char *argv[])
{
    //Driver code:

    struct Graph *g;

    printf("test_graph");

    allocateGraph(g, 7);

    generateGNP(g, 7, 0.85, 10);

    int permutation[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf('%d', graphFindPermutation(g, permutation, 10));

    return 0;
}