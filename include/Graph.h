#ifndef GRAPH_H

#define GRAPH_H 1

#include <stdbool.h>

struct Graph
{
    int **matrix; //adjacency matrix
    int vertices; //number vertices in Graph

};

/*Allocate memory for Graph
* n - number of vertices
*/
void allocateGraph(struct Graph *g, int n);
//free memory Graph
void freeGraph(struct Graph *g);
/*Generate graph model G(n,r)
* n - number of vertices
* probability - edge probability
*/
void generateGNP(struct Graph *g, int n, float probability, int maxWage);
//free memory Graph
void freeGraph(struct Graph *g);
//find permutation in graph
bool graphFindPermutation(struct Graph *g, int *permutation, int permutationSize);
//graph DFS algorithm
bool graphDFS(struct Graph *g, int vertex, int *permutation, int count, int permutationSize, bool *visited);
//check if every vertices has benn visited
bool isHamilton(struct Graph *g, bool *visited);

#endif