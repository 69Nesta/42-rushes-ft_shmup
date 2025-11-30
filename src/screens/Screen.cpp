#include "screens/Screen.hpp"

Screen::Screen(IScreenManager& screen_manager, ScreenType type): screen_manager(screen_manager), status(ScreenStatus::PAUSED)
{
	this->type = type;
}

void	Screen::pause()
{
	this->status = ScreenStatus::PAUSED;
}

void	Screen::resume()
{
	this->status = ScreenStatus::ACTIVE;
}

ScreenStatus	Screen::get_status()
{
	return (this->status);
}

ScreenType	Screen::get_type()
{
	return (this->type);
}

bool	Screen::is_active()
{
	return (this->get_status() == ScreenStatus::ACTIVE);
}