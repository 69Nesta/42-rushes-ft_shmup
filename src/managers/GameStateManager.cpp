#include "managers/GameStateManager.hpp"

GameStateManager::GameStateManager():
	score(0),
	lives(1)
{
}

GameStateManager::~GameStateManager()
{
}

void	GameStateManager::rest()
{

}

int		GameStateManager::get_score()
{
	return (this->score);
}

void	GameStateManager::add_score(int value)
{
	this->score += value;
}

void	GameStateManager::loseLife()
{
	if (lives > 0)
		this->lives -= 1;
}
