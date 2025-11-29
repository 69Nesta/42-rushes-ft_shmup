#pragma once
#include <ncurses.h>
#include "Window.hpp"

class Engine
{
private:
	WINDOW *window_game;
	WINDOW *window_ui;

public:
	Engine();
	~Engine();

	void init();
	void update();
};
 