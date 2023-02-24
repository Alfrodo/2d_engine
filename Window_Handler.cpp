#include "Window_Handler.hpp"

SDL_Window* Window_Handler::create_Window(int x, int y)
{
    
    return SDL_CreateWindow("Alfrodo\'s engine",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       x, y, 0);
}