#include "screens/ScreenLobby.hpp"

ScreenLobby::ScreenLobby(GameStateManager &game_state) : Screen(ScreenType::LOBBY)
{
	this->window = newwin(LINES, COLS, 0, 0);
	wrefresh(this->window);

	getch();
	endwin();
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
}