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
    // Check if data file name was passed as an argument
    if (argc < 2) 
    {
         fprintf(stderr, "ERROR - No data file was passed as an argument\n");
        exit(EXIT_FAILURE);
    }

    // Open file
    FILE *fp = fopen(argv[1], "r");
    if (NULL == fp) 
    {
        fprintf(stderr, "ERROR - The file \'%s\' couldn't be opened or it doesn't exist\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* READ DATA */

    // Close data file
    fclose(fp);

    /* CREATE Kn GRAPH*/

    /* GENERATE MST */

    /* PRINT LOWEST WEIGHT ON THE MST */
    
    return 0;    
} 
