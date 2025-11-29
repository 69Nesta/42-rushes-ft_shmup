#pragma once
#include <ncurses.h>
#include <stdio.h>

class Window
{
private:
	WINDOW *frame;
public:
	Window(WINDOW*, int, int, int, int);
	~Window();
	WINDOW *getFrame();
};