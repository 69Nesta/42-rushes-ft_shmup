#include "classes/GameScreen.hpp"
#include <string.h>

GameScreen::GameScreen() : Window(stdscr, LINES, COLS, 0, 0), ui(this->getFrame(), (LINES / 10) * 2, COLS, (LINES / 10) * 8, 0), game(this->getFrame(), (LINES / 10) * 8, COLS, 0, 0)
{
	
}

GameScreen::~GameScreen()
{
}

