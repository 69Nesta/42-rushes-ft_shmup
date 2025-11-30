#include "screens/EndScreen.hpp"
#include <string>

EndScreen::EndScreen(IScreenManager& screen_manager, GameStateManager &game_state, bool& is_running):
	Screen(screen_manager, ScreenType::END), game_state(game_state), is_running(is_running)
{
	this->window = subwin(stdscr, LINES, COLS, 0, 0);
}

EndScreen::~EndScreen()
{

	if (this->window)
	{
		delwin(this->window);
		this->window = NULL;
	}
}

void	EndScreen::update(float delta_time)
{

}

void	EndScreen::render(void)
{}

void	EndScreen::resize()
{
	erase();
	std::string end_msg = "GAME OVER !";
	std::ostringstream	score;
	score << "SCORE: " << this->game_state.get_score();
	std::string score_s = std::to_string(game_state.get_score());

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	mvwprintw(this->window, LINES / 5 * 2, (COLS / 2) - end_msg.length() / 2, "%s", end_msg.c_str());
	mvwprintw(this->window, LINES / 5 * 2 + 2, (COLS / 2) - score.str().length() / 2, "%s", score.str().c_str());
	box(this->window, ACS_VLINE, ACS_HLINE);
	wbkgd(this->window, COLOR_PAIR(1));
	wrefresh(this->window);
}

void	EndScreen::handle_input(InputHandler& input)
{
	if (input.key_is_pressed(' '))
		is_running = false;
	if (input.key_is_pressed(410))
		this->resize();
}

void	EndScreen::initialize(void)
{
	this->resize();
}
