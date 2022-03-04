#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>

const int MAP_HEIGHT = 11;

const std::string LevelMap[MAP_HEIGHT] = {
"                            ",
"                            ",
"                            ",
" XX    XXX             XX   ",
" XX P                       ",
" XXXX         XX         XX ",
" XXXX       XX              ",
" XX    X  XXXX    XX  XX    ",
"       X  XXXX    XX  XXX   ",
"    XXXX  XXXXXX  XX  XXXX  ",
"XXXXXXXX  XXXXXX  XX  XXXX  "
};

const int TILE_SIZE = 64;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = MAP_HEIGHT * TILE_SIZE;

#endif