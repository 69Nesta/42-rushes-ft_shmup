#include "classes/LobbyScreen.hpp"
#include <string.h>

LobbyScreen::LobbyScreen() : Window(stdscr, LINES, COLS, 0, 0)
{
	char *msg_start = "Press [Space] to start the game !";
	int taille = strlen(msg_start);

	while (1)
	{
		clear();
		mvprintw(LINES / 2, (COLS / 2) - (taille / 2), msg_start);
		refresh();
		if (getch() != 410)
			break;
	}
}

LobbyScreen::~LobbyScreen()
{
}
