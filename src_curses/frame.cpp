#include "frame.hpp"
#include <ncurses.h>
#include <string>

using namespace std;
/*
 * __
 * ) \_____				@ 	<	<
 * |  )42)__)>
 * )_/
 *
 * */

void Frame::init_frame()
{
	char	ch;
	int		size;
	string str = "press a [Space] to start the game";
		
	initscr();
	move(LINES / 2, 0);
	printw(">");
	move(LINES / 2,  (COLS / 2) - str.size() + 25 );	
	printw(str.c_str());
	refresh();
	while ((ch = getch()) != ' ')
	{
		erase();
		move (LINES/ 2, 0);
		printw(">");
		move(LINES / 2 ,  (COLS / 2) - str.size() + 25 );	
		printw(str.c_str());
		refresh();
	}
	refresh();
}

