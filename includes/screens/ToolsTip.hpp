#pragma once
#include <ncurses.h>
#include <string>


class ToolsTip
{
private:
	WINDOW *window;
public:
	ToolsTip(WINDOW *window);
	~ToolsTip();

	void	render();
};