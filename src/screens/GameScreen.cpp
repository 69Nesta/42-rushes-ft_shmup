#include "screens/GameScreen.hpp"

GameScreen::GameScreen(IScreenManager& screen_manager, GameClock& game_clock, GameStateManager& game_state_manager): 
	Screen(screen_manager, ScreenType::GAME),
	game_clock(game_clock),
	game_state_manager(game_state_manager),
	hud(subwin(stdscr, HUD_HEIGHT, COLS, 0, 0)),
	game(subwin(stdscr, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT, COLS, HUD_HEIGHT, 0)),
	bullet_manager(game),
	enemy_manager(game),
	player(10, 10, COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT, bullet_manager),
	toolstip(subwin(stdscr, TOOLTIP_HEIGHT, COLS, LINES - TOOLTIP_HEIGHT, 0)),
	_tools_tip(this->toolstip)
{}

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
	this->_tools_tip.render();

	// Enemy enemy(COLS - 2, (rand() % (LINES - HUD_HEIGHT - TOOLTIP_HEIGHT - 2)) + 1, COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT, this->bullet_manager);
	// this->enemy_manager.push_enemy(enemy);
	
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

	this->player.resize(COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT);
	this->player.render(this->game);
	this->_tools_tip.render();
	this->bullet_manager.resize(COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT);
	this->enemy_manager.resize(COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT);
	wrefresh(this->hud);
	wrefresh(this->game);
	wrefresh(this->toolstip);
}

void	GameScreen::update(float delta_time)
{
	if (rand() % 1001 <= 40)
	{
		
		Enemy enemy(COLS - 2, (rand() % (LINES - HUD_HEIGHT - TOOLTIP_HEIGHT - 2)) + 1, COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT, this->bullet_manager);
		this->enemy_manager.push_enemy(enemy);
		// this->enemy_manager;
	}
	// moves entities
	// check collides
	this->player.update(delta_time);
	this->bullet_manager.update(delta_time);
	this->enemy_manager.update(delta_time);
}

void	GameScreen::render(void)
{
	mvwprintw(this->hud, 1, COLS / 2 - 11/2, "FPS: %3.0f", this->game_clock.calculate_fps());
	// mvwprintw(this->game, 1, COLS / 2 - 11/2, "FPS: %6.0f", this->game_clock.calculate_fps());
	mvwprintw(this->hud, 1, 1, "Ammos: %3d", player.get_ammo());
	// mvwprintw(this->hud, 2, 1, "Health: %3d", player.get_health());
	// mvwprintw(this->hud, 2, 1, "Enemy Count: %4zu", this->enemy_manager.size());
	mvwprintw(this->hud, 2, 1, "Bullets Count: %4zu", this->bullet_manager.bullets.size());
	
	wrefresh(this->hud);
	
	if (this->game)
	{
		this->player.render(this->game);
		this->bullet_manager.render();
		this->enemy_manager.render();
	}
	wrefresh(this->game);
	// wrefresh(this->toolstip);
	// render player
	// render enemy
	// render bullets
}

