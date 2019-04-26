//==============================================================================
//                        UTILITIES [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: Utility functions, structs, and global variables.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef UTIL_H
#define UTIL_H

/*
 * Number of telescopes
 */
int g_num_telescopes;

/*
 * Telescope Position - Latitude and Longitude values of a telescope.
 */
typedef struct TelPos {   
    // Latitude
    float lat;
    // Longitude
    float lon;  
} telpos;


#endif //UTIL_H