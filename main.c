#include "init.h"
#include "SDL2/SDL.h"

int main() {
  game game; 
  init(&game);
  
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    std::cout << SDL_GetError() << std::endl;
    return 1;
  }
  
  SDL_Window *win = NULL;
  win = SDL_CreateWindow("Deep Space North", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == NULL) {
    std::cout << SDL_GetError() << std::endl;
    return 1;
  }
  
  SDL_Renderer *ren = NULL;
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == NULL) {
    std::cout << SDL_GetError() << std::endl;
    return 1;
  }
  
  SDL_Surface *bmp = NULL; 
  bmp = SDL_LoadBMP("./pics/titlescreen.bmp");
  if (bmp == NULL) {
    std::cout << SDL_GetError() << std::endl;
    return 1;
  }
  
  SDL_Texture *tex = NULL;
  tex = SDL_CreateTextureFromSurface(ren, bmp);
  SDL_FreeSurface(bmp);
  
  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, tex, NULL, NULL);
  SDL_RenderPresent(ren);

  print_start_message(); 
  while(!game.is_over() && game.get_command()) {
    const char *path = game.get_player()->get_curLoc()->get_path().c_str();
    std::cout << "-------------------------------" << std::endl;
    bmp = SDL_LoadBMP(path);
    tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);
    //std::cout << "---------------------------------" << std::endl;
  }
}
