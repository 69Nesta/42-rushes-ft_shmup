#pragma once
#include "Screen.hpp"
#include "managers/GameStateManager.hpp"

class LobbyScreen: public Screen
{
private:
	WINDOW* window;

public:
	LobbyScreen(IScreenManager& screen_manager, GameStateManager& game_state);
	~LobbyScreen();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
	void	handle_input(InputHandler& input) override;
	void	resize();
};
