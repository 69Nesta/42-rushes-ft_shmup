#include "managers/BulletsManager.hpp"

BulletsManager::BulletsManager(WINDOW *window):
	window(window)
{
}

BulletsManager::~BulletsManager()
{
}

void	BulletsManager::push_bullet(Bullet& bullet)
{
	this->bullets.push_back(bullet);
}

void	BulletsManager::remove_bullet(size_t index)
{
	std::swap(this->bullets[index], this->bullets.back());
	// delete this->bullets.back()
    this->bullets.pop_back();
}

void	BulletsManager::update(float delta_time)
{
	for (int i = static_cast<int>(this->bullets.size()) - 1; i >= 0; --i)
    {
        this->bullets[i].update(delta_time);
        if (this->bullets[i].to_delete())
        {
			mvwaddch(this->window, this->bullets[i].get_last_pos().y, this->bullets[i].get_last_pos().x, ' ');
            this->remove_bullet(i);
        }
    }
}

void	BulletsManager::render()
{
	for(Bullet& bullet : this->bullets)
	{
		bullet.render(this->window);
	}
}

void	BulletsManager::resize(int max_x, int max_y)
{
	for(Bullet& bullet : this->bullets)
	{
		bullet.resize(max_x, max_y);
	}
}
