#include <iostream>
// for initializing and shutdown functions
#include <SDL2/SDL.h>
// for using SDL_Delay() functions
#include <SDL2/SDL_timer.h>
#include "Scene.hpp"


#define DEFAULT_RES_X 1000
#define DEFAULT_RES_Y 1000

int main(int argc, char** argv)
{
    std::cout << "Welcome to Alfrodo's simple 2D Engine!" << std::endl;
    std::cout << "Initializing SDL.." << std::endl;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Error initializing SDL" << std::endl;
    }

    //Set desired window size and initialize

 
    if(argc != 3)
    {
        Scene* s = new Scene(DEFAULT_RES_X, DEFAULT_RES_Y);
        s->init_Scene();
        SDL_Delay(100);
    }


}