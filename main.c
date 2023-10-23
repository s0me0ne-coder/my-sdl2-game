#include <SDL2/SDL.h>
#include <stdio.h>

/* does initialization, returns negative error code to get caught in main */
int my_sdl_init(void) {
    /* NULL means default video driver */
    int error = SDL_VideoInit(NULL);
    if(error != 0) return error;
    return 0;
}

int main()
{
    int status = my_sdl_init();
    /* Error Handler */
    if (status != 0)
    {
        printf("An Error has occured: %s",SDL_GetError());
        return -1;
    }
    SDL_VideoQuit ();
    SDL_Quit();
}
