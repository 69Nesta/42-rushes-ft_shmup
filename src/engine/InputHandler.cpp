#include "engine/InputHandler.hpp"

InputHandler::InputHandler(): 
	initialized(false),
	currentKey(0),
	previousKey(0)
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::initialize()
{
	if (!initialized)
	{
		initscr();
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
		nodelay(stdscr, TRUE);
		this->initialized = true;
	}
}

void InputHandler::shutdown()
{
	if (this->initialized)
	{
		endwin();
		this->initialized = false;
	}
}

void InputHandler::process_event()
{
	this->previousKey = this->currentKey;
	this->currentKey = getch();

	if (this->currentKey == ERR)
		this->currentKey = 0;
}

bool InputHandler::key_is_pressed(int key)
{
	return (this->currentKey == key);
}

int InputHandler::get_current_key()
{
	return this->currentKey;
}