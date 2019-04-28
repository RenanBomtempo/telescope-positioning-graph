//==============================================================================
//                              GRAPH ADT [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: Graph represented as an array of edges.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef ALGRAPH_H 
#define ALGRAPH_H 
#include "util.h"

/* 
 * Edge of a graph.
 */
typedef struct Edge {
    // Index of first vertex of the edge.
    int vert_1;
    // Index of second vertex of the edge.
    int vert_2;
    // Weight of the edge.
    int weight;    
} edge;

/*
 * Allocate memory for a set of edges that compose a graph.
 */
edge *newEmptyGraph(int n_edges);

/*
 * Create a graph given all telescopes positions.
 */
edge *createKGraphFromTelescopeData(telpos *positions); 

/*
 * Free all memory allocated for a graph.
 */
void terminateGraph(edge *graph);

/*
 * Generate the Minimum Spanning Tree associated with the given graph
 */
edge *getMST(edge *graph, int size); 

/*
 * Get the lowest edge weight in the graph.
 */
int getLowestWeight(edge *graph, int size);

/*
 * Print a graph for debugging purposes.
 */
void printGraph(edge *graph, int size);

/*
 * Sort the graph by the size of the edges.
 */
void quickSortGraph(edge *graph, int start, int end);

/*
 * Partition the graph for sorting.
 */
int partition(edge *graph, int start, int end);

/*
 * Swap two edges in a graph.
 */
void swap(edge *graph, int e1, int e2);


#endif // ALGRAPH_H  