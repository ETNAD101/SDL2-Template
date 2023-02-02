#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Message.h"
#include "Vector2.h"
#include "MouseState.h"

class Button :
    public Message
{
public:
    bool isActive = false;

public:
    Button(Vector2f p_pos, std::string p_text, TTF_Font* p_font, MouseState* p_mouse, SDL_Renderer* p_renderer);
    Button(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex, MouseState* p_mouse, SDL_Renderer* p_renderer);
    bool pressed();

private:
    MouseState* mouse;
};

