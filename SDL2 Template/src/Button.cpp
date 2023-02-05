#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Button.h"
#include "Vector2.h"
#include "UserInput.h"

Button::Button(Vector2f p_pos, std::string p_text, TTF_Font* p_font, UserInput* p_input, SDL_Renderer* p_renderer)
	:Message(p_pos, p_text, p_font, p_renderer), input(p_input)
{}

Button::Button(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex, UserInput* p_input, SDL_Renderer* p_renderer)
	:Message(p_pos, NULL, NULL, p_renderer), input(p_input)
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
	if (input->mouseDown)
	{
		return this->touching(input->mouseX, input->mouseY);
	}
	return false;
}