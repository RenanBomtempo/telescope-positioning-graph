//==============================================================================
//                              GRAPH ADT [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: In this file we represent a Graph with an Adjacency List. All
//              functions needed to manipulate the graph are located here.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "algraph.h"
#include "util.h"

graph newEmptyGraph(int num_vertices) {
    // Allocate memory for the array of vertices
    graph graph = malloc(num_vertices * sizeof(gnode*));
    
    for (int i = 0; i < num_vertices; i++) {
        graph[i] = NULL;
    }

    return graph;
}

edge *getEdgesFromTelescopeData(telpos *tp) {
    printf("\n==CREATING EDGE ARRAY==\n");
    // Number of edges for the complete graph
    int num_edges = g_num_telescopes * (g_num_telescopes - 1)/2;

    // Auxilary variable for counting edges
    int count = 0;

    // Array of edges
    edge *edges = (edge*)malloc(num_edges * sizeof(edge));
    if (edges == NULL) exit(EXIT_FAILURE);

    for (int i = 0; i < g_num_telescopes; i++) {
        for (int j = i+1; j < g_num_telescopes; j++) {
            edges[count].vert_1 = i;
            edges[count].vert_2 = j;
            edges[count++].weight = distEarthKm(tp[i].lat, tp[i].lon, 
                                                tp[j].lat, tp[j].lon);
        }
    }
    printf("==FINISHED CREATING EDGE ARRAY==\n");
    return edges;
}

graph createGraphFromTelescopeData(int num_vertices, edge *edges) {
    printf("\n==CREATING COMPLETE GRAPH==\n");

    // New empty graph (contains no edges)
    graph k_graph = newEmptyGraph(num_vertices);

    // Number of edges of the complete graph
    int num_edges = num_vertices * (num_vertices - 1)/2;

    // Connect each vertex in the adjecency list according to edges
    for (int i = 0; i < num_edges; i++) {
        insertGnode(k_graph, edges[i]);
    }

    printf("==FINISHED CREATING COMPLETE GRAPH==\n");
  
    return k_graph;
}

void insertGnode(graph g, edge e) {
    printf("New gnode (%d, %d) -> weight = %d\n", e.vert_1, e.vert_2, e.weight);
    gnode *new_gnode, *ptr;
    
    // Insert gnode (vert_1, vert_2)
    // Allocate memory for a new gnode
    new_gnode = (gnode*)malloc(sizeof(gnode));
    if (new_gnode == NULL) exit(EXIT_FAILURE);

    // Set gnode values using the passed parameters
    new_gnode->vert_ind = e.vert_2;
    new_gnode->weight = e.weight;
    new_gnode->next = NULL;

    // Get pointer to vert_1
    if (g[e.vert_1] == NULL) g[e.vert_1] = new_gnode;
    else {
        ptr = g[e.vert_1];

        // Find last gnode of vert_1
        while (ptr->next != NULL) ptr = ptr->next;

        // Insert gnode in the vert_1 list
        ptr->next = new_gnode;
    }

    // Insert gnode (vert_2, vert_1)
    // Allocate memory for a new gnode
    new_gnode = (gnode*)malloc(sizeof(gnode));
    if (new_gnode == NULL) exit(EXIT_FAILURE);

    // Set gnode values using the passed parameters
    new_gnode->vert_ind = e.vert_1;
    new_gnode->weight = e.weight;
    new_gnode->next = NULL;

    // Get pointer to vert_2
    if (g[e.vert_2] == NULL) g[e.vert_2] = new_gnode;
    else {
        ptr = g[e.vert_2];

        // Find last gnode of vert_2
        while (ptr->next != NULL) ptr = ptr->next;

        // Insert gnode in the vert_2 list
        ptr->next = new_gnode;
    }
}

int countEdges(graph g, int num_vertices) {
    // Count variable
    int count = 0;
    
    // Travelling pointer
    gnode *ptr;

    /* We count the number of connections of all vertices. Since it's an *
     * undirected graph, we simply devide that count by two at the end.  */
    for (int i = 0; i < num_vertices; i++) {
        ptr = g[i];

        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
    }

    return count/2;
}

char edgeIsAlreadyInArray(edge *arr, int size, edge e) {
    for (size_t i = 0; i < size; i++)
    {
        if ( ((e.vert_1 == arr[i].vert_1 && e.vert_2 == arr[i].vert_2) ||
              (e.vert_1 == arr[i].vert_2 && e.vert_2 == arr[i].vert_1)) &&
               e.weight == arr[i].weight) {
            return 1;       
        } 
    }

    return 0;
}

edge *getEdgeArrayFromGraph(graph g, int num_vertices) {
    int num_edges = countEdges(g, num_vertices);
    edge *e_arr = (edge*)malloc(num_edges * sizeof(edge));
    if (e_arr == NULL) exit(EXIT_FAILURE);

    // FIll with default values
    for (int i = 0; i < num_edges; i++) {
        e_arr[i].vert_1 = -1;
        e_arr[i].vert_2 = -1;
        e_arr[i].weight = -1;
    }
    
    int edge_count = 0;
    edge tmp;

    for (int i = 0; i < num_vertices; i++) {
        gnode *ptr = g[i];

        while (ptr != NULL) {
            tmp.vert_1 = i;
            tmp.vert_2 = ptr->vert_ind;
            tmp.weight = ptr->weight;

            if (!edgeIsAlreadyInArray(e_arr, num_edges, tmp)) {
                e_arr[edge_count].vert_1 = tmp.vert_1;
                e_arr[edge_count].vert_2 = tmp.vert_2;
                e_arr[edge_count++].weight = tmp.weight;
            }

            ptr = ptr->next;
        }
    }
    
    for (int i = 0; i < num_edges; i++)
    {
        printf("Edge (%d, %d) -> %d\n", e_arr[i].vert_1, e_arr[i].vert_2, e_arr[i].weight);
    }
    

    return e_arr;
}

int getMedianWeight(int *w, int size) {
    
}

int MBST(graph g, int num_vertices, int *w, int num_w) {
    edge *E = getEdgeArrayFromGraph(g, num_vertices);
    int w_median = getMedianWeight(E, num_w);


    if (countEdges(g, num_vertices) != 1) {
        // A <- half edges in E whose weights are no less than the median weight
        // B <- E - A
        // F <- forest of GB
        // if F is a spanning tree then
        //     return MBST(GB,w)
        // else
        //     return MBST((GA)η, w)   
    } else return 0;

}

void printGraph(graph g, int size) {
    printf("\n==PRINTING ADJACENCY LIST==\n");
    for (int i = 0; i < size; i++) {
        printf("(%d)", i);
        if (g[i] != NULL) {
            gnode *ptr = g[i];
            do {
                printf("->[%d,%d]", ptr->vert_ind, ptr->weight);
                ptr = ptr->next;
            }
            while (ptr != NULL);
            printf("\n");
        }
    }
    printf("==FINISHED PRINTING ADJACENCY LIST==\n");
}

void terminateGraph(graph g, int size, edge *e) {
    printf("\n==TERMINATING COMPLETE GRAPH==\n");
    gnode *ptr, *tmp;
    for (int i = 0; i < size; i++) {
        // Auxilary pointer
        ptr = g[i];

        while (ptr->next != NULL) {
            tmp = ptr;
            ptr = ptr->next;

            // Free connection to vertex i
            free(tmp);
        }

        // Free vertex
        free(ptr);
    }

    // Free whole graph
    free(g);

    // Free edges array
    free(e);
}
