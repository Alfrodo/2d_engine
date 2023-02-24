#include "GeoFigures.hpp"
#include "GeoRect.hpp"
#include <iostream>

GeoRect* GeoFigures::createRect(int length, int width, uint8_t r, uint8_t g, uint8_t b, uint8_t o)
{
    GeoRect* rect = new GeoRect(length, width, r, g, b, o); 
    return rect->getRect();
}