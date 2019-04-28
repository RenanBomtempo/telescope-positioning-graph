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

edge *newEmptyGraph(int n_edges)
{
    // Allocate memory
    edge *graph = (edge*)malloc(n_edges * sizeof(edge));

    // Check for allocation error
    if (NULL == graph) 
    {
        fprintf(stderr, "ERROR - Couldn't allocate memory for graph\n");
        exit(EXIT_FAILURE);
    }

    return graph;
}   

void terminateGraph(edge *graph)
{
    free(graph);
}   

edge *createKGraphFromTelescopeData(telpos *positions) 
{
    // Number of edges in the K graph.
    int num_edges = g_num_telescopes * (g_num_telescopes - 1)/2;
    
    // Counter for populating the graph.
    int count = 0;

    // Allocate memory
    edge *k_graph = newEmptyGraph(num_edges);

    // Fill in the K graph. 
    for (int i = 0; i < g_num_telescopes; i++)
    {
        for (int j = i+1; j < g_num_telescopes; j++)
        {
            k_graph[count].vert_1 = i;
            k_graph[count].vert_2 = j;
            k_graph[count].weight = distEarthKm(positions[i].lat, positions[i].lon,
                                                positions[j].lat, positions[j].lon);
            count++;
        }
    }

    return k_graph;
} 

void printGraph(edge *graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Edge %d:\n"
               "    vert_1: %d\n"
               "    vert_2: %d\n"
               "    weight: %d\n",
               i, graph[i].vert_1,
                  graph[i].vert_2,
                  graph[i].weight);
    }
}

void quickSortGraph(edge *graph, int start, int end)
{
    if (start < end)
    {
        int part_index = partition(graph, start, end);

        // Sort first partition
        quickSortGraph(graph, start, part_index - 1);

        // Sort second partition
        quickSortGraph(graph, part_index + 1, end);
    }
}

int partition(edge *graph, int start, int end)
{
    int pivot = graph[end].weight;
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) 
    { 
        if (graph[j].weight <= pivot) 
        { 
            i++; 
            swap(graph, i, j); 
        } 
    } 
    swap(graph, i + 1, end); 

    return (i + 1); 
}

void swap(edge *graph, int e1, int e2)
{
    int tmp;

    // Swap vert_1
    tmp = graph[e1].vert_1;
    graph[e1].vert_1 = graph[e2].vert_1;
    graph[e2].vert_1 = tmp;

    // Swap vert_2
    tmp = graph[e1].vert_2;
    graph[e1].vert_2 = graph[e2].vert_2;
    graph[e2].vert_2 = tmp;

    // Swap weight
    tmp = graph[e1].weight;
    graph[e1].weight = graph[e2].weight;
    graph[e2].weight = tmp;
}
