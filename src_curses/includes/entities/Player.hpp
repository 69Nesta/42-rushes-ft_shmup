#pragma once
#include "entities/Entity.hpp"
#include "engine/InputHandler.hpp"

class Player : public Entity
{
private:
	static constexpr Duration MAX_FIRE_RATE = std::chrono::milliseconds(100);
    static constexpr Duration AMMO_REGENERATION_RATE = std::chrono::seconds(2);
    static constexpr int MAX_AMMO = 10;

	int			ammo;
	Duration	last_ammo;
	Duration	last_fire;

public:
	Player(int x, int y, int max_x, int max_y);
	~Player();

	void	update(float duration_time);
	int		get_ammo();
	void	shoot(/* bulletsManager */);
	void	handle_input(InputHandler& input);
	void	render(WINDOW *window);
};
