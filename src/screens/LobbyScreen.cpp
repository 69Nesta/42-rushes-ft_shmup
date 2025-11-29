#include "screens/LobbyScreen.hpp"
#include <string>

LobbyScreen::LobbyScreen(IScreenManager& screen_manager, GameStateManager &game_state):
	Screen(screen_manager, ScreenType::LOBBY)
{
	this->window = subwin(stdscr, LINES, COLS, 0, 0);
}

LobbyScreen::~LobbyScreen()
{
	if (this->window)
	{
		free(this->window);
		this->window = NULL;
	}
}

void	LobbyScreen::update(float delta_time)
{

}

void	LobbyScreen::render(void)
{
	// mvwprintw(this->window, 10, 10, "Hello");
	// wrefresh(this->window);
	// mvwprintw(this->window, 10, 10, "Count: %d", this->count);
	// wrefresh(this->window);
	// this->count++;

}

void	LobbyScreen::handle_input(InputHandler& input)
{
	if (input.key_is_pressed(' '))
	{
		this->screen_manager.change_screen(ScreenType::GAME);
	}
}

void	LobbyScreen::initialize(void)
{
	std::string start_msg = "Press [Space] to start";

	mvwprintw(this->window, LINES / 2, (COLS / 2) - start_msg.length() / 2, start_msg.c_str());
	box(this->window, ACS_VLINE, ACS_HLINE);
	wrefresh(this->window);
}