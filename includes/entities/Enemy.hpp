#pragma once
#include "entities/Entity_2.hpp"

class Player : public Entity
{
private:
	TimePoint	last_fire;
public:
	Player(int x, int y, int max_x, int max_y);
	~Player();

	void	shoot(/* bulletsManager */);
};
