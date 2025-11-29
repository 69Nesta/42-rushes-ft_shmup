#pragma once
#include "Screen.hpp"
#include "managers/GameStateManager.hpp"

class ScreenLobby: public Screen
{
private:
	WINDOW* window;
public:
	ScreenLobby(GameStateManager& game_state);
	~ScreenLobby();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
};
