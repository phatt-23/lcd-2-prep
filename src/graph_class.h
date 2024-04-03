#ifndef __graph_class_h__
#define __graph_class_h__

#include <stdint.h>
#include <stdio.h>

#define __string_buffer__ 256
#define __debug__ 0

enum MoveOrder {
    Left,
    Right,
    Up,
    Down,
};

enum Position {
    Normal = 0b00000001,
    Center = 0b00000010,
    Above  = 0b00000100,
    Below  = 0b00001000,
};

struct Point2D { 
    int32_t x, y; 
    bool operator!=(Point2D t_other);
    void print_console();
};

struct RGB { 
    uint8_t r, g, b; 
};

class GraphElement {
private:
    RGB m_fg_color, m_bg_color;
    
protected:
public:
    Point2D m_pos;
    Point2D m_last_drawn;

    GraphElement(RGB t_fg_color, RGB t_bg_color);
    void drawPixel(int32_t t_x, int32_t t_y);
    virtual void draw() = 0;
    virtual void hide();
    RGB* get_fg();
    RGB* get_bg();
private:
    void swap_fg_bg_color();
    uint16_t convert_RGB888_to_RGB565(RGB t_color);
};

class Pixel : public GraphElement {
public:
    Pixel(Point2D t_pos, RGB t_fg_color, RGB t_bg_color);
    virtual void draw();
};

class Circle : public GraphElement {
    int32_t m_radius;
    void other_octant(int t_xc, int t_yc, int t_x, int t_y);

public:
    Circle( Point2D t_center, int32_t t_radius, RGB t_fg, RGB t_bg ); 
    void set_center(Point2D t_p);
    Point2D get_center() const;
    Point2D move(MoveOrder t_m, uint8_t t_by);
    void draw();
};

class Character : public GraphElement  {
    char m_character;

  public:
    Character(Point2D t_pos, char t_char, RGB t_fg, RGB t_bg);
    void draw();
    void draw(uint8_t t_x, uint8_t t_y);
};


class String : public GraphElement {
    Point2D m_font_size;
    char m_string[__string_buffer__] = {0};

public:
    String(Point2D t_pos, const char* t_str, RGB t_fg, RGB t_bg);
    void set_string(const char* t_str);
    Point2D set_pos(Point2D t_p);
    void hide_last();
    void draw();
    void draw(uint8_t t_x, uint8_t t_y);
    void draw(uint8_t t_x, uint8_t t_y, Position t_pos_type);
    void draw(Point2D t_font_size);
    void draw(Point2D t_font_size, Position t_pos_type);
    void draw(Point2D t_p, uint16_t t_pos_type);
    void draw(uint8_t t_x, uint8_t t_y, uint16_t t_pos_type);
};

class Line : public GraphElement {
    Point2D m_pos1, m_pos2;

public:
    Line(Point2D t_pos1, Point2D t_pos2, RGB t_fg, RGB t_bg);
    void draw_line(Point2D start, Point2D end);
    void draw();
};

#endif//__graph_class_h__