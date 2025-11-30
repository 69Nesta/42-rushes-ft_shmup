#pragma once
#include "entities/Entity.hpp"
#include "managers/BulletsManager.hpp"

class Enemy : public Entity
{
private:
    static constexpr Duration MOVEMENT_SPEED = std::chrono::milliseconds(40);
	Duration	last_movment;
	BulletsManager* bullets_manager;

public:
	Enemy(int x, int y, int max_x, int max_y, BulletsManager& bullets_manager);
	~Enemy();

	// Enemy& operator=(const Enemy& other);

	void	update(float duration_time);
	void	shoot();
	bool	to_delete();
	void	render(WINDOW *window);

	Enemy(const Enemy&) = default;
	Enemy& operator=(const Enemy&) = default;
};
