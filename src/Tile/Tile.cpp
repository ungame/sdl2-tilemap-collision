#include <SDL2/SDL.h>

#include "Tile.hpp"

Tile::Tile(SDL_Color color, SDL_FPoint position, int w, int h)
{
   _color = color;
   _position = position;
   _width = w;
   _height = h;
}

void Tile::Update(float xShift, float yShift)
{
    _position.x += xShift;
    _position.y += yShift;
}

void Tile::Draw(SDL_Renderer* renderer)
{   
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, _color.a);

    int x = _position.x;
    int y = _position.y;

    // SDL_Log("PX=%f, PY=%f, X=%d, Y=%d", _position.x, _position.y, x, y);

    SDL_Rect rect = { x, y, _width, _height };

    SDL_RenderFillRect(renderer, &rect);
}
