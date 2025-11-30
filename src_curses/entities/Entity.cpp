#include "entities/Entity.hpp"

Entity	init_enemy(unsigned int cols, unsigned int lines)
{
	return (Ennemy(cols, lines));
}


Entity	init_player(unsigned int cols, unsigned int lines)
{
	return (Player(cols, lines));
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

void	Entity::increment_entity_lines()
{
	Entity::lines -= 1;
}

void	Entity::decrement_entity_lines()
{
	Entity::lines += 1;
}

Projectile   Player::shoot(Player player)
{
	Projectile projectile(player.cols, player.lines, 1);
	return (projectile);
}	

Projectile	Ennemy::shoot(Ennemy ennemy)
{
	Projectile projectile(ennemy.cols, ennemy.lines, -1);
	return (projectile);
}
