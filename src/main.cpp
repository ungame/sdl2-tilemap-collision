#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "Settings.hpp"
#include "Tile.hpp"
#include "Level.hpp"

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl init failed: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    std::string title = "SDL2 TileMap - Collisions | WW=" + std::to_string(SCREEN_WIDTH) + " | WH=" + std::to_string(SCREEN_HEIGHT); 

    SDL_Window* window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create window failed: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create renderer failed: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Event event;
    bool running = true;
    const Uint8* _keyboard = SDL_GetKeyboardState(nullptr);

    int size = sizeof(LevelMap) / sizeof(LevelMap[0]);
    Level* level = new Level(LevelMap, size, TILE_SIZE);

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYUP:
                case SDL_KEYDOWN:
                    _keyboard = SDL_GetKeyboardState(nullptr);
            }
        }

        if(_keyboard[SDL_SCANCODE_ESCAPE] == 1)
            running = false;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
        SDL_RenderClear(renderer);

        level->Run(renderer, _keyboard);

        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }

    level->Destroy();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;
}