#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
#include <stdio.h>

#define SUBSYSTEMS (SDL_INIT_VIDEO)
int main(void) {
  int status = SDL_Init(SUBSYSTEMS);
  /* Error Handler */
  if (status != 0) {
    printf("An Error has occured: %s", SDL_GetError());
    return -1;
  }
  const char *title = "My GAME!!";
  int x = SDL_WINDOWPOS_UNDEFINED;
  int y = SDL_WINDOWPOS_UNDEFINED;
  int w = 800;
  int h = 600;
  Uint32 flags = SDL_WINDOW_SHOWN;
  SDL_Window *window = SDL_CreateWindow(title, x, y, w, h, flags);
  SDL_ShowWindow(window);
  SDL_Surface *my_surface = SDL_GetWindowSurface(window);
  // main loop
  // draw_random_stuff(my_surface);
  SDL_Rect myrect;
  myrect.x = w / 2;
  myrect.y = h / 2;
  myrect.w = 10;
  myrect.h = 10;
  int R = 39, G = 39, B = 245, A = 1;
  int color = SDL_MapRGBA(my_surface->format, R, G, B, A);

  SDL_FillRect(my_surface, &myrect, color);
  SDL_UpdateWindowSurface(window);
  SDL_Event test_event;
  /*
   * Main Event Loop of the game
   */
  for (; test_event.type != SDL_QUIT; SDL_PollEvent(&test_event)) {
    switch (test_event.type) {
    case SDL_QUIT:
      printf("Quitting the game\n");
      return 0;
    case SDL_KEYDOWN:
      printf("you pressed a key\n");
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
      // black out the canvas
      SDL_FillRect(my_surface, NULL, 0);
      // write new rectangle to canvas
      SDL_FillRect(my_surface, &myrect, color);
      // update window
      SDL_UpdateWindowSurface(window);
      R *= 2;
      G *= 2;
      B *= 2;
      color = SDL_MapRGBA(my_surface->format, R, G, B, A);
    }
  }
  SDL_SetMainReady();
  SDL_VideoQuit();
  SDL_Quit();
  return 0;
}
