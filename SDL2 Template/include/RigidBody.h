#pragma once
#include "Entity.h"
#include "MouseState.h"


class RigidBody : public Entity
{
public:
	RigidBody(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex, MouseState* p_mouse);
	void move(float x, float y);
	bool boxCollision(Entity& e);
private:
	Vector2f velocity;
	MouseState* mouse;
};
