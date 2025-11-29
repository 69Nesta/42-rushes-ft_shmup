#include "frame.hpp"
#include "entity.cpp"
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


void	render_frame(vector<Entity, entity_lst>)
{
	
}

void	render_entity(Entity::entity)
{
	move(entity.get_lines(), entity.get_cols());
	printw(entity.get_display().c_str());
}
