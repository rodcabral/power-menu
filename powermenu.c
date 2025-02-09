#include "powermenu.h"

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

    app->shutdown_ttf = load_text(app, "⏻");
    app->reboot_ttf = load_text(app, "");
    app->lock_ttf = load_text(app, "");

    for(int i = 0; i < 3; ++i) {
        app->base_rect[i].w = app->aux_rect.w;
        app->base_rect[i].h = app->aux_rect.h;
    }

    app->base_rect[0].x = (app->shutdown_rect.x + app->shutdown_rect.w / 2 - app->aux_rect.w / 2);
    app->base_rect[0].y = (app->shutdown_rect.y + app->shutdown_rect.h / 2 - app->aux_rect.h  / 2);

    app->base_rect[1].x = (app->reboot_rect.x + app->reboot_rect.w / 2 - app->aux_rect.w / 2);
    app->base_rect[1].y = (app->reboot_rect.y + app->reboot_rect.h / 2 - app->aux_rect.h  / 2);

    app->base_rect[2].x = (app->lock_rect.x + app->lock_rect.w / 2 - app->aux_rect.w / 2);
    app->base_rect[2].y = (app->lock_rect.y + app->lock_rect.h / 2 - app->aux_rect.h  / 2);
}

SDL_Texture* load_text(App* app, const char* txt) {
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/JetBrainsMono/JetBrainsMonoNerdFont-Medium.ttf", 23);

    if(!font) {
        fprintf(stderr, "could not open font.\n");
    }

    SDL_Color color = {
        .r = 0x2d,
        .g = 0x35,
        .b = 0x3b,
        .a = 0xff
    };

    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, txt, color);

    app->aux_rect.w = surface->w;
    app->aux_rect.h = surface->h;

    SDL_Texture* text = SDL_CreateTextureFromSurface(app->renderer, surface);

    TTF_CloseFont(font);
    SDL_FreeSurface(surface);

    return text;
}

void events(App* app) {
    SDL_Event event;

    SDL_PollEvent(&event);

    int clickX, clickY;

    switch(event.type) {
        case SDL_QUIT:
            app->is_running = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    app->is_running = false;
                    break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    SDL_GetMouseState(&clickX, &clickY);
                    
                    if((clickX >= app->shutdown_rect.x && clickX <= app->shutdown_rect.x + app->shutdown_rect.w) && (clickY >= app->shutdown_rect.y && clickY <= app->shutdown_rect.y + app->shutdown_rect.h)) {
                        system("shutdown -h 0");
                    }
                        
                    if((clickX >= app->reboot_rect.x && clickX <= app->reboot_rect.x + app->reboot_rect.w) && (clickY >= app->reboot_rect.y && clickY <= app->reboot_rect.y + app->reboot_rect.h)) {
                        system("reboot");
                    }

                    if((clickX >= app->lock_rect.x && clickX <= app->lock_rect.x + app->lock_rect.w) && (clickY >= app->lock_rect.y && clickY <= app->lock_rect.y + app->lock_rect.h)) {
                        system("");
                    }

                    break;
            }
            break;
    }
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

    SDL_RenderCopy(app->renderer, app->shutdown_ttf, NULL, &app->base_rect[0]);
    SDL_RenderCopy(app->renderer, app->reboot_ttf, NULL, &app->base_rect[1]);
    SDL_RenderCopy(app->renderer, app->lock_ttf, NULL, &app->base_rect[2]);

    SDL_RenderPresent(app->renderer);
}
