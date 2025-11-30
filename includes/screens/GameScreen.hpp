#pragma once
#include "Screen.hpp"
#include "engine/GameClock.hpp"
#include "managers/GameStateManager.hpp"
#include "managers/BulletsManager.hpp"
#include "managers/EnemysManager.hpp"
#include "entities/Player.hpp"

#include "managers/CollisionManager.hpp"

#include "screens/ToolsTip.hpp"
#include "screens/Background.hpp"

#include <sstream>
#include <string>
#include <iostream>


class GameScreen : public Screen
{
protected:
	static const int	HUD_HEIGHT = 4;
	static const int	TOOLTIP_HEIGHT = 3;

private:
	WINDOW*	hud;
	WINDOW*	game;
	WINDOW*	toolstip;

	ToolsTip	_tools_tip;

	GameClock&			game_clock;
	GameStateManager& 	game_state_manager;
	
	BulletsManager		bullet_manager;
	EnemysManager		enemy_manager;

	Player				player;

	CollisionManager	collision_manager;

	Background			background;

public:
	GameScreen(IScreenManager& screen_manager, GameClock& game_clock, GameStateManager& game_state_manager);
	~GameScreen();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
	void	refresh_hud(void);
	void	handle_input(InputHandler& input) override;
	void	resize();
};