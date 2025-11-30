#include "managers/EnemysManager.hpp"
#include <iostream>
#include <algorithm>

EnemysManager::EnemysManager(WINDOW *window) : window(window)
{
}

EnemysManager::~EnemysManager()
{
}

void EnemysManager::push_enemy(Enemy &enemy)
{
	this->enemys.push_back(enemy);
}

void EnemysManager::pop_enemy()
{
	if (!this->enemys.empty())
	{
		this->enemys.pop_back();
	}
}

void EnemysManager::update(float delta_time)
{
	// for (auto &enemy : this->enemys)
	// {
	// 	enemy.update(delta_time);
	// }

	for (int i = static_cast<int>(this->enemys.size()) - 1; i >= 0; --i)
	{
		this->enemys[i].update(delta_time);
		if (this->enemys[i].to_delete())
		{
			mvwaddch(this->window, this->enemys[i].get_last_pos().y, this->enemys[i].get_last_pos().x, ' ');
			this->enemys.erase(this->enemys.begin() + i);
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

Enemy &EnemysManager::top()
{
	return this->enemys.back();
}

bool EnemysManager::empty() const
{
	return this->enemys.empty();
}

size_t EnemysManager::size() const
{
	return this->enemys.size();
}
