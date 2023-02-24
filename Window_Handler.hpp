#include <SDL2/SDL.h>

class Window_Handler
{
    public:
    //create Window with desired resolution
    static SDL_Window* create_Window(int x, int y);
};