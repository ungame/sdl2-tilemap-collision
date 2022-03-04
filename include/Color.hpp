#ifndef COLOR_HPP
#define COLOR_HPP

#include <SDL2/SDL.h>

class Color
{  
    public:
        Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = SDL_ALPHA_TRANSPARENT);

    public:
        inline static SDL_Color White() { return Color(255, 255, 255).GetColor(); }
        inline static SDL_Color Black() { return Color(0, 0, 0).GetColor(); }
        inline static SDL_Color Red() { return Color(255, 0, 0).GetColor(); }
        inline static SDL_Color Green() { return Color(0, 255, 0).GetColor(); }
        inline static SDL_Color Blue() { return Color(0, 0, 255).GetColor(); }
        inline static SDL_Color Grey() { return Color(189, 189, 189).GetColor(); }

    public:
        inline SDL_Color GetColor() { return _color; }

    private:
        SDL_Color _color;

};

#endif