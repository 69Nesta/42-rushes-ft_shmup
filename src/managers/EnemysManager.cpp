#include "managers/EnemysManager.hpp"

EnemysManager::EnemysManager(WINDOW *window) :
	window(window),
	enemys()
{
}

EnemysManager::~EnemysManager()
{
}

void EnemysManager::push_enemy(Enemy &enemy)
{
	this->enemys.push_back(enemy);
}

void EnemysManager::remove_enemy(size_t index)
{
	this->enemys.erase(this->enemys.begin() + index);
}

void EnemysManager::update(float delta_time)
{
	for (int i = static_cast<int>(this->enemys.size()) - 1; i >= 0; --i)
	{
		this->enemys[i].update(delta_time);
		if (this->enemys[i].to_delete())
		{
			mvwaddch(this->window, this->enemys[i].get_last_pos().y, this->enemys[i].get_last_pos().x, ' ');
			this->remove_enemy(i);
		}
	}
}

void EnemysManager::render()
{
	for (Enemy &enemy : this->enemys)
	{
		enemy.render(this->window);
	}
}

void EnemysManager::resize(int max_x, int max_y)
{
	for (Enemy &enemy : this->enemys)
	{
		enemy.resize(max_x, max_y);
	}
}
