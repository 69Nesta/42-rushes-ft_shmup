#include "screens/GameScreen.hpp"

GameScreen::GameScreen(IScreenManager& screen_manager, GameClock& game_clock, GameStateManager& game_state_manager): 
	Screen(screen_manager, ScreenType::GAME),
	game_clock(game_clock),
	game_state_manager(game_state_manager),
	player(10, 10, COLS, LINES - 4 - 3),
	toolstip(subwin(stdscr, 3, COLS, LINES - 3, 0)),
	_tools_tip(this->toolstip)
{
	int		hud_h;
	int		tooltips_h;
	
	hud_h = 4;
	tooltips_h = 3;
	this->hud = subwin(stdscr, hud_h, COLS, 0, 0);
	this->game = subwin(stdscr, LINES - hud_h - tooltips_h, COLS, hud_h, 0);;
	
	// this->_tools_tip = ToolsTip(this->toolstip);
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
	box(this->hud, ACS_VLINE, ACS_HLINE);
	box(this->game, ACS_VLINE, ACS_HLINE);
	// box(this->toolstip, ACS_VLINE, ACS_HLINE);
	this->_tools_tip.render();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	wbkgd(this->game, COLOR_PAIR(1));
	wbkgd(this->hud, COLOR_PAIR(1));


	wrefresh(this->hud);
	wrefresh(this->game);
	wrefresh(this->toolstip);
}

void	GameScreen::handle_input(InputHandler& input)
{
	if (input.key_is_pressed(410))
		this->resize();

	this->player.handle_input(input);
}

void	GameScreen::resize()
{
	erase();
	box(this->hud, ACS_VLINE, ACS_HLINE);
	box(this->game, ACS_VLINE, ACS_HLINE);
	box(this->toolstip, ACS_VLINE, ACS_HLINE);

	this->player.resize(COLS, LINES - 4 - 3);
	this->player.render(this->game);
	this->_tools_tip.render();

	wrefresh(this->hud);
	wrefresh(this->game);
	wrefresh(this->toolstip);
}

void	GameScreen::update(float delta_time)
{
	// moves entities
	// check collides
	this->player.update(delta_time);
}

void	GameScreen::render(void)
{
	mvwprintw(this->hud, 1, COLS / 2 - 11/2, "FPS: %6.0f", this->game_clock.calculate_fps());
	// mvwprintw(this->game, 1, COLS / 2 - 11/2, "FPS: %6.0f", this->game_clock.calculate_fps());
	wrefresh(this->hud);
	
	if (this->game)
		this->player.render(this->game);
	wrefresh(this->game);
	// wrefresh(this->toolstip);
	// render player
	// render enemy
	// render bullets
}

