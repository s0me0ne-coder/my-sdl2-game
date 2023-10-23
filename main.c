#include <SDL2/SDL.h>
#include <stdio.h>

#define SUBSYSTEMS (SDL_INIT_VIDEO)

/* does initialization, returns negative error code to get caught in main */
int my_sdl_init(void) {
    /* NULL means default video driver */
    int error = SDL_Init(SUBSYSTEMS);
    if(error != 0) return error;
    return 0;
}

int main(void)
{
    int status = my_sdl_init();
    /* Error Handler */
    if (status != 0)
    {
        printf("An Error has occured: %s",SDL_GetError());
        return -1;
    }
    const char * title = "My GAME!!";
    int x = SDL_WINDOWPOS_UNDEFINED;
    int y = SDL_WINDOWPOS_UNDEFINED;
    int w = 800;
    int h = 600;
    Uint32 flags = SDL_WINDOW_SHOWN;
    SDL_Window * window =  SDL_CreateWindow(title,
                                 x, y, w,
                                 h, flags);
    SDL_ShowWindow (window);
    SDL_Event test_event;
    while (1) {
        SDL_PollEvent (&test_event);
        switch(test_event.type) {
        case SDL_QUIT:
            printf("Quitting the game\n");
            return 0;
        }
    }
    SDL_SetMainReady ();
    SDL_VideoQuit ();
    SDL_Quit();
    return 0;
}
