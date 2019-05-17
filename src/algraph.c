//==============================================================================
//                           GRAPH ADT [implementation]                   
//------------------------------------------------------------------------------
// DESCRIPTION: Graph represented as an array of edges.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "algraph.h"
#include "util.h"

edge **newEmptyGraph(int num_vertices) {
    // Allocate memory for the array of vertices
    edge **graph = (edge**)malloc(num_vertices * sizeof(edge*));
    
    for (int i = 0; i < num_vertices; i++) {
        graph[i] = NULL;
    }

    return graph;
}

edge **createKGraph(int num_vertices, telpos *tel_positions) {
    edge **k_graph = newEmptyGraph(num_vertices);

    for (int i = 0; i < num_vertices; i++){
        for (int j = i+1; j < num_vertices; j++){
            insertEdge(k_graph, i, j, distEarthKm(tel_positions[i].lat, tel_positions[i].lon,
                                                  tel_positions[j].lat, tel_positions[j].lon));
        }
    }

    return k_graph;
}

void insertEdge(edge **graph, int vert_1, int vert_2, int weight) {
    printf("New edge (%d, %d) -> weight = %d\n", vert_1, vert_2, weight);
    edge *new_edge, *ptr;
    
    // Insert edge (vert_1, vert_2)
    // Allocate memory for a new edge
    new_edge = (edge*)malloc(sizeof(edge));
    if (new_edge == NULL) exit(EXIT_FAILURE);

    // Set edge values using the passed parameters
    new_edge->vert_ind = vert_2;
    new_edge->weight = weight;
    new_edge->next = NULL;

    // Get pointer to vert_1
    if (graph[vert_1] == NULL) graph[vert_1] = new_edge;
    else {
        ptr = graph[vert_1];

        // Find last edge of vert_1
        while (ptr->next != NULL) ptr = ptr->next;

        // Insert edge in the vert_1 list
        ptr->next = new_edge;
    }

    // Insert edge (vert_2, vert_1)
    // Allocate memory for a new edge
    new_edge = (edge*)malloc(sizeof(edge));
    if (new_edge == NULL) exit(EXIT_FAILURE);

    // Set edge values using the passed parameters
    new_edge->vert_ind = vert_1;
    new_edge->weight = weight;
    new_edge->next = NULL;

    // Get pointer to vert_2
    if (graph[vert_2] == NULL) graph[vert_2] = new_edge;
    else {
        ptr = graph[vert_2];

        // Find last edge of vert_2
        while (ptr->next != NULL) ptr = ptr->next;

        // Insert edge in the vert_2 list
        ptr->next = new_edge;
    }
}

void printGraph(edge **graph, int size) {
    printf("PRINTING ADJACENCY LIST\n");
    for (int i = 0; i < size; i++) {
        printf("(%d)", i);
        if (graph[i] != NULL) {
            edge *ptr = graph[i];
            do {
                printf("->[%d,%d]", ptr->vert_ind, ptr->weight);
                ptr = ptr->next;
            }
            while (ptr != NULL);
            printf("\n");
        }
    }
}

void terminateGraph(edge **graph, int size) {
    edge *ptr, *tmp;
    for (int i = 0; i < size; i++) {
        ptr = graph[i];
        while (ptr->next != NULL) {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
        free(ptr);
    }
    free(graph);
}