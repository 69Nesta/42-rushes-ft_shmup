#include "entities/Enemy.hpp"
#include <cstdlib>

using namespace std::chrono;

Enemy::Enemy(int x, int y, int max_x, int max_y, BulletsManager& bullets_manager): 
	Entity(x, y, '@', 1, max_x, max_y, EDirection::LEFT),
	last_movment(0),
	bullets_manager(&bullets_manager)
{
	
}

Enemy::~Enemy()
{
}

void	Enemy::update(float duration_time)
{
	Duration elapsed_duration = Duration(duration_time);

	this->last_movment += elapsed_duration;

	if (rand() % 1001 <= 30)
		this->shoot();
	if (this->last_movment >= this->MOVEMENT_SPEED)
	{
		this->last_movment = Duration(0);
		this->left();
	}
}

void	Enemy::shoot()
{
	if (this->get_pos().x > 2)
	{
		Bullet bullet(this->get_pos().x - 2, this->get_pos().y, this->max.x, this->max.y, this->direction);
		(*bullets_manager).push_bullet(bullet);
	}
}

void	Enemy::render(WINDOW *window)
{
	//  && this->max.x - 1 != this->get_pos().x && this->max.x - 1 != this->get_last_pos().x
	if (this->updated)
	{
		mvwaddch(window, this->get_last_pos().y, this->get_last_pos().x, ' ');
		mvwaddch(window, this->get_pos().y, this->get_pos().x, this->get_ship());
	}
}

bool	Enemy::to_delete()
{
	return (this->get_pos().x == 1);
}
