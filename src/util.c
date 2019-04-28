//==============================================================================
//                        UTILITIES [implementation]                   
//------------------------------------------------------------------------------
// DESCRIPTION: Utility functions implementations.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"
#define PI 3.14159265359
#define earthRadiusKm 6371.0

double degToRad(double deg)
{
    return (deg * PI / 180);
}

int distEarthKm(double lat1d, double lon1d, double lat2d, double lon2d)
{
    double lat1r, lat2r, lon1r, lon2r, u, v;

    // Convert degrees to radians
    lat1r = degToRad(lat1d);
    lon1r = degToRad(lon1d);
    lat2r = degToRad(lat2d);
    lon2r = degToRad(lon2d);

    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);

    return (int) 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}