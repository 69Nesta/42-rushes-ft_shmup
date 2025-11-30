#pragma once
#include "Screen.hpp"
#include "engine/GameClock.hpp"
#include "managers/GameStateManager.hpp"
#include "entities/Player.hpp"

class GameScreen : public Screen
{
private:
	WINDOW*	hud;
	WINDOW*	game;
	WINDOW*	toolstip;

	GameClock&			game_clock;
	GameStateManager& 	game_state_manager;
	
	Player				player;

public:
	GameScreen(IScreenManager& screen_manager, GameClock& game_clock, GameStateManager& game_state_manager);
	~GameScreen();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
	void	handle_input(InputHandler& input) override;
	void	resize();
};