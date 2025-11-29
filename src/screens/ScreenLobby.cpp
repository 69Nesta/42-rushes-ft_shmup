#include "screens/ScreenLobby.hpp"

ScreenLobby::ScreenLobby(GameStateManager &game_state) : Screen(ScreenType::LOBBY)
{
	this->window = subwin(stdscr, LINES, COLS, 0, 0);
}

ScreenLobby::~ScreenLobby()
{
	if (this->window)
	{
		free(this->window);
		this->window = NULL;
	}
}

void ScreenLobby::update(float delta_time)
{
}

void ScreenLobby::render(void)
{
}

void ScreenLobby::initialize(void)
{
	box(this->window, ACS_VLINE, ACS_HLINE);
	wrefresh(this->window);

	getch();
	endwin();
}