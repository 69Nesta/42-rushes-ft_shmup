#include "engine/Engine.hpp"

Engine::Engine(): is_running(true)
{
	initscr();
	initialize_screens();
	this->run();
}

Engine::~Engine()
{
	
}

void Engine::run()
{
	while (is_running)
	{
		this->clock.set_start_frame();
		this->process_input();
		this->screen_manager.update(this->clock.get_delta_time());
		this->screen_manager.render();
	}
}

void	Engine::process_input()
{
	this->input_handler.process_event();
}

void Engine::update()
{

}

void	Engine::initialize_screens()
{
	auto	lobby_screen = std::make_shared<ScreenLobby>(this->game_state_manager);
	this->screen_manager.register_screen(ScreenType::LOBBY, lobby_screen);

	this->screen_manager.push_screen(ScreenType::LOBBY);
}
