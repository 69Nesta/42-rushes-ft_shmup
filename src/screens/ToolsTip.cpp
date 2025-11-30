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
	int			format;
	std::string	k_up = " [UP] = Up";
	std::string	k_down = "[DOWN] = Down";
	std::string k_left = "[LEFT] = left";
	std::string k_right = "[RIGHT] = right";
	std::string k_shoot = "[SPACE] = SHOOT !!!";
	format = COLS / 6;
	
	mvwprintw(this->window, 1, format - k_up.size(), "%s", k_up.c_str());
	mvwprintw(this->window, 1, (2 * format) - k_down.size(), "%s", k_down.c_str());
	mvwprintw(this->window, 1, (3 * format) - k_left.size(), "%s", k_left.c_str());
	mvwprintw(this->window, 1, (4 * format) - k_right.size(), "%s", k_right.c_str());
	mvwprintw(this->window, 1, (5 * format) - k_shoot.size() + 5, "%s", k_shoot.c_str());
	box(this->window, ACS_VLINE, ACS_HLINE);
	wbkgd(this->window, COLOR_PAIR(1));
}