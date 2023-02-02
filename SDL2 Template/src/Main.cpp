#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <vector>
#include <string>
#include "RenderWindow.h"
#include "Vector2.h"
#include "Entity.h"
#include "Message.h"
#include "Button.h"
#include "MouseState.h"
#include "Settings.h"

// Delta time variables
Uint64 NOW = SDL_GetPerformanceCounter();
Uint64 LAST = 0;
double deltaTime = 0;

// Create window
RenderWindow window(TITLE, WIDTH, HEIGHT);

// Creating Variables
SDL_Event event;
bool running = true;

MouseState mouse;

int i = 0;

Button b = Button(Vector2f(WIDTH / 2, HEIGHT / 2), "0", window.loadFont(FONT_PATH, 50), &mouse, window.getRenderer());

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
            mouse.down = true;
            break;

        case SDL_MOUSEBUTTONUP:
            mouse.down = false;
            break;

        case SDL_QUIT:
            running = false;
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
    
    SDL_GetMouseState(&mouse.x, &mouse.y);
    
    if (mouse.down)
    {
        if (b.pressed())
        {
            i++;
            b.setMessage(std::to_string(i));
        }
        mouse.down = false;
    }
  
}



void graphics()
{
    // Clearing
    window.clear();

    // Adding Entities to Renderer
    window.background(220, 220, 220, 255);
    window.render(b);
    
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