#include "Scene.hpp"
#include "Window_Handler.hpp"
#include <iostream>
#include "GeoFigures.hpp"
#include "GeoRect.hpp"

#define MOVEMENTSPEED 5

int Scene::init_Scene()
{
    window_ = Window_Handler::create_Window(x_, y_);
    if(!window_)
    {
        std::cout << "Error creating Window!\n";
        return -1;
    }
    start_Renderloop();

    return 0;
}

void Scene::start_Renderloop()
{
    SDL_Event e;
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    rend_ = SDL_CreateRenderer(window_, -1, render_flags);
    bool quit = false;

    //Create Assets to use
    //Create some rect
    GeoRect* rect = GeoFigures::createRect(300, 200, 100, 0, 100, 50);


    while (!quit){
        
         while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                switch( e.key.keysym.sym ){
                    case SDLK_LEFT:
                        //Set new position of rect
                        rect->translate(Vec2D{-MOVEMENTSPEED,0});
                        break;
                    case SDLK_RIGHT:
                        rect->translate(Vec2D{MOVEMENTSPEED,0});
                        break;
                    case SDLK_UP:
                        rect->translate(Vec2D{0,-MOVEMENTSPEED});
                        break;
                    case SDLK_DOWN:
                        rect->translate(Vec2D{0,MOVEMENTSPEED});
                        break;
                    default:
                        break;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }

        //Clear the Scene
        SDL_SetRenderDrawColor(rend_, 0, 0, 0, 0);
        SDL_RenderClear(rend_); 


        //Drawing
        SDL_SetRenderDrawColor(rend_, 255, 0, 0, 255);
        
        

        draw_rgb_img(rect->getImg(), rect->getLength(), rect->getWidth(), rect->getPosition());


        
        //Present
        SDL_RenderDrawLine(rend_, 0, 0, 500, 500);
        SDL_RenderPresent(rend_);
         }
    }
}

void Scene::draw_rgb_img(RGB** rgb_img, int length, int width, Vec2D pos)
{
    for(int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            SDL_SetRenderDrawColor(rend_, rgb_img[i][j].r, rgb_img[i][j].g, rgb_img[i][j].b, rgb_img[i][j].o);
            SDL_RenderDrawPoint(rend_, i + pos.x, j + pos.y);
        }
    }
}