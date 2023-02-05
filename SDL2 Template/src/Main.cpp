#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Settings.h"
#include "RenderWindow.h"
#include "Vector2.h"
#include "UserInput.h"
#include "Entity.h"
#include "RigidBody.h"
#include "Message.h"
#include "Button.h"

// Delta time variables
Uint64 NOW = SDL_GetPerformanceCounter();
Uint64 LAST = 0;
double deltaTime = 0;

// Create window
RenderWindow window(TITLE, WIDTH, HEIGHT);

// Creating Variables
SDL_Event event;
bool running = true;

UserInput input;

int i = 0;

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed, ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed, ERROR: " << SDL_GetError() << std::endl;

    if (TTF_Init() != 0)
        std::cout << "TTF_init has failed, ERROR: " << SDL_GetError() << std::endl;
}

void events()
{
    // Event loop
    while (SDL_PollEvent(&event))
    {
        // Events
        SDL_PumpEvents();  // make sure we have the latest mouse state.

        switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            input.mouseDown = true;
            break;

        case SDL_MOUSEBUTTONUP:
            input.mouseDown = false;
            break;

        case SDL_QUIT:
            running = false;
            break;

        case SDL_KEYDOWN:
            input.addKey(event.key.keysym.sym);
            break;

        case SDL_KEYUP:
            input.removeKey(event.key.keysym.sym);
            break;

        default:
            break;
        }
    }
}

void update()
{
    // Calculates delta time
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();
    deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
    
    SDL_GetMouseState(&input.mouseX, &input.mouseY);

}



void graphics()
{
    // Clearing
    window.clear();

    // Adding Entities to Renderer
    window.background(255, 255, 255, 255);

    // Displaying Renderer
    window.display();
}

int main(int argc, char* argv[])
{
    while (running)
    {
        graphics();
        events();
        update();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}