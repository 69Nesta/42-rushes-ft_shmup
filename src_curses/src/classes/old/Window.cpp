#include "classes/Window.hpp"
#include <ncurses.h>
#include <stdlib.h>

Window::Window(WINDOW *parent, int h, int w, int y, int x)
{
	this->frame = subwin(parent, h, w, y, x);
}

Window::~Window()
{
	if (this->frame)
	{
		free(this->frame);
		this->frame = NULL;
	}
}

WINDOW* Window::getFrame()
{
	return (this->frame);
}