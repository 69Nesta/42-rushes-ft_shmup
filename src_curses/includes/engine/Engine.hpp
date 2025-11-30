#pragma once
#include "GameClock.hpp"
#include "InputHandler.hpp"
#include "screens/ScreenManager.hpp"
#include "screens/GameScreen.hpp"
#include "screens/LobbyScreen.hpp"
#include "screens/EndScreen.hpp"
#include "managers/GameStateManager.hpp"

class Engine
{
private:
	bool				is_running;
	GameClock			clock;
	InputHandler		input_handler;
	ScreenManager		screen_manager;
	GameStateManager	game_state_manager;
public:
	Engine(/* args */);
	~Engine();

	void 	run();
	void	process_input();
	void	update(float delta_time);
	void	render();
	void	initialize_screens();
};

