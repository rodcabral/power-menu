#include "powermenu.h"

void init(App* app) {
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    app->window = SDL_CreateWindow("PowerMenu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    app->renderer = SDL_CreateRenderer(app->window, -1, 0);

    app->is_running = true;
}

void render(App* app) {
    SDL_SetRenderDrawColor(app->renderer, 0x27, 0x2e, 0x3e, 0xff);
    SDL_RenderClear(app->renderer);

    SDL_RenderPresent(app->renderer);
}
