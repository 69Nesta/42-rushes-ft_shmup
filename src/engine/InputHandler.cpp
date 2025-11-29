#include "engine/InputHandler.hpp"

InputHandler::InputHandler(): key(0)
{

}

InputHandler::~InputHandler()
{
}

void	InputHandler::process_event()
{
	this->key = getch();
}

int		InputHandler::get_current_key()
{
	return (this->key);
}