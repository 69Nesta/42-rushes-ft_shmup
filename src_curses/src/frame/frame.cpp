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

WINDOW	*init_top()
{
	WINDOW	*layer;
	string health = "HEALTH :";
	string score = "SCORE : ";
	
	layer = subwin(stdscr, 3, COLS, 0, 0);
	wmove(layer, 1, 1);
	wprintw(layer, health.c_str());
	wmove(layer, 1, COLS - score.size() - 12);
	wprintw(layer, score.c_str());
	box(layer, ACS_VLINE, ACS_HLINE);
	return (layer);
}

WINDOW	*init_bot()
{

	WINDOW	*layer;
	string key = " [W] = Up       [S] = Down      [SPACE] = SHOOT !!!";
	
	layer = subwin(stdscr, 3, COLS, LINES - 4, 0);
	wmove(layer, 1, 1);
	wprintw(layer, key.c_str());
	box(layer, ACS_VLINE, ACS_HLINE);
	return (layer);
}

void Frame::init_frame()
{
	char	ch;
	int		size;
	WINDOW	*top_layer;
	WINDOW	*bot_layer;
	string str = "press a [Space] to start the game";
		
	initscr();
	noecho();
	top_layer = init_top();
	bot_layer = init_bot();
	curs_set(0);
	move(LINES / 2, COLS / 4);
	printw(">");
	move(LINES / 2,  (COLS / 2) - str.size() + 20 );	
	printw(str.c_str());
	refresh();
	wrefresh(top_layer);
	wrefresh(bot_layer);
	while ((ch = getch()) != ' ')
	{
		refresh();
		wrefresh(top_layer);
		wrefresh(bot_layer);
	}
	clear(); {
		
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

void	render_frame(vector<Entity> &entity, WINDOW *top_layer, WINDOW *bot_layer)
{
	for(Entity n : entity) 	
	{
		move(n.get_lines(), n.get_cols());
		render_entity(n);	
	}
}

