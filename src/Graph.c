#include <stdio.h>
#include <stdlib.h>
#include "../include/Graph.h"

void allocateGraph(struct Graph *g, int n)
{
    g->matrix = (int **)malloc(n * sizeof(int *));

    for(int i = 0; i < n; i++)
    {
        g->matrix[i] = (int *)malloc(n * sizeof(int));

    }

    g->vertices = n;

}
void freeGraph(struct Graph *g)
{
    for(int i = 0; i < g->vertices; i++)
    {
        //free memory for each row

        free(g->matrix[i]);

    }

    //free memory all graph

    free(g->matrix);

}
void generateGNP(struct Graph *g, int n, float probability)
{

}