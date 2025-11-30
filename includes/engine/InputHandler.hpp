#pragma once
#include <ncurses.h>


class InputHandler
{
private:
	bool	initialized;
	int		currentKey;
    int		previousKey;
public:
	InputHandler();
	~InputHandler();
	void	process_event();
	bool	key_is_pressed(int key);
	int		get_current_key();
	void	initialize();
	void	shutdown();
};
