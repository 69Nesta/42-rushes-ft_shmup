#include "entities/Entity_2.hpp"

Entity::Entity(int x, int y, char ship, int health, int max_x, int max_y): ship(ship), health(health)
{
	this->pos.x = x;
	this->pos.y = y;
	this->last_pos.x = x;
	this->last_pos.y = y;
}

Entity::~Entity()
{
}

char	Entity::get_ship()
{
	return (this->ship);
}

int		Entity::get_health()
{
	return (this->health);
}

int		Entity::remove_health(int amount)
{
	if (this->health - amount >= 0)
		this->health -= amount;
	else if (health > 0)
		this->health = 0;
	return (this->health);
}
int		Entity::add_health(int amount)
{
	if (this->health >= 0)
		this->health += amount;
	return (this->health);
}

Point2	Entity::get_last_pos()
{
	return (this->last_pos);
}

Point2	Entity::get_pos()
{
	return (this->pos);
}

void	Entity::pos_has_been_updated()
{
	this->last_pos = this->pos;
}


/*
   x
  0______
y |
  |

*/

void	Entity::resize(int max_x, int max_y)
{
	this->max.x = max_x;
	this->max.y = max_y;
}


void	Entity::up()
{
	this->last_pos = this->pos;
	if (this->pos.y > 0)
		this->pos.y -= 1;
}

void	Entity::left()
{
	if (this->pos.x > 0)
		this->pos.x -= 1;
}

void	Entity::right()
{
	if (this->pos.x < this->max.x)
		this->pos.x += 1;
}

void	Entity::down()
{
	if (this->pos.y < this->max.y)
		this->pos.y += 1;
}
