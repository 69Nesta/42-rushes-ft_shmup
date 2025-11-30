#pragma once
#include "entities/Bullet.hpp"
#include "ncurses.h"

#include <vector>


class BulletsManager
{
private:
	WINDOW				*window;
	
public:
	std::vector<Bullet>	bullets;

	BulletsManager(WINDOW *window);
	~BulletsManager();

	void	push_bullet(Bullet& bullet);
	void	remove_bullet(size_t index);
	void	update(float delta_time);
	void	render();

	void	resize(int max_x, int max_y);
};