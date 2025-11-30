#include "entities/Player.hpp"

using namespace std::chrono;

Player::Player(int x, int y, int max_x, int max_y): 
	Entity(x, y, 20, '>', max_x, max_y),
	ammo(100),
	last_ammo(0),
	last_fire(0)
{
}

Player::~Player()
{
}

void	Player::update(float duration_time)
{
	Duration elapsed_duration = Duration(duration_time);
    
    this->last_ammo += elapsed_duration;
    this->last_fire += elapsed_duration;

    if (this->last_ammo >= this->MAX_FIRE_RATE)
    {
        this->last_ammo = Duration(0);
        this->ammo = std::min(this->ammo + 1, MAX_AMMO);
    }
}

void	Player::shoot(/* bulletsManager */)
{
	if (this->ammo > 0 && this->last_fire >= this->MAX_FIRE_RATE)
    {
        this->last_fire = Duration(0);
        this->ammo--;
        // logic
    }
}

int		Player::get_ammo()
{
	return (this->ammo);
}

void	Player::render(WINDOW *window)
{
	if (this->updated)
	{
		mvwaddch(window, this->get_last_pos().y, this->get_last_pos().x, ' ');
		mvwaddch(window, this->get_pos().y, this->get_pos().x, '>');
	}
}

void	Player::handle_input(InputHandler& input)
{
	switch (input.get_current_key())
	{
		case KEY_UP:
			this->up();
			break;
		case KEY_LEFT:
			this->left();
			break;
		case KEY_RIGHT:
			this->right();
			break;
		case KEY_DOWN:
			this->down();
			break;
		case ' ':
			this->shoot();
			break;
		default:
			break;
	}
}