#include <stdio.h>
#include <stdlib.h>
#include "../include/Graph.h"
#include <time.h>

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

    free(g->matrix);;

}
void generateGNP(struct Graph *g, int n, float probability, int maxWage)
{
    //generate graph GNP 

    for(int i = 0; i < g->vertices; i++)
    {
        for(int j = 0; j < g->vertices; j++)
        {
            if(rand() >= probability)
                g->matrix[i][j] = rand() % maxWage + 1; 

        }
    }

}
bool graphDFS(struct Graph *g, int vertex, int *permutation, int count, int permutationSize, bool *visited)
{
    //DFS

    visited[vertex] = true;

    if(count == g->vertices && isHamilton(g, visited))
        return true;
    else
        return false;

    for(int i = 0; i < vertex; i++)
    {
        if(g->matrix[vertex][i] != 0 && visited[i] != true)
        {
            if(permutation[i] == g->matrix[vertex][i])
                count++;
            else
                count = 0;         

            bool state = graphDFS(g, i, permutation, count, permutationSize, visited);

            if(state)
                return true;
        }
    }

    return false;
}
bool isHamilton(struct Graph *g, bool *visited)
{
    //check if is hamiltonian path

    for(int i = 0; i < g->vertices; i++)
    {
        if(!visited[i])
            return false;

    }

    return true;
}