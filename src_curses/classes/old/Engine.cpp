#include "classes/Engine.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include "classes/LobbyScreen.hpp"
#include "classes/GameScreen.hpp"

Engine::Engine()
{
	initscr();
	LobbyScreen lobby_screen;
	GameScreen game_screen;

}

Engine::~Engine()
{
	endwin();
}

void Engine::init()
{
	
	

	// this->window_game = subwin(stdscr, (LINES / 10) * 8, COLS, 0, 0);
	// this->window_ui = subwin(stdscr, (LINES / 10) * 2, COLS, (LINES / 10) * 8, 0);
	
	// box(this->haut, ACS_VLINE, ACS_HLINE);
	// box(this->bas, ACS_VLINE, ACS_HLINE);
	
	// wrefresh(this->haut);
	// wrefresh(this->bas);

	// getch();
	
}

void Engine::update()
{
}
