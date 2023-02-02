#pragma once

#include <iostream>

struct MouseState
{
    MouseState()
        :x(0.0f), y(0.0f)
    {
        down = false;
    }

    MouseState(int p_x, int p_y, bool p_down)
        :x(p_x), y(p_y)
    {
        down = p_down;
    }

    void print()
    {
        std::cout << "X: " << x << ", Y: " << y << ", Down: " << down << std::endl;
    }

    int x, y;
    bool down;
};