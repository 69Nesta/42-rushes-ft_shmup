#include "frame.hpp"
#include <ncurses.h>

int main()
{
	Frame window;
    WINDOW **layer;

    layer = NULL;
	window.init_frame();
	window.end_game();
	return (0);
}
