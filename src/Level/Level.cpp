#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Tile.hpp"
#include "Level.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include "Settings.hpp"

#define GRAVITY 0.8F

Level::Level(const std::string levelData[], const int mapHeight, const int tileSize)
{
    _worldShift = 0;

    for(int row = 0; row < mapHeight; row++)
    {
        int len = levelData[row].length();

        for(int col = 0; col < len; col++)
        {
            char cell = levelData[row][col];
            
            float x = col * tileSize;
            float y = row * tileSize;
            SDL_FPoint position = { x, y };

            if(cell == 'X')
            {
                Tile* tile = new Tile(Color::Grey(), position, tileSize, tileSize);

                _tiles.push_back(tile);
            }

            if(cell == 'P')
            {
                _player = new Player(Color::Red(), position, 32, 64);
            }
        }
    }
}

void Level::ApplyGravity()
{
    float directionY = _player->GetDirectionY() + GRAVITY;
    _player->SetDirectionY(directionY);

    float y = _player->GetY() + _player->GetDirectionY();
    _player->SetY(y);
}

void Level::HorizontalMovementCollision()
{
    float directionX = _player->GetDirectionX();
    _player->SetX(_player->GetX() + (directionX * _player->GetSpeed()));

    for(Tile* tile: _tiles)
    {
        SDL_Rect t = { (int)tile->GetX(), (int)tile->GetY(), tile->GetWidth(), tile->GetHeight() };
        SDL_Rect p = { (int)_player->GetX(), (int)_player->GetY(), _player->GetWidth(), _player->GetHeight() };

        if(SDL_HasIntersection(&t, &p))
        {
            if(_player->IsWalkingLeft())
            {
                float rightSide = t.x + t.w;
                _player->SetX(rightSide);
            }

            if(_player->IsWalkingRight())
            {
                float leftSide = t.x - p.w;
                _player->SetX(leftSide);
            }
        }
    }

}

void Level::VerticalMovementCollision()
{
    ApplyGravity();

    for(Tile* tile: _tiles)
    {
        SDL_Rect t = getRect(tile->GetX(), tile->GetY(), tile->GetWidth(), tile->GetHeight());
        SDL_Rect p = getRect(_player->GetX(), _player->GetY(), _player->GetWidth(), _player->GetHeight());

        if(SDL_HasIntersection(&t, &p))
        {
            if(_player->IsJumping())
            {
                float bottomSide = t.y + t.h;
                _player->SetY(bottomSide);
                _player->SetDirectionY(0);
            }

            if(_player->IsFalling())
            {
                float topSide = t.y - p.h;
                _player->SetY(topSide);
                _player->SetDirectionY(0);
            }
        }
    } 
}

SDL_Rect Level::getRect(int x, int y, int width, int height)
{
    SDL_Rect rect = { x, y, width, height };

    return rect;
}

void Level::Run(SDL_Renderer* renderer, const Uint8* keys)
{
    _player->Update(keys);

    HorizontalMovementCollision();
    VerticalMovementCollision();

    if(_player->GetX() < (SCREEN_WIDTH / 4) && _player->IsWalkingLeft())
    {
        _worldShift = PLAYER_SPEED;
        _player->SetSpeed(0);
    }
    else if (_player->GetX() > SCREEN_WIDTH - (SCREEN_WIDTH / 4) && _player->IsWalkingRight())
    {
        _worldShift = -PLAYER_SPEED;
        _player->SetSpeed(0);
    }
    else
    {
        _worldShift = 0;
        _player->SetSpeed(PLAYER_SPEED);
    }

    for(Tile* tile : _tiles)
    {
        tile->Update(_worldShift);
        tile->Draw(renderer);
    }

    _player->Draw(renderer);
   
}

void Level::Destroy()
{
  if(_tiles.size() > 0)
    _tiles.clear();
}