#include "entities/Bullet.hpp"

using namespace std::chrono;

Bullet::Bullet(int x, int y, int max_x, int max_y, EDirection direction): 
	Entity(x, y, '-', 20, max_x, max_y, direction)
{
}

Bullet::~Bullet()
{
}

void	Bullet::update(float duration_time)
{
	Duration elapsed_duration = Duration(duration_time);
	(void)elapsed_duration;

	switch (this->direction)
	{
		case EDirection::LEFT:
			this->left_bullet();
			break;
		case EDirection::RIGHT:
			this->right_bullet();
			break;
		default:
			break;
	}
}

void	Bullet::render(WINDOW *window)
{
	if (this->updated)
	{
		mvwaddch(window, this->get_last_pos().y, this->get_last_pos().x, ' ');
		mvwaddch(window, this->get_pos().y, this->get_pos().x, this->get_ship());
	}
}

bool	Bullet::to_delete()
{
	return (this->get_pos().x == 0 || this->get_pos().x == this->max.x - 1);
}

void	Bullet::left_bullet()
{
	this->last_pos = this->pos;
	// if (this->pos.x > 1)
	// {
		this->updated = true;
		this->pos.x -= 1;
	// }
}

void	Bullet::right_bullet()
{
	this->last_pos = this->pos;
	// if (this->pos.x < this->max.x - 2)
	// {
		this->updated = true;
		this->pos.x += 1;
	// }
}