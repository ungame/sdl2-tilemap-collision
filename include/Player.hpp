#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>

#define PLAYER_SPEED 8.0F
#define PLAYER_JUMP_SPEED -16.0F

class Player
{
    public:
        Player(SDL_Color color, SDL_FPoint position, int w, int h);
        void Update(const Uint8* keys);
        void Draw(SDL_Renderer* renderer);

    public:
        inline void Fill(SDL_Color color) { _color = color; }

        inline int GetWidth() { return _width; }
        inline int GetHeight() { return _height; }

        inline float GetDirectionX() { return _direction.x; }
        inline void SetDirectionX(float x) { _direction.x = x; }
        inline bool IsWalkingLeft() { return _direction.x < 0; }
        inline bool IsWalkingRight() { return _direction.x > 0; }

        inline float GetDirectionY() { return _direction.y; }
        inline void SetDirectionY(float y) { _direction.y = y; }
        inline bool IsJumping() { return _direction.y < 0; }
        inline bool IsFalling() { return _direction.y > 0; }

        inline void SetSpeed(float speed) { _speed = speed; }
        inline float GetSpeed() { return _speed; }

        inline void SetX(float x) { _position.x = x; }
        inline float GetX() { return _position.x; }

        inline void SetY(float y) { _position.y = y; }
        inline float GetY() { return _position.y; }

        inline void Jump() { _direction.y = PLAYER_JUMP_SPEED; }

    private:
        SDL_Color _color;
        SDL_FPoint _position;
        SDL_FPoint _direction;
        int _width;
        int _height;
        float _speed;
};

#endif