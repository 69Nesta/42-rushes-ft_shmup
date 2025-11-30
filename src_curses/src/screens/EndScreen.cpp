#include "screens/EndScreen.hpp"
#include <string>

EndScreen::EndScreen(IScreenManager& screen_manager, GameStateManager &game_state):
	Screen(screen_manager, ScreenType::END)
{
	this->window = subwin(stdscr, LINES, COLS, 0, 0);
}

EndScreen::~EndScreen()
{

	if (this->window)
	{
		free(this->window);
		this->window = NULL;
	}
}

void	EndScreen::update(float delta_time)
{

}

void	EndScreen::render(void)
{
	// mvwprintw(this->window, 10, 10, "Hello");
	// wrefresh(this->window);
	// mvwprintw(this->window, 10, 10, "Count: %d", this->count);
	// wrefresh(this->window);
	// this->count++;

}

void	EndScreen::resize(int score)
{
	erase();
	std::string end_msg = "GAME OVER !";
	std::string score_s = std::to_string(score);

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	mvwprintw(this->window, LINES / 3, (COLS / 2) - end_msg.length() / 2, end_msg.c_str());
	mvwprintw(this->window, LINES / 3 + 2, (COLS / 2) - end_msg.length() / 2, "SCORE :");
	mvwprintw(this->window, LINES / 3 + 3, (COLS / 2) - end_msg.length() / 2, score_s.c_str());
	box(this->window, ACS_VLINE, ACS_HLINE);
	wbkgd(this->window, COLOR_PAIR(1));
	wrefresh(this->window);
}

void	EndScreen::handle_input(InputHandler& input)
{
	if (input.key_is_pressed(' '))
	{
		this->screen_manager.change_screen(ScreenType::LOBBY);
	} else if (input.key_is_pressed(410))
		this->resize();
}

void	EndScreen::initialize(void)
{
	this->resize();
}
