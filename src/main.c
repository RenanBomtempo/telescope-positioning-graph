//==============================================================================
//                                    MAIN                 
//------------------------------------------------------------------------------
// DESCRIPTION: Conatins the main function of the application.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "algraph.h"

int main(int argc, char const *argv[])
{
    /* READ FILE */
    printf("\n==READING FILE==\n");
    // Check if data file name was passed as an argument
    if (argc < 2) {
        fprintf(stderr, "ERROR - No data file was passed as an argument\n");
        exit(EXIT_FAILURE);
    }

    // Open file
    FILE *fp = fopen(argv[1], "r");
    if (NULL == fp) {
        fprintf(stderr, "ERROR - The file \'%s\' couldn't be opened or it doesn't exist\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read number of telescopes
    fscanf(fp, "%d", &g_num_telescopes);

    // Array of telescope positions
    telpos *tel_positions = (telpos*)malloc(g_num_telescopes * sizeof(telpos));
    if (NULL == tel_positions) {
        fprintf(stderr, "ERROR - Couldn't allocate memory for \'telpos\' array\n");
        exit(EXIT_FAILURE);
    }

    // Read telescopes positions
    for (int i = 0; i < g_num_telescopes; i++) {
        fscanf(fp, "%f %f", &tel_positions[i].lat, &tel_positions[i].lon);
        /*log*/printf("Telescope %d:\n"
                      "    lat: %.5f\n"
                      "    lon: %.5f\n",
                      i, tel_positions[i].lat,
                         tel_positions[i].lon);
    }

    printf("==FINISHED READING FILE==\n");

    // Close data file
    fclose(fp);

    /* CREATE K GRAPH */
    edge *edges = getEdgesFromTelescopeData(tel_positions);
    graph k_graph = createGraphFromTelescopeData(g_num_telescopes, edges);
    printGraph(k_graph, g_num_telescopes);
    getEdgeArrayFromGraph(k_graph, g_num_telescopes);
    
    /* GENERATE MBST */

    // Terminate K_graph
    
    terminateGraph(k_graph, g_num_telescopes, edges);

    /* PRINT LOWEST WEIGHT ON THE MST */
    
    // Free array of positions
    free(tel_positions);
    
    return 0;    
} 
