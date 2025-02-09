#ifndef _POWER_MENU_H_
#define _POWER_MENU_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#define SCREEN_WIDTH 150
#define SCREEN_HEIGHT 150

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool is_running;

    SDL_Rect shutdown_rect, reboot_rect, lock_rect;

    SDL_Texture* shutdown_ttf;
    SDL_Texture* reboot_ttf;
    SDL_Texture* lock_ttf;

    SDL_Rect aux_rect;
    SDL_Rect base_rect[3];
} App;

void init(App* app);

void render(App* app);

void events(App* app);

SDL_Texture* load_text(App* app, const char* txt);

#endif
