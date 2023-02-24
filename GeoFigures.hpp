#ifndef GEOFIGURES_HPP
#define GEOFIGURES_HPP

#include <cstdint>
#include "ImageFormats.hpp"
#include "defines.hpp"

class GeoRect;

class GeoFigures
{

    public:
        void rotateFigure(int deg);
        void moveFigure(int delta_x, int delta_y);
        static GeoRect* createRect(int length, int width, uint8_t r, uint8_t g, uint8_t b, uint8_t o);
        RGB** getImg() {return img_;};

        //Getter
        int getLength() {return length_;};
        int getWidth() {return width_;};
        Vec2D getPosition() {return pos_;};

        //Setter
        //Used to set an absolute value for the position
        int setPosition(Vec2D pos) {pos_ = pos; return 0;};
        //Move from the current position and returns the current position
        Vec2D translate(Vec2D delta) {pos_.x += delta.x; pos_.y += delta.y; return pos_;};

    protected:
        RGB** img_;
        int length_;
        int width_;
        Vec2D pos_ = {0 , 0}; //Standard spawn
        
};

#endif