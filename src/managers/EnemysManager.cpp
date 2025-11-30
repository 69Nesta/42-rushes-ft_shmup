#include "managers/EnemysManager.hpp"
#include <iostream>
#include <algorithm>

EnemysManager::EnemysManager(WINDOW *window):
    window(window)
{
}

EnemysManager::~EnemysManager()
{
}

void	EnemysManager::push_enemy(Enemy& enemy)
{
    this->enemys.push_back(enemy);
}

void	EnemysManager::pop_enemy()
{
    if (!this->enemys.empty()) {
        this->enemys.pop_back();
    }
}

void	EnemysManager::update(float delta_time)
{
	for (auto& bullet : this->enemys) {
        bullet.update(delta_time);
    }
    
    // Ensuite supprimer celles qui doivent l'être
    // this->enemys.erase(
    //     std::remove_if(this->enemys.begin(), this->enemys.end(),
    //         [](Enemy& enemy) {
    //             return enemy.to_delete();
    //         }),
    //     this->enemys.end()
    // );

	for (int i = static_cast<int>(this->enemys.size()) - 1; i >= 0; --i) {
        this->enemys[i].update(delta_time);
        if (this->enemys[i].to_delete()) {
			mvwaddch(this->window, this->enemys[i].get_last_pos().y, this->enemys[i].get_last_pos().x, ' ');
            this->enemys.erase(this->enemys.begin() + i);
        }
    }
    // if (!this->enemys.empty()) {
    //     Enemy& last_enemy = this->enemys.back();
    //     last_enemy.update(delta_time);
        
    //     if (last_enemy.to_delete()) {
    //         this->pop_enemy();
    //     }
    // }
}

void EnemysManager::render()
{
    for (Enemy& enemy : this->enemys) {
        enemy.render(this->window);
    }
}

void	EnemysManager::resize(int max_x, int max_y)
{
    for (Enemy& enemy : this->enemys) {
        enemy.resize(max_x, max_y);
    }
}

Enemy&	EnemysManager::top() {
    return this->enemys.back();
}

bool	EnemysManager::empty() const {
    return this->enemys.empty();
}

size_t	EnemysManager::size() const {
    return this->enemys.size();
}