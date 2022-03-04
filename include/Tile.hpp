#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL.h>

class Tile
{
    public:
        Tile(SDL_Color color, SDL_FPoint position, int w, int h);
        void Update(float xShift = 0.0f, float yShift = 0.0f);
        void Draw(SDL_Renderer* renderer);

    public:
        inline void Fill(SDL_Color color) { _color = color; }
        inline int GetWidth() { return _width; }
        inline int GetHeight() { return _height; }
        inline float GetX() { return _position.x; }
        inline float GetY() { return _position.y; }

    private:
        SDL_Color _color;
        SDL_FPoint _position;
        int _width;
        int _height;
};

#endif