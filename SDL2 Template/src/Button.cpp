#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Button.h"
#include "Vector2.h"
#include "MouseState.h"

Button::Button(Vector2f p_pos, std::string p_text, TTF_Font* p_font, MouseState* p_mouse, SDL_Renderer* p_renderer)
	:Message(p_pos, p_text, p_font, p_renderer), mouse(p_mouse)
{}

Button::Button(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex, MouseState* p_mouse, SDL_Renderer* p_renderer)
	:Message(p_pos, NULL, NULL, p_renderer), mouse(p_mouse)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = p_w;
	rect.h = p_h;

	this->setCurrentFrame(rect);
	this->setTex(p_tex);

}

bool Button::pressed()
{
	if (mouse->down)
	{
		return this->touching(mouse->x, mouse->y);
	}
	return false;
}