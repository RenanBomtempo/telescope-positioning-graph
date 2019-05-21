//==============================================================================
//                              GRAPH ADT [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: In this file we represent a Graph with an Adjacency List. All
//              functions needed to manipulate the graph are located here.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef ALGRAPH_H 
#define ALGRAPH_H 
#include "util.h"

/*
 * Auxilary edge struct for sorting in the camerini algorithm
 */
typedef struct Edge {
    // Vertex 1 in the edge
    int vert_1;
    // Vertex 2 in the edge
    int vert_2;
    // Weight of the edge between vert_1 and vert_2
    int weight;
} edge;

/*
 * Adjacency list representation of the graph 
 */
typedef struct GraphNode {
    // Connected vertex index
    int vert_ind;
    // Wheight of the gnode between them
    int weight;
    // Next vertex on the  list
    struct GraphNode *next;
} gnode;

/* 
 * Renaming gnode** to graph for simplicity and ease of reading the code
 */
typedef gnode **graph;

/*
 * Creates a graph with a given number of vertices but with no edges
 */
graph newEmptyGraph(int num_vertices);

/* 
 * Create the complete graph from the telescope data
 */
graph createGraphFromTelescopeData(int num_vertices, edge *edges);

/*
 * Insert a connection between two vertices in a graph using information from edge
 */
void insertGnode(graph g, edge e);

/*
 * Print a graph to the terminal
 */
void printGraph(graph g, int size);

/*
 * Free all memory allocated for all the graph structures
 */
void terminateGraph(graph g, int size, edge *e);

/*
 * Count the number of edges in an undirected graph represeted by an adjacency list
 */
int countEdges(graph g, int num_vertices);

/*
 * Create a edge array with all information provided from de telescope data
 */
edge *getEdgesFromTelescopeData(telpos *tp);

/*
 * Create an edge array of all edges in the graph
 */
edge *getEdgeArrayFromGraph(graph g, int num_vertices);

int getMedianWeight(int *w, int size);

/* Camerini Algorithm */
/*
 * Recursive function 
 */
int MBST(graph g, int num_vertices, int *w, int num_w);

#endif // ALGRAPH_H  