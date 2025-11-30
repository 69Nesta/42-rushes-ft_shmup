#include "screens/GameScreen.hpp"

GameScreen::GameScreen(IScreenManager& screen_manager, GameClock& game_clock, GameStateManager& game_state_manager): 
    Screen(screen_manager, ScreenType::GAME),
    hud(newwin(HUD_HEIGHT, COLS, 0, 0)),
    game(newwin(LINES - HUD_HEIGHT - TOOLTIP_HEIGHT, COLS, HUD_HEIGHT, 0)),
    toolstip(newwin(TOOLTIP_HEIGHT, COLS, LINES - TOOLTIP_HEIGHT, 0)),
    _tools_tip(this->toolstip),
    game_clock(game_clock),
    game_state_manager(game_state_manager),
    bullet_manager(game),
    enemy_manager(game),
    player(10, 10, COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT, bullet_manager),
    collision_manager(bullet_manager, enemy_manager, player, screen_manager),
    background(COLS, LINES - HUD_HEIGHT - TOOLTIP_HEIGHT, 6.0f)
{}

GameScreen::~GameScreen()
{
	if (this->hud)
	{
		delwin(this->hud);
		this->hud = NULL;
	}
	if (this->game)
	{
		delwin(this->game);
		this->game = NULL;
	}
	if (this->toolstip)
	{
		delwin(this->toolstip);
		this->toolstip = NULL;
	}
}

void	GameScreen::initialize(void)
{
    wclear(stdscr);
    wnoutrefresh(stdscr);

    werase(this->hud);
    box(this->hud, ACS_VLINE, ACS_HLINE);

    werase(this->game);
    box(this->game, ACS_VLINE, ACS_HLINE);

    this->_tools_tip.render();

    this->background.render(this->game);

    wrefresh(this->hud);
    wrefresh(this->game);
    wrefresh(this->toolstip);
    doupdate();
}

void	GameScreen::handle_input(InputHandler& input)
{
	if (input.key_is_pressed(410))
		this->resize();
	this->player.handle_input(input);
}

void	GameScreen::resize()
{
    int game_h = LINES - HUD_HEIGHT - TOOLTIP_HEIGHT;

    if (this->hud)
    {
        wresize(this->hud, HUD_HEIGHT, COLS);
        mvwin(this->hud, 0, 0);
        werase(this->hud);
        box(this->hud, ACS_VLINE, ACS_HLINE);
    }
    if (this->game)
    {
        wresize(this->game, game_h, COLS);
        mvwin(this->game, HUD_HEIGHT, 0);
        werase(this->game);
    }
    if (this->toolstip)
    {
        wresize(this->toolstip, TOOLTIP_HEIGHT, COLS);
        mvwin(this->toolstip, LINES - TOOLTIP_HEIGHT, 0);
        werase(this->toolstip);
        box(this->toolstip, ACS_VLINE, ACS_HLINE);
    }

    this->player.resize(COLS, game_h);
    this->background.resize(COLS, game_h);
    this->bullet_manager.resize(COLS, game_h);
    this->enemy_manager.resize(COLS, game_h);

    this->player.render(this->game);
    this->_tools_tip.render();
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
	}
	this->player.update(delta_time);
	this->background.update(delta_time);
	this->collision_manager.update(this->game);
	this->enemy_manager.update(delta_time);
	this->bullet_manager.update(delta_time);

	// score
	this->game_state_manager.add_score(1);

}

void	GameScreen::render(void)
{
	std::ostringstream oss;

	std::ostringstream	score;
	score << "Score: " << this->game_state_manager.get_score();

	mvwprintw(this->hud, 1, COLS / 2 - 11/2, "FPS: %3.0f", this->game_clock.calculate_fps());
	{
		int health = player.get_health();
		int max_health = player.get_max_health();
		int bar_len = 10;
		int filled = 0;
		if (max_health > 0) filled = (health * bar_len) / max_health;

		std::string health_bar;
		health_bar.reserve(bar_len);
		for (int i = 0; i < bar_len; ++i)
		{
			health_bar += (i < filled) ? '#' : ' ';
		}
		mvwprintw(this->hud, 1, 1, "Health: %s (%d/%d)", health_bar.c_str(), health, max_health);
	}
	{
		int ammo = player.get_ammo();
		int max_ammo = player.get_max_ammo();
		std::string ammo_bar;
		ammo_bar.reserve(max_ammo * 2);
		for (int i = 0; i < max_ammo; ++i)
		{
			ammo_bar += (i < ammo) ? 'o' : '.';
			if (i + 1 < max_ammo) ammo_bar += ' ';
		}
		mvwprintw(this->hud, 2, 1, "Ammos:  %s", ammo_bar.c_str());
	}
	
	mvwprintw(this->hud, 1, COLS - score.str().length() - 1, "%s", score.str().c_str());

	/* DEBUG */
	wbkgd(this->hud, COLOR_PAIR(1));	
	wrefresh(this->hud);
	
	if (this->game)
	{
		this->background.render(this->game);
		this->player.render(this->game);
		this->bullet_manager.render();
		this->enemy_manager.render();
	}
	wbkgd(this->game, COLOR_PAIR(1));
	wrefresh(this->game);
}

