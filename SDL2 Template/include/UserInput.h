#pragma once

#include <iostream>
#include <vector>

struct UserInput
{
    UserInput()
        :mouseX(0.0), mouseY(0.0)
    {
        mouseDown = false;
    }

    UserInput(int p_x, int p_y, bool p_mouseDown)
        :mouseX(p_x), mouseY(p_y)
    {
        mouseDown = p_mouseDown;
    }

    void print()
    {
        std::cout << "mouseX: " << mouseX << ", mouseY: " << mouseY << ", mouseDown: " << mouseDown << ", Keys Down: ";
        for (int key : keysDown)
        {
            std::cout << key << ", ";
        }
    }

    void addKey(int p_key)
    {
        if (!std::count(keysDown.begin(), keysDown.end(), p_key))
            keysDown.push_back(p_key);
    }

    void removeKey(int p_key)
    {
        keysDown.erase(std::remove(keysDown.begin(), keysDown.end(), p_key), keysDown.end());
    }

    bool keyDown(int p_key)
    {
        if (std::find(keysDown.begin(), keysDown.end(), p_key) != keysDown.end())
        {
            return true;
        }
        return false;
    }

    int mouseX, mouseY;
    bool mouseDown;
    std::vector<int> keysDown;
};