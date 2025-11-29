#pragma once
#include "Screen.hpp"

class ScreenGame : public Screen
{
private:
	WINDOW* hud;
	WINDOW* game;
	WINDOW* toolstip;

public:
	ScreenGame();
	~ScreenGame();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
};