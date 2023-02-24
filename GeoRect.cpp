#include "GeoRect.hpp"
#include <iostream>

GeoRect::GeoRect(int length, int width, uint8_t r, uint8_t g, uint8_t b, uint8_t o)
{
    length_ = length;
    width_ = width;

    
    RGB** arr = new RGB*[length];
    for(int i = 0; i < length; i++)
    {
        arr[i] = new RGB[width];
    }
    img_ = arr;

    //Fill the Rect with desired values
    //Background
    for (int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            img_[i][j] = RGB{r ,g ,b, 255}; 
        }
    }
    

}