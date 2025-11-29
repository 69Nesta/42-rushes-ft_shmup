#pragma once
#include "Screen.hpp"
#include "engine/InputHandler.hpp"

#include <stack>
#include <unordered_map>
#include <memory>

class ScreenManager: public IScreenManager
{
private:
	std::stack<std::shared_ptr<Screen>>						screen_stack;
	std::unordered_map<ScreenType, std::shared_ptr<Screen>>	registered_screens;
	
	InputHandler& 	input_handler;

public:
	ScreenManager(InputHandler& input_handler);
	~ScreenManager();

	void	register_screen(ScreenType type, std::shared_ptr<Screen> screen);
	void	push_screen(ScreenType type) override;
	void	pop_screen() override;
	void	change_screen(ScreenType type) override;

	void	update(float delta_time);
	void	render();
	void	handle_input();
};

