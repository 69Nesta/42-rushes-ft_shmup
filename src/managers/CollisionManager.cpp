#include "managers/CollisionManager.hpp"

CollisionManager::CollisionManager(BulletsManager &bullet_manager, EnemysManager &enemys_manager, Player &player):
	bullet_manager(bullet_manager),
	enemys_manager(enemys_manager),
	player(player)
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::update(WINDOW *window)
{
	for (int i = static_cast<int>(this->bullet_manager.bullets.size()) - 1; i >= 0; --i)
	{
		Point2 pos;

		pos = this->bullet_manager.bullets[i].get_pos();
		if (this->player.get_pos().x == pos.x && this->player.get_pos().y == pos.y)
		{
			mvwaddch(window, this->bullet_manager.bullets[i].get_last_pos().y, this->bullet_manager.bullets[i].get_last_pos().x, ' ');
			this->bullet_manager.remove_bullet(i);
			this->player.remove_health();
		} else
		{
			for (int i_e = static_cast<int>(this->enemys_manager.enemys.size()) - 1; i_e >= 0; --i_e) {
				if (pos.x == this->enemys_manager.enemys[i_e].get_pos().x && pos.y == this->enemys_manager.enemys[i_e].get_pos().y)
				{
					mvwaddch(window, this->enemys_manager.enemys[i_e].get_last_pos().y, this->enemys_manager.enemys[i_e].get_last_pos().x, ' ');
					this->enemys_manager.enemys.erase(this->enemys_manager.enemys.begin() + i_e);
					break;
				}
			}
		}
	}

	for (Enemy &enemy : this->enemys_manager.enemys)
	{
		if (this->player.get_pos().x == enemy.get_pos().x && this->player.get_pos().y == enemy.get_pos().y)
		{
			// next screen
		}
	}
}