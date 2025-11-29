#include "screens/ScreenManager.hpp"


ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
}

void	ScreenManager::register_screen(ScreenType type, std::shared_ptr<Screen> screen)
{
	this->registered_screens[type] = screen;
	screen->initialize();
}

void	ScreenManager::push_screen(ScreenType type)
{
	auto screen = this->registered_screens.find(type);
	if (screen != this->registered_screens.end())
	{
		if (!this->screen_stack.empty())
			this->screen_stack.top()->pause();
		this->screen_stack.push(screen->second);
	}
}

void	ScreenManager::pop_screen()
{
	if (!this->screen_stack.empty())
	{
		this->screen_stack.top()->pause();
		this->screen_stack.pop();

		// Supperposed Screen (Pause)
		if (!this->screen_stack.empty())
		{
			this->screen_stack.top()->resume();
		}
	}
}

void	ScreenManager::change_screen(ScreenType type)
{
	auto screen = this->registered_screens.find(type);
	if (screen != this->registered_screens.end())
	{
		while (!this->screen_stack.empty())
		{
			this->screen_stack.top()->pause();
			this->screen_stack.pop();
		}
		this->screen_stack.push(screen->second);
		screen->second->resume();
	}
}

void	ScreenManager::update(float delta_time)
{
	if (!this->screen_stack.empty())
		this->screen_stack.top()->update(delta_time);
}

void	ScreenManager::render()
{
	if (!this->screen_stack.empty())
		this->screen_stack.top()->render();
}