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

    srand(time(NULL));

    for(int i = 0; i < g->vertices; i++)
    {
        for(int j = 0; j < g->vertices; j++)
        {
            if(((double)rand() / (double)RAND_MAX) <= probability)
                g->matrix[i][j] = rand() % maxWage + 1; 

        }
    }

}
bool graphFindPermutation(struct Graph *g, int *permutation, int permutationSize)
{
    //helper function for graphDFS

    bool *visited = (bool *)malloc(g->vertices * sizeof(bool));

    if(graphDFS(g, 0, permutation, permutationSize, visited, 0))
        return true;

    return false;
}
bool graphDFS(struct Graph *g, int vertex, int *permutation, int permutationSize, bool *visited, int it)
{
    //bactracking algorithm for find permutation as hamiltonian path

    visited[vertex] = true;

    if(it + 1 == g->vertices)
    {     
        if(isHamilton(g, visited))
            return true;
        else
            return false;

    }

    for(int i = 0; i < g->vertices; i++)
    {
        if(g->matrix[vertex][i] != 0 && visited[i] != true)
        {
            if(permutation[it] == g->matrix[vertex][i])
                it++;

            if(graphDFS(g, i, permutation, permutationSize, visited, it))
                return true;

            visited[vertex] = false;
            if(it > 0)
                it--;

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
void printGraph(struct Graph *g)
{
    for(int i = 0; i < g->vertices; i++)
    {
        for(int j = 0; j < g->vertices; j++)
        {
            printf(" %d", g->matrix[i][j]);

        }

        printf("\n");

    }

}