#include <SDL2/SDL.h>

#include "Color.hpp"

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    _color = { r, g, b, a };
}