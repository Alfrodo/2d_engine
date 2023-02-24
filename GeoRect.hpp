#ifndef GEORECT_HPP
#define GEORECT_HPP

#include "GeoFigures.hpp"
class GeoRect : public GeoFigures
{


    public:
    GeoRect(int length, int width, uint8_t r, uint8_t g, uint8_t b, uint8_t o);
    GeoRect* getRect() { return this;}
};

#endif