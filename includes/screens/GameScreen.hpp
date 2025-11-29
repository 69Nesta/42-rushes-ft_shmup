#pragma once
#include "Screen.hpp"

class GameScreen : public Screen
{
private:
	WINDOW* hud;
	WINDOW* game;
	WINDOW* toolstip;

public:
	GameScreen(IScreenManager& screen_manager);
	~GameScreen();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
	void	handle_input(InputHandler& input) override;
};