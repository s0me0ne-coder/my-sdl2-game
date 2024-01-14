#include <SDL2/SDL.h>
#include <stdio.h>

#define SUBSYSTEMS (SDL_INIT_VIDEO)

/* does initialization, returns negative error code to get caught in main */
int my_sdl_init(void) {
    /* NULL means default video driver */
    int error = SDL_Init(SUBSYSTEMS);
    return error;
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
    SDL_Surface * my_surface = SDL_GetWindowSurface (window);
    // main loop
    //draw_random_stuff(my_surface);
    SDL_Rect myrect;
    myrect.x = w/2;
    myrect.y = h/2;
    myrect.w = 10;
    myrect.h = 10;
    int color = SDL_MapRGBA(
        my_surface->format,
        39,
        39,
        245,
        1
    );

    SDL_FillRect(my_surface, &myrect, color);
    SDL_UpdateWindowSurface (window);
    SDL_Event test_event;
    while (1) {
        SDL_PollEvent (&test_event);
        switch(test_event.type) {
        case SDL_QUIT:
            printf("Quitting the game\n");
            return 0;
        case SDL_KEYDOWN:
            printf("you pressed a key\n");
            switch(test_event.key.keysym.sym) {
            case SDLK_w:
                myrect.y -= 10;
                break;
            case SDLK_s:
                myrect.y += 10;
                break;
            case SDLK_a:
                myrect.x -= 10;
                break;
            case SDLK_d:
                myrect.x += 10;
                break;
            }
            // black out the canvas
            SDL_FillRect(my_surface, NULL, 0);
            // write new rectangle to canvas
            SDL_FillRect(my_surface, &myrect, color);
            // update window
            SDL_UpdateWindowSurface(window);
        }
    }
    SDL_SetMainReady ();
    SDL_VideoQuit ();
    SDL_Quit();
    return 0;
}
