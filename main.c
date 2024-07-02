#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#define SUBSYSTEMS (SDL_INIT_VIDEO)

void make_a_square(SDL_Renderer* renderer, SDL_Color color, SDL_Rect* rect)
{
    SDL_SetRenderDrawColor(renderer, 39, 39, 245, 1);
    SDL_RenderFillRect(renderer, rect);
}

int main(void)
{
    int status = SDL_Init(SUBSYSTEMS);
    /* Error Handler */
    if (status != 0) {
        printf("An Error has occured: %s", SDL_GetError());
        return -1;
    }
    static const char* title = "My GAME!!";
    int x = SDL_WINDOWPOS_UNDEFINED;
    int y = SDL_WINDOWPOS_UNDEFINED;
    int w = 800;
    int h = 600;
    Uint32 flags = SDL_WINDOW_SHOWN;
    SDL_Window* window = SDL_CreateWindow(title, x, y, w, h, flags);
    SDL_ShowWindow(window);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // main loop
    // draw_random_stuff(my_surface);
    SDL_Rect myrect;
    myrect.x = w / 2;
    myrect.y = h / 2;
    myrect.w = 10;
    myrect.h = 10;
    int R = 39, G = 39, B = 245, A = 1;
    SDL_Color color = { 39, 39, 245, 1 };

    SDL_Event test_event;
    /*
     * Main Event Loop of the game
     */
    SDL_SetMainReady();
    for (; test_event.type != SDL_QUIT; SDL_PollEvent(&test_event)) {
        switch (test_event.type) {
        case SDL_QUIT:
            printf("Quitting the game\n");
            return 0;
        case SDL_KEYDOWN:
            // printf("you pressed a key\n");
            switch (test_event.key.keysym.sym) {
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
        }
        /* redraw the scene */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);

        // we can render stuff in between these calls
        make_a_square(renderer, color, &myrect);
        // update surface
        SDL_RenderPresent(renderer);
        // 60 fps limit
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_VideoQuit();
    SDL_Quit();
    return 0;
}
