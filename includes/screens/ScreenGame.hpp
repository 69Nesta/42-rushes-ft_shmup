#pragma once
#include "Screen.hpp"

class ScreenGame : public Screen
{
private:
public:
	ScreenGame();
	~ScreenGame();

	void	initialize(void) override;
	void	update(float delta_time) override;
	void	render(void) override;
};