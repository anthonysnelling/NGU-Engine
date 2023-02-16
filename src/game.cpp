#include <iostream>
#include "constants.h"
#include "game.h"
//#include "TransformComponent.h"
#include "../lib/glm/glm.hpp"

EntityManager manager;
SDL_Renderer* Game::renderer;

Game::Game()
{
    this->isRunning = false;
}

Game::~Game()
{
}

bool Game::IsRunning() const
{
    return this->isRunning;
}

void Game::Initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error Initializing SDL" << std::endl;
        return;
    }
    window = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_BORDERLESS
    );
    if (!window)
    {
        std::cerr << "Error creating SDL window" << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cerr << "Error creating SDL window" << std::endl;
        return;
    }

    isRunning = true;
}

void Game::ProcessInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isRunning = false;
//            Just experimenting with keys presses
//            if(event.key.keysym.sym == SDLK_r)
//            {
//                projectileVel.x *= -1;
//                projectileVel.y *= -1;
//            }
            break;
        default:
            break;
    }
}

void Game::Update()
{
    // wait until 16ms has elapsed since last frame 1000/ 60 is 16
    // while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME));

    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(timeToWait);
    }

    // Delta Time difference between in ticks from last frame converted to seconds.
    float deltaTime{(SDL_GetTicks() - ticksLastFrame) / 1000.0f};
    //Sets the new ticks for the current frame to be used in the next pass.
    ticksLastFrame = SDL_GetTicks();

    //Clamp delta time to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    //TODO:
    //Call the manager.update to update all the entities as function of deltatime.

}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    //TODO:
    // Call the manager.render to render all entities.

    SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}