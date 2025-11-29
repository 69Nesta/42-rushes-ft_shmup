#include "frame.hpp"
#include <ncurses.h>

void Frame::init_frame()
{
	initscr();
	printw("test");
	refresh();
	getch();
	endwin();

}
