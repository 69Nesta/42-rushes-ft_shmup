#include "entities/Entity.hpp"

Entity::Entity(int x, int y, char _ship, int health, int max_x, int max_y, EDirection direction): 
	ship(_ship),
	health(health),
	updated(true),
	direction(direction)
{
	this->pos.x = x;
	this->pos.y = y;
	this->last_pos.x = x;
	this->last_pos.y = y;
	this->max.x = max_x;
	this->max.y = max_y;
}

Entity::~Entity()
{
}

// Entity& Entity::operator=(const Entity& other)
// {
//     // if (this != &other)
//     // {
//     //     this->updated = other.updated;
//     //     this->direction = other.direction;
//     //     this->pos = other.pos;
//     //     this->last_pos = other.last_pos;
//     //     this->max = other.max;
        
//     //     this->health = other.health;
//     //     this->ship = other.ship;
//     // }
//     return *this;
// }

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
	this->updated = false;
}


/*
   x
  0______
y |
  |

*/

void	Entity::resize(int max_x, int max_y)
{
	this->updated = true;
	this->max.x = max_x;
	this->max.y = max_y;
}


void	Entity::up()
{
	this->last_pos = this->pos;
	if (this->pos.y > 1)
	{
		this->last_pos = this->pos;
		this->pos.y -= 1;
		this->updated = true;
	}
}

void	Entity::left()
{
	this->last_pos = this->pos;
	if (this->pos.x > 1)
	{
		this->updated = true;
		this->pos.x -= 1;
	}
}

void	Entity::right()
{
	this->last_pos = this->pos;
	if (this->pos.x < this->max.x - 2)
	{
		this->updated = true;
		this->pos.x += 1;
	}
}

void	Entity::down()
{
	this->last_pos = this->pos;
	if (this->pos.y < this->max.y - 2)
	{
		this->updated = true;
		this->pos.y += 1;
	}
}
