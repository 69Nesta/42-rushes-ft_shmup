#pragma once
#include "entities/Enemy.hpp"
#include "ncurses.h"
#include <vector>

class EnemysManager
{
private:
	WINDOW	*window;
	
public:
	std::vector<Enemy>	enemys;

	EnemysManager(WINDOW *window);
	~EnemysManager();

	void	push_enemy(Enemy& enemy);
	void	remove_enemy(size_t index);
	void	update(float delta_time);
	void	render();

	void	resize(int max_x, int max_y);
};