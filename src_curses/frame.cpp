#include "frame.hpp"
#include "entity.cpp"
#include <ncurses.h>
#include <string>
#include <vector>

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
	curs_set(0);
	move(LINES / 2, 0);
	printw(">");
	move(LINES / 2,  (COLS / 2) - str.size() + 25 );	
	printw(str.c_str());
	refresh();
	while ((ch = getch()) != ' ')
	{
		erase();
		curs_set(0);
		move (LINES/ 2, 0);
		printw(">");
		move(LINES / 2 ,  (COLS / 2) - str.size() + 25 );	
		printw(str.c_str());
		refresh();
	}
	refresh();
}

void	Frame::end_game()
{
	endwin();
}


void	render_entity(Entity entity)
{
	move(entity.get_lines(), entity.get_cols());
	addch(entity.get_ship());
}

void	render_frame(vector<Entity> &entity)
{
	for(Entity n : entity) 	
	{
		move(n.get_lines(), n.get_cols());
		render_entity(n);	
	}
}

