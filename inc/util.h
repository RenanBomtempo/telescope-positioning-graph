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
 * Number of telescopes.
 */
int g_num_telescopes;

/*
 * Telescope Position - Latitude and Longitude values of a telescope.
 */
typedef struct TelPos {   
    // Latitude.
    float lat;
    // Longitude.
    float lon;  
} telpos;

/*
 * Convert degrees to radians.
 */
double degToRad(double deg);

/*
 * Calculate spherical distance between cities.
 */
int distEarthKm(double lat1d, double lon1d, double lat2d, double lon2d);

#endif //UTIL_H