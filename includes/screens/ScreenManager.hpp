#pragma once
#include "Screen.hpp"
#include <stack>
#include <unordered_map>
#include <memory>

class ScreenManager
{
private:
	std::stack<std::shared_ptr<Screen>> screen_stack;
	std::unordered_map<ScreenType, std::shared_ptr<Screen>> registered_screens;
public:
	ScreenManager();
	~ScreenManager();

	void	register_screen(ScreenType type, std::shared_ptr<Screen> screen);
	void	push_screen(ScreenType type);
	void	pop_screen();
	void	change_screen(ScreenType type);

	void	update(float delta_time);
	void	render();
};

