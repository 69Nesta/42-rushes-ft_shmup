#include "screens/ScreenGame.hpp"

ScreenGame::ScreenGame(): Screen(ScreenType::GAME)
{
}

ScreenGame::~ScreenGame()
{
}

void	ScreenGame::update(float delta_time)
{
	// moves entities
	// check collides
}

void	ScreenGame::render(void)
{
	// render player
	// render enemy
	// render bullets
}

void	ScreenGame::initialize(void)
{
	
}

