#pragma once
#include "classes/Window.hpp"


class GameScreen : public Window
{
private:
	Window	ui;
	Window	game;
public:
	GameScreen();
	~GameScreen();
};
