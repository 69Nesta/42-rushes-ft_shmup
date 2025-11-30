#pragma once
#include <chrono>
#include <vector>

struct Point2 {
	int	x;
	int	y;
};

class Entity
{
protected:
	using Clock = std::chrono::steady_clock;
	using TimePoint = std::chrono::time_point<Clock>;
    using Duration = std::chrono::duration<float>;
	bool		updated;

private:

	Point2		pos;
	Point2		last_pos;
	Point2		max;
	int			health;
	char		ship;

public:
	Entity(int x, int y, char ship, int health, int max_x, int max_y);
	~Entity();

	char	get_ship();

	int		get_health();
	int		remove_health(int amount = 1);
	int		add_health(int amount = 1);

	Point2	get_pos();
	Point2	get_last_pos();
	void	pos_has_been_updated();

	void	resize(int max_x, int max_y);

	void	up();
	void	left();
	void	right();
	void	down();
};