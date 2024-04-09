#ifndef __colours_h__
#define __colours_h__

#include <cstdint>

struct RGB { 
    uint8_t r, g, b; 
};

enum ColorIndex {
    White,
    Silver,
    Gray,
    Black,
    Red,
    Maroon,
    Yellow,
    Olive,
    Lime,
    Green,
    Aqua,
    Teal,
    Blue,
    Navy,
    Fuchsia,
    Purple,
};

extern const RGB g_color[];

#endif//__colours_h__