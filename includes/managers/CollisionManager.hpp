#include "managers/BulletsManager.hpp"
#include "managers/EnemysManager.hpp"
#include "entities/Player.hpp"

class CollisionManager
{
private:
	BulletsManager&	bullet_manager;
	EnemysManager&	enemys_manager;
	Player&			player;
public:
	CollisionManager(BulletsManager& bullet_manager, EnemysManager& enemys_manager, Player& player);
	~CollisionManager();
	
	void	update(WINDOW *window);
};
