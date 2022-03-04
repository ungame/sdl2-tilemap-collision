#include <SDL2/SDL.h>

#include "Player.hpp"

Player::Player(SDL_Color color, SDL_FPoint position, int w, int h)
{
   _color = color;
   _position = position;
   _width = w;
   _height = h;
   _speed = PLAYER_SPEED;
   _direction = { 0.0F, 0.0F };
}

void Player::Update(const Uint8* keys)
{
    _direction.x = 0.0F;

    if(keys[SDL_SCANCODE_LEFT] == 1)
         _direction.x = -1.0F;  

    if(keys[SDL_SCANCODE_RIGHT] == 1)
        _direction.x = 1.0F;

    if(keys[SDL_SCANCODE_SPACE] == 1)
        Jump();

    // _position.x +=  _direction.x * _speed;
}


void Player::Draw(SDL_Renderer* renderer)
{   
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, _color.a);

    int x = _position.x;
    int y = _position.y;

    SDL_Rect rect = { x, y, _width, _height };

    SDL_RenderFillRect(renderer, &rect);
}
