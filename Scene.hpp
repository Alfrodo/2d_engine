#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL2/SDL.h>
#include "ImageFormats.hpp"
#include "defines.hpp"

class Scene
{
    private:
        SDL_Window* window_;
        int x_;
        int y_;
        SDL_Renderer* rend_;
        SDL_Surface* surface_;

        void draw_rgb_img(RGB** rgb_img, int length, int width, Vec2D pos);

    public:
        Scene(int x, int y) : x_{x}, y_{y} {}
        int init_Scene();
        void start_Renderloop();
};

#endif