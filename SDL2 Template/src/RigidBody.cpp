#include "RigidBody.h"
#include "Entity.h"
#include "MouseState.h"

RigidBody::RigidBody(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex, MouseState* p_mouse)
    :Entity(p_pos, p_w, p_h, p_tex), mouse(p_mouse)
{
    velocity.x = 0;
    velocity.y = 0;
}

void RigidBody::move(float x, float y)
{
    velocity.x = x;
    velocity.y = y;
}

bool RigidBody::boxCollision(Entity& e)
{
    return (
            (this->top() + this->velocity.y < e.bottom()) &&
            (this->bottom() + this->velocity.y > e.top()) &&
            (this->left() + this->velocity.x < e.right()) &&
            (this->right() + this->velocity.x > e.left())
            );
}