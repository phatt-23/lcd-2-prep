#include "lcd_lib.h"
#include "graph_class.h"

Point2D g_center_of_screen = { LCD_WIDTH/2, LCD_HEIGHT/2 };

int main() {

    int l_circle_size = 32;
    Circle l_circle {
        g_center_of_screen,
        l_circle_size,
        g_color[Blue],
        g_color[Black]
    };

    String l_above {
        g_center_of_screen, 
        std::to_string(l_circle.get_center().x).c_str(),
        g_color[Yellow], 
        g_color[Black]
    };

    String l_below {
        g_center_of_screen, 
        std::to_string(l_circle.get_center().y).c_str(),
        g_color[Yellow], 
        g_color[Black] 
    };

    l_circle.draw();
    l_above.draw({8,8}, Position::Above | Position::Center);
    l_below.draw({8,8}, Position::Below | Position::Center);
    
    cv::imshow(LCD_NAME, g_canvas);
    cv::waitKey(0);

    l_below.hide_last();

    cv::imshow(LCD_NAME, g_canvas);
    cv::waitKey(0);

    l_below.set_pos({30, 30});
    l_below.draw({8,8}, Position::Below | Position::Center);

    cv::imshow(LCD_NAME, g_canvas);
    cv::waitKey(0);


    Point2D l_pos = g_center_of_screen;
    bool x_plus = true;
    bool y_plus = false;
    
    while(true) {
        if(x_plus) {
            l_pos.x++;
            x_plus = (l_pos.x >= LCD_WIDTH - l_circle_size) ? false : true;
        } else {
            l_pos.x--;
            x_plus = (l_pos.x <= 0 + l_circle_size) ? true : false;
        }

        if(y_plus) {
            l_pos.y++;
            y_plus = (l_pos.y >= LCD_HEIGHT - l_circle_size) ? false : true;
        } else {
            l_pos.y--;
            y_plus = (l_pos.y <= 0 + l_circle_size) ? true : false;
        }

        l_circle.set_center(l_pos);
        l_above.set_pos(l_pos);
        l_below.set_pos(l_pos);

        l_above.set_string(std::to_string(l_circle.get_center().x).c_str());
        l_below.set_string(std::to_string(l_circle.get_center().y).c_str());
        l_circle.draw();
        l_above.draw({8,8}, Position::Above | Position::Center);
        l_below.draw({8,8}, Position::Below | Position::Center);
        cv::imshow(LCD_NAME, g_canvas);
        cv::waitKey(10);
        l_circle.hide();
        l_above.hide_last();
        l_below.hide_last();
    }

    cv::imshow(LCD_NAME, g_canvas);
    cv::waitKey(0);
    return 0;
}

int main2()
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