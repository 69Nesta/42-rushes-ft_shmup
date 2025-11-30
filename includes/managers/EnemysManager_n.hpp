#pragma once
#include "entities/Enemy.hpp"
#include "ncurses.h"
#include <vector>
// #include <deque>

class EnemysManager
{
private:
	WINDOW	*window;
	
public:
	// std::vector<Enemy>	enemys;
	// std::deque<Enemy> enemys;
	std::vector<Enemy>	enemys;

	EnemysManager(WINDOW *window);
	~EnemysManager();

	void	push_enemy(Enemy& enemy);
	void	pop_enemy(int index);
	void	update(float delta_time);
	void	render();

	void	resize(int max_x, int max_y);

	Enemy&	top();
	bool	empty() const;
	size_t	size() const;
};