#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <cmath>
#include <Vector2.h>


class Entity
{
public:
    Entity(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex);
    SDL_Rect getCurrentFrame();
    void setCurrentFrame(SDL_Rect p_rect);
    SDL_Texture* getTex();
    void setTex(SDL_Texture* p_tex);

    // Position Setters
    void setPos(float p_x, float p_y);
    void setX(float p_x);
    void setY(float p_y);

    // Position Getters
    Vector2f& getPos();
    float top();
    float bottom();
    float left();
    float right();

    // Collision
    bool touching(int p_x, int p_y);
    bool boxCollision(Entity& p_e);

private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};