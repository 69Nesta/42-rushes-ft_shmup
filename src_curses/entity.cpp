#include "entity.hpp"
#include <vector>

namespace std;

//
//                          Entity vector list
//

Vector<Entity>  Entity::init_vec_entity(Entity entity)
{
    vector<Entity> v;

    v.push_back(entity);
    return (v);
}

void  Entity::clear_vec(vector<Entity> v)
{
    v.clear();
}

Entity	init_enemy(unsigned int cols, unsigned int lines)
{
	return (Ennemy(cols, lines));
}

Entity	init_player(unsigned int cols, unsigned int lines)
{
	return (Player(cols, lines));
}

//
//                  Entity check position && collision
//

bool    Entity::check_collision(Entity a, Entity b)
{
    if (a.get_cols == b.get_cols && a.get_lines == b.get_lines)
        return (TRUE);
    return (FALSE);
}

unsigned int	Entity::get_lines()
{
	return (Entity::lines);
}

unsigned int	Entity::get_cols()
{
	return (Entity::cols);
}

char	Entity::get_ship()
{
	return (Entity::ship);
}

//
//                      Entity Movement update
//

void	Entity::increment_entity_lines()
{
	Entity::lines -= 1;
}

void	Entity::decrement_entity_lines()
{
	Entity::lines += 1;
}

void    Entity::increment_entity_cols()
{
    Entity::cols += 1;
}

void    Entity::decrement_entity_cols()
{
    Entity::cols -= 1;
}

//
//                  Projectile Entity functions
//

Projectile (unsigned int cols, unsigned int lines, int direction) 
{
	this->cols = cols;
	this->lines = lines;
	this->direction = direction;
	this->ship = '-';
    return (Projectile);
}


Projectile   Player::shoot(Player player)
{
	Projectile projectile(player.cols + 1, player.lines, 1);

	return (projectile);
}

Projectile	Ennemy::shoot(Ennemy ennemy)
{
	Projectile projectile(ennemy.cols - 1, ennemy.lines, -1);
	return (projectile);
}

//
//                          Player   function
//

Player (unsigned int cols, unsigned int lines)
{
	this->cols = cols;
	this->lines = lines;
	this->ship = '>';
}

void    Player::player_get_hit(bool hit, gamestate::health health)
{
    if (hit == TRUE)
        health--;
}

//
//                      Ennemy function
//

Ennemy(unsigned int cols, unsigned int lines)
{
	this->cols = cols;
	this->lines = lines;
	this->ship = '<';
}

void    Ennemy::ennemy_get_hit(bool hit, gamestate::score score)
{
    if (hit == TRUE)
    {
        score += 100;
        ~Ennemy();
    }
}
