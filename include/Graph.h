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
void generateGNP(struct Graph *g, int n, float probability);
//free memory Graph
void freeGraph(struct Graph *g);