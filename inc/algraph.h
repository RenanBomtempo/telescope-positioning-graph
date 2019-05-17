//==============================================================================
//                              GRAPH ADT [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: In this file we represent a Graph
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef ALGRAPH_H 
#define ALGRAPH_H 
#include "util.h"

/*
 * Adjacency list representation of the graph 
 */
typedef struct Edge {
    // Connected vertex index
    int vert_ind;
    // Wheight of the edge between them
    int weight;
    // Next vertex on the  list
    struct Edge *next;
} edge;

/*
 * Allocate memory for a set of edges that compose a graph.
 */
edge **newEmptyGraph(int num_vertices);
edge **createKGraph(int num_vertices, telpos *tel_positions);
void insertEdge(edge **graph, int vert_1, int vert_2, int weight);
void printGraph(edge **graph, int size);
void terminateGraph(edge **graph, int size);

#endif // ALGRAPH_H  