#include "engine/Engine.hpp"


Engine::Engine(): is_running(true), screen_manager(this->input_handler)
{
	srand(time(0));
	initscr();
	noecho();
	curs_set(0);
	timeout(0);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	this->input_handler.initialize();
	this->initialize_screens();
	this->run();
}

Engine::~Engine()
{
	this->input_handler.shutdown();
}

void Engine::run()
{
	while (is_running)
	{
		this->clock.set_start_frame();

		this->process_input();
		this->update(this->clock.get_delta_time());
		this->render();

		this->clock.set_end_frame();
	}
}

void	Engine::process_input()
{
	this->input_handler.process_event();
	this->screen_manager.handle_input();
}

void Engine::update(float delta_time)
{
	this->screen_manager.update(delta_time);
}

void Engine::render()
{
	this->screen_manager.render();
}

void	Engine::initialize_screens()
{
	auto	lobby_screen = std::make_shared<LobbyScreen>(this->screen_manager, this->game_state_manager);
	auto	game_screen = std::make_shared<GameScreen>(this->screen_manager, this->clock, this->game_state_manager);
	auto	end_screen = std::make_shared<EndScreen>(this->screen_manager, this->game_state_manager, this->is_running);
	this->screen_manager.register_screen(ScreenType::LOBBY, lobby_screen);
	this->screen_manager.register_screen(ScreenType::GAME, game_screen);
	this->screen_manager.register_screen(ScreenType::END, end_screen);

	this->screen_manager.change_screen(ScreenType::LOBBY);
}
