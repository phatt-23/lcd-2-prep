#include <stdio.h>

#include "lcd_lib.h"
#include "graph_class.h"

Point2D g_center_of_screen = { LCD_WIDTH/2, LCD_HEIGHT/2 };

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

RGB g_color[] = {
    {255, 255, 255},        // #FFFFFF
    {192, 192, 192},        // #C0C0C0
    {128, 128, 128},        // #808080
    {0, 0, 0},              // #000000
    {255, 0, 0},            // #FF0000
    {128, 0, 0},            // #800000
    {255, 255, 0},          // #FFFF00
    {128, 128, 0},          // #808000
    {0, 255, 0},            // #00FF00
    {0, 128, 0},            // #008000
    {0, 255, 255},          // #00FFFF
    {0, 128, 128},          // #008080
    {0, 0, 255},            // #0000FF
    {0, 0, 128},            // #000080
    {255, 0, 255},          // #FF00FF
    {128, 0, 128},          // #800080
};

int main()
{
	lcd_init();				// LCD initialization
    
    String s { 
        g_center_of_screen, 
        "Hello, world!",
        g_color[Yellow], 
        g_color[Red] 
    };
    s.draw({8, 8},   Position::Above | Position::Center);
    s.draw({16, 26}, Position::Below | Position::Center);
    
    s.hide_last();
    
    Line l {
        {60, 60},
        {60, 90},
        g_color[Green],
        g_color[Blue]
    };
    l.draw();

    cv::imshow(LCD_NAME, g_canvas);
    cv::waitKey(0);
	return 0;
}