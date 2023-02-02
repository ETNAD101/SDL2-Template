#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <cmath>
#include <Vector2.h>
#include <entity.h>

Entity::Entity(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex)
    :pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_w;
    currentFrame.h = p_h;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::setCurrentFrame(SDL_Rect p_rect)
{
    currentFrame = p_rect;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

void Entity::setTex(SDL_Texture* p_tex)
{
    tex = p_tex;
}

// Position Setters

void Entity::setPos(float p_x, float p_y)
{
    setX(p_x);
    setY(p_y);
}

void Entity::setX(float p_x)
{
    pos.x = p_x - currentFrame.w / 2;
}

void Entity::setY(float p_y)
{
    pos.y = p_y - currentFrame.h / 2;
}

// Position Getters

Vector2f& Entity::getPos()
{
    return pos;
}

float Entity::top()
{
    return pos.x - currentFrame.h / 2;
}

float Entity::bottom()
{
    return pos.x + currentFrame.h / 2;
}

float Entity::left()
{
    return pos.x - currentFrame.w / 2;
}

float Entity::right()
{
    return pos.x + currentFrame.w / 2;
}

// Collision

bool Entity::touching(int p_x, int p_y)
{
    bool a = p_y > top();
    bool b = p_y < bottom();
    bool c = p_x > left();
    bool d = p_x < right();
    return a && b && c && d;
}