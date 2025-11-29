#include "screens/GameScreen.hpp"

GameScreen::GameScreen(IScreenManager& screen_manager): Screen(screen_manager, ScreenType::GAME)
{
	int		hud_h;
	int		tooltips_h;

	hud_h = 4;
	tooltips_h = 3;
	this->hud = subwin(stdscr, hud_h, COLS, 0, 0);
	this->game = subwin(stdscr, LINES - hud_h - tooltips_h, COLS, hud_h, 0);
	this->toolstip = subwin(stdscr, tooltips_h, COLS, LINES - tooltips_h, 0);
}

GameScreen::~GameScreen()
{
	if (this->hud)
	{
		free(this->hud);
		this->hud = NULL;
	}
	if (this->game)
	{
		free(this->game);
		this->game = NULL;
	}
	if (this->toolstip)
	{
		free(this->toolstip);
		this->toolstip = NULL;
	}
}

void	GameScreen::initialize(void)
{
	erase();
	// mvwprintw(this->window, LINES / 2, (COLS / 2) - start_msg.length() / 2, start_msg.c_str());
	box(this->hud, ACS_VLINE, ACS_HLINE);
	box(this->game, ACS_VLINE, ACS_HLINE);
	box(this->toolstip, ACS_VLINE, ACS_HLINE);
	wrefresh(this->hud);
	wrefresh(this->game);
	wrefresh(this->toolstip);
}

void	GameScreen::handle_input(InputHandler& input)
{

}

void	GameScreen::update(float delta_time)
{
	// moves entities
	// check collides
}

void	GameScreen::render(void)
{
	wrefresh(this->hud);
	wrefresh(this->game);
	wrefresh(this->toolstip);
	// render player
	// render enemy
	// render bullets
}

