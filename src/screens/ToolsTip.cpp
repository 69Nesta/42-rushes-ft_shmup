#include "screens/ToolsTip.hpp"

ToolsTip::ToolsTip(WINDOW *window):
	window(window)
{
}

ToolsTip::~ToolsTip()
{
}


void	ToolsTip::render()
{
	std::string key = " [W] = Up       [S] = Down      [SPACE] = SHOOT !!!";
	mvwprintw(this->window, 1, 1, key.c_str());
	box(this->window, ACS_VLINE, ACS_HLINE);
}