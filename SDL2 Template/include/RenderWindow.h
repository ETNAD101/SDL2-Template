#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include "entity.h"


class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);

    // loading assets
    SDL_Texture* loadTexture(const char* p_filePath);
    TTF_Font* loadFont(const char* p_fontPath, int p_size);

    // Rendering
    void clear();
    void background(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void background(SDL_Texture* p_tex);
    void render(Entity& p_e);
    void display();
    void cleanUp();

    // Getters
    SDL_Renderer* getRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
