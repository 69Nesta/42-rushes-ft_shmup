#pragma once
#include <ncurses.h>


class InputHandler
{
private:
	int key;
public:
	InputHandler();
	~InputHandler();
	void	process_event();
	bool	is_key_pressed(int key);
	int		get_current_key();
};
