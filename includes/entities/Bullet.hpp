#pragma once
#include "entities/Entity_2.hpp"
#include <ncurses.h>

class Bullet : public Entity
{
private:
	static constexpr Duration SPEED = std::chrono::milliseconds(10);

public:
	Bullet(int x, int y, int max_x, int max_y, EDirection direction);
	~Bullet();

	void	update(float duration_time);
	bool	to_delete();
	void	render(WINDOW *window);

	void	left_bullet();
	void	right_bullet();
};
