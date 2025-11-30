#pragma once
#include "Screen.hpp"
#include "managers/GameStateManager.hpp"
#include <sstream>
#include <string>
#include <iostream>

class EndScreen: public Screen
{
private:
	WINDOW*				window;
	GameStateManager&	game_state;
	bool&				is_running;

public:
	EndScreen(IScreenManager& screen_manager, GameStateManager& game_state, bool& is_running);
	~EndScreen();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
	void	handle_input(InputHandler& input) override;
	void	resize();
};
