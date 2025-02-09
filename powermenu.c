#include "powermenu.h"
#include <SDL2/SDL_render.h>

void init(App* app) {
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    app->window = SDL_CreateWindow("PowerMenu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    app->renderer = SDL_CreateRenderer(app->window, -1, 0);

    app->is_running = true;

    int rect_w = 40; 
    int rect_h = 40;

    app->shutdown_rect.x = SCREEN_WIDTH / 2 - rect_w / 2;
    app->shutdown_rect.y = 8;
    app->shutdown_rect.w = rect_w;
    app->shutdown_rect.h = rect_h;

    app->reboot_rect.x = SCREEN_WIDTH / 2 - rect_w / 2;
    app->reboot_rect.y = app->shutdown_rect.y + rect_h + 8;
    app->reboot_rect.w = rect_w;
    app->reboot_rect.h = rect_h;

    app->lock_rect.x = SCREEN_WIDTH / 2 - rect_w / 2;
    app->lock_rect.y = app->reboot_rect.y + rect_h + 8;
    app->lock_rect.w = rect_w;
    app->lock_rect.h = rect_h;
}

void render(App* app) {
    SDL_SetRenderDrawColor(app->renderer, 0x27, 0x2e, 0x33, 0xff);
    SDL_RenderClear(app->renderer);

    SDL_SetRenderDrawColor(app->renderer, 0xe6, 0x73, 0x80, 0xff);
    SDL_RenderFillRect(app->renderer, &app->shutdown_rect);
    
    SDL_SetRenderDrawColor(app->renderer, 0xe6, 0x73, 0x80, 0xff);
    SDL_RenderFillRect(app->renderer, &app->reboot_rect);

    SDL_SetRenderDrawColor(app->renderer, 0xe6, 0x73, 0x80, 0xff);
    SDL_RenderFillRect(app->renderer, &app->lock_rect);

    SDL_RenderPresent(app->renderer);
}
