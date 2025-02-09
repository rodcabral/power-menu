#ifndef _POWER_MENU_H_
#define _POWER_MENU_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#define SCREEN_WIDTH 200
#define SCREEN_HEIGHT 300

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool is_running;
} App;

void init(App* app);

void render(App* app);

#endif
